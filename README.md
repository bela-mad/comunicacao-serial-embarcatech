<samp>
<h1 align="center"> Interfaces de Comunicação Serial com RP2040: UART, SPI e I2C :desktop_computer: </h1>
  
<h2 align="center"> Sobre :pencil: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Repositório com o objetivo de consolidar os conceitos sobre o uso de interfaces de comunicação serial no RP2040 e explorar as funcionalidades da placa de desenvolvimento BitDogLab, como parte de uma tarefa desenvolvida na Unidade 4 do Capítulo 6 da EmbarcaTech, residência de Sistemas Embarcados. Essa tarefa foi desenvolvida pela residente Isabela Madureira.

<h3> Descrição da tarefa </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; A tarefa consiste em utilizar os seguintes componentes:

  1. Matriz 5x5 de LEDs (endereçáveis) WS2812, conectada à GPIO 7;
  2. LED RGB, com os pinos conectados às GPIOs (11, 12 e 13);
  3. Botão A conectado à GPIO 5;
  4. Botão B conectado à GPIO 6;
  5. Display SSD1306 conectado via I2C (GPIO 14 e GPIO15).

 &emsp;&emsp;&emsp;&emsp; O programa deve possuir as seguintes funcionalidades:

<p align="justify">  1. <b> Modificação da Biblioteca font.h: </b> adicionar caracteres minúsculos à biblioteca font.h. Use sua criatividade para criar os novos caracteres; </p>
<p align="justify">  2. <b> Entrada de caracteres via PC: </b> utilize o Serial Monitor do VS Code para digitar os caracteres. Cada caractere digitado no Serial Monitor deve ser exibido no display SSD1306 (Observação: Apenas um caractere será enviado de cada vez, não é necessário suportar o envio de strings completas). Quando um número entre 0 e 9 for digitado, um símbolo correspondente ao número deve ser exibido, também, na matriz 5x5 WS2812; </p>
<p align="justify">  3. <b> Interação com o Botão A: </b> pressionar o botão A deve alternar o estado do LED RGB Verde (ligado/desligado) e a operação deve ser registrada de duas formas: uma mensagem informativa sobre o estado do LED deve ser exibida no display SSD1306 e um texto descritivo sobre a operação deve ser enviado ao Serial Monitor; </p>
<p align="justify">  4. <b> Interação com o Botão B: </b> pressionar o botão B deve alternar o estado do LED RGB Azul (ligado/desligado) e a operação deve ser registrada de duas formas: uma mensagem informativa sobre o estado do LED deve ser exibida no display SSD1306 e um texto descritivo sobre a operação deve ser enviado ao Serial Monitor. </p>

<h3> Estruturação dos Arquivos </h3>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; O projeto é composto pelos arquivos comuns a um projeto Pico W, além de uma pasta chamada 'inc', que possui 5 arquivos na extensão .c, que são: animation.c (que organiza as funções relacionadas à animação), button.c (que organiza as funções relacionadas aos botões), led_rgb.c (que organiza as funções relacionadas ao LED RGB), matriz_led.c (que organiza as funções relacionadas à matriz de LEDs) e sdd1306.c (que organiza as funções relacionadas ao display), 6 arquivos na extensão .h, que são: animaton.h, button.h, font.h, led_rgb.h, matriz_led.h e ssd1306.h (em que ambos possuem as importações e o cabeçalho das funções) e um arquivo ws2818b.pio, e os arquivos serial-embarcatech.c (que gerencia todo o projeto) e READ.ME (descrição do projeto).

<h3></h3>
<h2 align="center"> Vídeo :video_camera: </h2>
<p align="justify"> &emsp;&emsp;&emsp;&emsp; Aqui está o link para o vídeo com uma prática de simulação associada a esta tarefa: </p>
<p align="center"> https://youtube.com/shorts/eecuZJhzQQk?feature=share </p>

<h2></h2>
<h2 align="center"> Como utilizar :computer_mouse: </h2>

<p align="justify"> &emsp;&emsp;&emsp;&emsp; Para utilizar o programa, o usuário deve:

- Clonar o repositório em uma pasta separada para recebê-lo;
- Abrir o projeto no VS Code, importando-o pela extensão Raspberry Pi Pico;
- Conectar a placa BitDogLab em modo BOOTSEL;
- Compilar e executar o projeto;
- Configurar e acionar o PuTTY;
- Testar as funcionalidades descritas acima.

</samp>
