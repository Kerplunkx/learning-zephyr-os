#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

#define LED_PIN 2

static const struct device *gpio_ct_dev = DEVICE_DT_GET(DT_NODELABEL(gpio0));

int main() {
  if (!device_is_ready(gpio_ct_dev)) {
    return -1;
  }

  int ret;
  ret = gpio_pin_configure(gpio_ct_dev, LED_PIN, GPIO_OUTPUT_ACTIVE);

  if (ret != 0) {
    return -1;
  }

  while (true) {
    ret = gpio_pin_set_raw(gpio_ct_dev, LED_PIN, 1);
    if (ret != 0) {
      return -1;
    }
    k_msleep(1000);

    ret = gpio_pin_set_raw(gpio_ct_dev, LED_PIN, 0);
    if (ret != 0) {
      return -1;
    }
    k_msleep(1000);
  }
}
