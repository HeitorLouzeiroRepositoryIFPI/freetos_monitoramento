#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "semphr.h"

const uint led_blue = 12;
const uint led_red = 13;

const uint button_pin = 5;

SemaphoreHandle_t semaforoBotao; // semáforo para acionar tarefa 2
SemaphoreHandle_t semaforoLed; // semáforo para acionar tarefa 3

void tarefaLeituraBotao(void *parametro) {
    int estadoBotaoAnterior = 1;

    for (;;) {
        int estadoBotaoAtual = gpio_get(button_pin);
        
        printf("estado botao: %d\n",estadoBotaoAtual);

        if (estadoBotaoAtual == 0 && estadoBotaoAnterior == 1) { 
            xSemaphoreGive(semaforoBotao);
        }

        estadoBotaoAnterior = estadoBotaoAtual;
        vTaskDelay(pdMS_TO_TICKS(50)); 
    }
}

void tarefaProcessamentoBotao(void *parametro) {
    for (;;) {
        if (xSemaphoreTake(semaforoBotao, portMAX_DELAY)) {
            xSemaphoreGive(semaforoLed);
        }
    }
}

void tarefaControleLed(void *parametro) {
    for (;;) {
        if (xSemaphoreTake(semaforoLed, portMAX_DELAY)) {
            gpio_put(led_blue, 1);
            gpio_put(led_red,1);
            vTaskDelay(pdMS_TO_TICKS(1000));
            gpio_put(led_blue, 0);
            gpio_put(led_red , 0);
        }
    }
}

void setupLedsAndButton() {
    gpio_init(led_blue);
    gpio_set_dir(led_blue, GPIO_OUT);
    gpio_put(led_blue, 0);
    
    gpio_init(led_red);
    gpio_set_dir(led_red, GPIO_OUT);
    gpio_put(led_red, 0);

    gpio_init(button_pin);
    gpio_set_dir(button_pin, GPIO_IN);
    gpio_pull_up(button_pin);
}

void main() {
    stdio_init_all();
    setupLedsAndButton();

    semaforoBotao = xSemaphoreCreateBinary();
    semaforoLed = xSemaphoreCreateBinary();

    if (semaforoBotao == NULL || semaforoLed == NULL) {
        printf("Erro ao criar seaforos!\n");
        while (1);
    }

    xTaskCreate(tarefaLeituraBotao, "Leitura Botão", 1024, NULL, 1, NULL);
    xTaskCreate(tarefaProcessamentoBotao, "Processamento Botão", 1024, NULL, 1, NULL);
    xTaskCreate(tarefaControleLed, "Controle LED", 1024, NULL, 1, NULL);

    vTaskStartScheduler();

    for (;;);
}
