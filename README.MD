# FreeRTOS - Sistema de Monitoramento com Raspberry Pi Pico

<!-- PROJECT SHIELDS -->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<div align="center">
  <h3 align="center">Sistema de Monitoramento FreeRTOS para Raspberry Pi Pico</h3>
  <p align="center">
    Um projeto utilizando o Raspberry Pi Pico com FreeRTOS para demonstrar o uso de tarefas concorrentes e semáforos.
    <br/>
    <a href="https://github.com/HeitorLouzeiroRepositoryIFPI/freetos_monitoramento/issues">Reportar Bug</a>
    ·
    <a href="https://github.com/HeitorLouzeiroRepositoryIFPI/freetos_monitoramento/issues">Solicitar Funcionalidade</a>
  </p>
</div>

## Índice
1. [Sobre o Projeto](#sobre-o-projeto)
   - [Desenvolvido Com](#desenvolvido-com)
2. [Funcionalidades](#funcionalidades)
3. [Primeiros Passos](#primeiros-passos)
   - [Pré-requisitos](#pré-requisitos)
   - [Instalação](#instalação)
4. [Uso](#uso)
5. [Roteiro](#roteiro)
6. [Contribuindo](#contribuindo)
7. [Licença](#licença)
8. [Contato](#contato)

## Sobre o Projeto
Este projeto demonstra a utilização do FreeRTOS com Raspberry Pi Pico, implementando um sistema de monitoramento com três tarefas concorrentes sincronizadas por semáforos. O sistema monitora o acionamento de um botão e controla LEDs como resposta.

### Desenvolvido Com
- [Raspberry Pi Pico C/C++ SDK](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html)
- [FreeRTOS](https://www.freertos.org/)
- [CMake](https://cmake.org/)

## Funcionalidades
- 🔘 Monitoramento de botão em tempo real
- 🔄 Sistema de tarefas concorrentes
- 🚥 Sincronização entre tarefas usando semáforos
- 💡 Controle de LEDs como resposta a eventos
- 🧠 Gerenciamento eficiente de recursos com RTOS

## Primeiros Passos

### Pré-requisitos
- Raspberry Pi Pico
- 2 LEDs (vermelho e azul)
- 1 Botão
- Resistores pull-up/pull-down conforme necessário
- [Raspberry Pi Pico SDK](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html)
- [FreeRTOS Kernel](https://www.freertos.org/a00104.html)
- CMake
- Ferramentas de compilação (GCC)

### Instalação
1. Clone o repositório:
   ```sh
   git clone https://github.com/HeitorLouzeiroRepositoryIFPI/freetos_monitoramento.git
   ```
2. Navegue até o diretório do projeto:
   ```sh
   cd freertos_monitoramento
   ```
3. Crie e entre no diretório de build:
   ```sh
   mkdir build && cd build
   ```
4. Gere os arquivos de build com CMake:
   ```sh
   cmake ..
   ```
5. Compile o projeto:
   ```sh
   make
   ```
6. Transfira o arquivo `.uf2` compilado para o Raspberry Pi Pico.

## Uso
O sistema funciona da seguinte forma:

1. **Tarefa 1** - Monitora continuamente o estado do botão conectado ao pino 5.
2. **Tarefa 2** - Processa o acionamento do botão quando notificado pela Tarefa 1 via semáforo.
3. **Tarefa 3** - Controla os LEDs quando ativada pela Tarefa 2 via semáforo.

Quando o botão é pressionado:
- Os LEDs azul (pino 12) e vermelho (pino 13) acendem simultaneamente.
- Os LEDs permanecem acesos por 1 segundo.
- Os LEDs se apagam automaticamente.

## Roteiro
- [x] Implementação básica das tarefas FreeRTOS
- [x] Sincronização com semáforos
- [x] Controle de LEDs com GPIO
- [x] Debouncing do botão
- [ ] Interface de usuário melhorada
- [ ] Suporte para múltiplos botões e LEDs
- [ ] Comunicação serial com computador host

## Contribuindo
Contribuições são o que tornam a comunidade open source um lugar incrível para aprender, inspirar e criar. Qualquer contribuição será muito apreciada.

1. Faça um Fork do projeto.
2. Crie sua Feature Branch:
   ```sh
   git checkout -b feature/RecursoIncrivel
   ```
3. Faça commit das suas alterações:
   ```sh
   git commit -m 'Adicionando um Recurso Incrível'
   ```
4. Faça Push para a Branch:
   ```sh
   git push origin feature/RecursoIncrivel
   ```
5. Abra um Pull Request.

## Licença
Distribuído sob a licença MIT. Veja [LICENSE](LICENSE) para mais informações.

## Contato
<div align='center'>
  <a href="https://www.instagram.com/heitorlouzeiro/" target="_blank">
    <img src="https://img.shields.io/badge/-Instagram-%23E4405F?style=for-the-badge&logo=instagram&logoColor=white" target="_blank">
  </a>
  <a href="mailto:heitorlouzeirodev@gmail.com">
    <img src="https://img.shields.io/badge/-Gmail-%23333?style=for-the-badge&logo=gmail&logoColor=white" target="_blank">
  </a>
  <a href="https://www.linkedin.com/in/heitor-louzeiro/" target="_blank">
    <img src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank">
  </a>
</div>

📌 **Link do Projeto:** [GitHub - FreeRTOS Monitoramento](https://github.com/HeitorLouzeiroRepositoryIFPI/freetos_monitoramento)
