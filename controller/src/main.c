#include "zephyr/dt-bindings/input/input-event-codes.h"
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/input/input.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

static void button_input_cb(struct input_event *evt, void *user_data) {
  if (evt->sync == 0) {
    return;
  }
  if (evt->value) {
    if (evt->code == INPUT_KEY_0) {
      LOG_INF("BUTTON A PRESSED");
    } else if (evt->code == INPUT_KEY_1) {
      LOG_INF("BUTTON B PRESSED");
    }
  }
}

INPUT_CALLBACK_DEFINE(DEVICE_DT_GET(DT_PATH(buttons)), button_input_cb, NULL);

int main() {
  static const struct device *input_dev = DEVICE_DT_GET(DT_PATH(buttons));
  if (!device_is_ready(input_dev)) {
    LOG_ERR_DEVICE_NOT_READY(input_dev);
    return -1;
  }
  return 0;
}
