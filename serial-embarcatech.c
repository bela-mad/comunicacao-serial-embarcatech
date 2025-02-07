#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"
#include "inc/font.h"
#include "inc/button.h"
#include "inc/led_rgb.h"
#include "inc/matrix_led.h"
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C

void gpio_irq_handler(uint gpio, uint32_t events);

uint32_t last_time_a = 0;
uint32_t last_time_b = 0;
ssd1306_t ssd;
bool cor = true;

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
  gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
  gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

  // I2C Initialisation. Using it at 400Khz.
  i2c_init(I2C_PORT, 400 * 1000);

  gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);                    // Set the GPIO pin function to I2C
  gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);                    // Set the GPIO pin function to I2C
  gpio_pull_up(I2C_SDA);                                        // Pull up the data line
  gpio_pull_up(I2C_SCL);                                        // Pull up the clock line                                                // Inicializa a estrutura do display
  ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT); // Inicializa o display
  ssd1306_config(&ssd);                                         // Configura o display
  ssd1306_send_data(&ssd);                                      // Envia os dados para o display

  // Limpa o display. O display inicia com todos os pixels apagados.
  ssd1306_fill(&ssd, false);
  ssd1306_send_data(&ssd);

  while (true) {
    // cor = !cor;
    // // Atualiza o conteúdo do display com animações
    // ssd1306_fill(&ssd, !cor); // Limpa o display

    // // ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
    // // ssd1306_draw_string(&ssd, "abcdefghijkl", 8, 10); // Desenha uma string
    // // ssd1306_draw_string(&ssd, "mnopqrstuvwxyz", 20, 30); // Desenha uma string
    // // ssd1306_draw_string(&ssd, "0123456789", 15, 48); // Desenha uma string

    // ssd1306_send_data(&ssd); // Atualiza o display

    // sleep_ms(1000);

    // colocar :, ? e ! no ssd1306.c
    if (stdio_usb_connected()) { // Certifica-se de que o USB está conectado
      char c;
      if (scanf("%c", &c) == 1) { // Lê caractere da entrada padrão
        printf("Caractere: '%c'\n", c);
        ssd1306_draw_string(&ssd, "Caractere: ", 8, 10);
        ssd1306_draw_char(&ssd, c, 90, 10);

        
      }

      if(c >= '0') {
        
      }
    }
    sleep_ms(40);
  }
  return 0;
}

// Função callback que verifica o tempo para que o debouncing ocorra, atualiza esse tempo, verifica o botão que
// foi pressionado, atualiza o valor de cont para exibir o número correto na tela e imprime o valor na matriz
void gpio_irq_handler(uint gpio, uint32_t events)
{
  uint32_t current_time = to_us_since_boot(get_absolute_time());

  // Debounce para o botão A
  if (gpio == BUTTON_A_PIN && (current_time - last_time_a > 200000))
  { // 200 ms
    last_time_a = current_time;
    // verifica se o LED azul está ligado. Se sim, ele é desligado para não misturar as cores
    if (gpio_get(BLUE_LED_PIN))
    {
      gpio_put(BLUE_LED_PIN, 0);
    }
    gpio_put(GREEN_LED_PIN, !gpio_get(GREEN_LED_PIN)); // Alterna o estado do LED verde
    if (gpio_get(GREEN_LED_PIN))
    {
      printf("LED VERDE ON\n");
      ssd1306_draw_string(&ssd, "LED VERDE ON   ", 15, 48);
    }
    else if (!gpio_get(GREEN_LED_PIN))
    {
      printf("LED VERDE OFF\n");
      ssd1306_draw_string(&ssd, "LED VERDE OFF ", 15, 48);
    }
  }

  // Debounce para o botão B
  if (gpio == BUTTON_B_PIN && (current_time - last_time_b > 200000))
  { // 200 ms
    last_time_b = current_time;
    // verifica se o LED verde está ligado. Se sim, ele é desligado para não misturar as cores
    if (gpio_get(GREEN_LED_PIN))
    {
      gpio_put(GREEN_LED_PIN, 0);
    }
    gpio_put(BLUE_LED_PIN, !gpio_get(BLUE_LED_PIN)); // Alterna o estado do LED azul
    if (gpio_get(BLUE_LED_PIN))
    {
      printf("LED AZUL ON\n");
      ssd1306_draw_string(&ssd, "LED AZUL ON   ", 15, 48);
    }
    else if (!gpio_get(BLUE_LED_PIN))
    {
      printf("LED AZUL OFF\n");
      ssd1306_draw_string(&ssd, "LED AZUL OFF  ", 15, 48);
    }
  }

  // atualiza o display
  ssd1306_send_data(&ssd);
}