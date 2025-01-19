#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

extern "C" void app_main();

constexpr gpio_num_t LED_PIN = GPIO_NUM_4;

void app_main()
{
  // Setup
  gpio_config_t io_conf;
  io_conf.mode = GPIO_MODE_OUTPUT;
  io_conf.pin_bit_mask = 1ULL << LED_PIN;
  io_conf.intr_type = GPIO_INTR_DISABLE;
  io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
  io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
  gpio_config(&io_conf);

  // Loop
  while (true)
  {
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(50 / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}