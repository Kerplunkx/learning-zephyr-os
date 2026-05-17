#include <zephyr/kernel.h>


int main() {
  printf("Hello world\n");
  while (true) {
    k_msleep(1000);
  }
}
