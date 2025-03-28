#include "pico/stdlib.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "semphr.h"

const uint led_azul = 12;
const uint led_vermelho = 13;

const uint pino_botao = 5;

SemaphoreHandle_t semaforoBotaoPressionado; // semáforo para acionar tarefa de processamento do botão
SemaphoreHandle_t semaforoAcionarLed; // semáforo para acionar tarefa de controle do LED

void tarefaLeituraBotao(void *parametro) {
    int estadoAnteriorBotao = 1;

    for (;;) {
        int estadoAtualBotao = gpio_get(pino_botao);
        
        printf("Estado do botao: %d\n", estadoAtualBotao);

        if (estadoAtualBotao == 0 && estadoAnteriorBotao == 1) { 
            xSemaphoreGive(semaforoBotaoPressionado);
        }

        estadoAnteriorBotao = estadoAtualBotao;
        vTaskDelay(pdMS_TO_TICKS(50)); 
    }
}

void tarefaProcessamentoBotao(void *parametro) {
    for (;;) {
        if (xSemaphoreTake(semaforoBotaoPressionado, portMAX_DELAY)) {
            xSemaphoreGive(semaforoAcionarLed);
        }
    }
}

void tarefaControleLed(void *parametro) {
    for (;;) {
        if (xSemaphoreTake(semaforoAcionarLed, portMAX_DELAY)) {
            gpio_put(led_azul, 1);
            gpio_put(led_vermelho, 1);
            vTaskDelay(pdMS_TO_TICKS(1000));
            gpio_put(led_azul, 0);
            gpio_put(led_vermelho, 0);
        }
    }
}

void configurarLedsEBotao() {
    gpio_init(led_azul);
    gpio_set_dir(led_azul, GPIO_OUT);
    gpio_put(led_azul, 0);
    
    gpio_init(led_vermelho);
    gpio_set_dir(led_vermelho, GPIO_OUT);
    gpio_put(led_vermelho, 0);

    gpio_init(pino_botao);
    gpio_set_dir(pino_botao, GPIO_IN);
    gpio_pull_up(pino_botao);
}

void main() {
    stdio_init_all();
    configurarLedsEBotao();

    semaforoBotaoPressionado = xSemaphoreCreateBinary();
    semaforoAcionarLed = xSemaphoreCreateBinary();

    if (semaforoBotaoPressionado == NULL || semaforoAcionarLed == NULL) {
        printf("Erro ao criar semaforos!\n");
        while (1);
    }

    xTaskCreate(tarefaLeituraBotao, "Leitura Botao", 1024, NULL, 1, NULL);
    xTaskCreate(tarefaProcessamentoBotao, "Processamento Botao", 1024, NULL, 1, NULL);
    xTaskCreate(tarefaControleLed, "Controle LED", 1024, NULL, 1, NULL);

    vTaskStartScheduler();

    for (;;);
}
