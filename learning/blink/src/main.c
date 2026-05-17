#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

static const struct gpio_dt_spec led =
    GPIO_DT_SPEC_GET(DT_NODELABEL(blinking_led), gpios);

int main() {
  if (!device_is_ready(led.port)) {
    return -1;
  }

  int ret;
  ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

  if (ret != 0) {
    return -1;
  }

  while (true) {
    ret = gpio_pin_toggle_dt(&led);
    if (ret != 0) {
      return -1;
    }
    k_msleep(1000);
  }
}
