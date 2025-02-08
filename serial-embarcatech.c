#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "../inc/animation.h"
#include "inc/button.h"
#include "inc/font.h"
#include "inc/led_rgb.h"
#include "inc/matrix_led.h"
#include "inc/ssd1306.h"
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C

// Cabeçalho da função de callback dos botões
void button_irq_handler(uint gpio, uint32_t events);

// Declaração de variáveis
uint8_t num = 0;
absolute_time_t debounce;
uint32_t last_time = 0;
ssd1306_t ssd;

int main() {

  stdio_init_all();

  // Inicialização e configuração dos componentes a serem utilizados
  led_init(RED_LED_PIN);
  led_init(GREEN_LED_PIN);
  led_init(BLUE_LED_PIN);
  button_init(BUTTON_A_PIN);
  button_init(BUTTON_B_PIN);
  matrix_init(LED_MATRIZ_PIN);

  // Configuração das interrupções nos botões A e B
  gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &button_irq_handler);
  gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &button_irq_handler);

  // Inicialização do I2C, usando-o em 400KHz
  i2c_init(I2C_PORT, 400 * 1000);

  gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);                    // set the GPIO pin function to I2C
  gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);                    // set the GPIO pin function to I2C
  gpio_pull_up(I2C_SDA);                                        // pull up the data line
  gpio_pull_up(I2C_SCL);                                        // pull up the clock line   
  ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // inicializa o display
  ssd1306_config(&ssd);                                         // configura o display
  ssd1306_send_data(&ssd);                                      // envia os dados para o display

  ssd1306_fill(&ssd, false);                                    // limpa o display, ele é iniciado com todos os pixels apagados
  ssd1306_send_data(&ssd);                                      // envia os dados para o display

  // inicializa o debounce
  debounce = delayed_by_ms(get_absolute_time(), 200);

  while (true) {

    if (stdio_usb_connected()) {
      char c;
      scanf("%c", &c);
      printf("Caractere: '%c'\n", c);

      // atualiza o tempo para impedir a ação do botão durante 100ms
      debounce = delayed_by_ms(get_absolute_time(), 100);

      ssd1306_draw_string(&ssd, "Caractere: ", 8, 10);
      ssd1306_draw_char(&ssd, c, 90, 10);
      ssd1306_send_data(&ssd);

      if (c >= '0' && c <= '9') {
        num = c - '0';                         // converte o caractere para o tipo uint8_t
        matrix_draw_number(numeros_low, num);  // imprime o número correspondente na matriz de LEDs
      }
    }
  }
  sleep_ms(40);
}

// Função callback que verifica se o tempo para que o debouncing ocorra foi alcançado, muda o estado 
// do LED, verifica se o outro LED está ligado e imprime as mensagens no monitor serial e no display
void button_irq_handler(uint gpio, uint32_t events) {
  if (time_reached(debounce)) {

    // Debounce para o botão A
    if (gpio == BUTTON_A_PIN) { 
      // verifica se o LED azul está ligado. Se sim, ele é desligado para não misturar as cores
      if (gpio_get(BLUE_LED_PIN)) {
        gpio_put(BLUE_LED_PIN, 0);
      }
      gpio_put(GREEN_LED_PIN, !gpio_get(GREEN_LED_PIN)); // alterna o estado do LED verde

      // exibe mensagem de acordo com o estado do led
      if (gpio_get(GREEN_LED_PIN)) {
        printf("LED VERDE ON\n");
        ssd1306_draw_string(&ssd, "LED VERDE ON!  ", 15, 48);
      }
      else if (!gpio_get(GREEN_LED_PIN)) {
        printf("LED VERDE OFF\n");
        ssd1306_draw_string(&ssd, "LED VERDE OFF! ", 15, 48);
      }
    }

    // Debounce para o botão B
    if (gpio == BUTTON_B_PIN) { 
      // verifica se o LED verde está ligado. Se sim, ele é desligado para não misturar as cores
      if (gpio_get(GREEN_LED_PIN)) {
        gpio_put(GREEN_LED_PIN, 0);
      }
      gpio_put(BLUE_LED_PIN, !gpio_get(BLUE_LED_PIN)); // alterna o estado do LED azul

      // exibe mensagem de acordo com o estado do led
      if (gpio_get(BLUE_LED_PIN)) {
        printf("LED AZUL ON\n");
        ssd1306_draw_string(&ssd, "LED AZUL ON!  ", 15, 48);
      }
      else if (!gpio_get(BLUE_LED_PIN)) {
        printf("LED AZUL OFF\n");
        ssd1306_draw_string(&ssd, "LED AZUL OFF!  ", 15, 48);
      }
    }
    ssd1306_send_data(&ssd);                              // atualiza o display
    debounce = delayed_by_ms(get_absolute_time(), 200);   // atualiza o debounce após a ação
  }
}