#include "../ft_printf.h"
#include <stdio.h>

int main() {
  printf("|%u|\n", -255);
  printf("|%-18u|\n", -255);
  printf("|%-18.14u|\n", -255);
  ft_printf("...1...\n");
  ft_printf("|%u|\n", -255);
  ft_printf("|%-18u|\n", -255);
  ft_printf("|%-18.14u|\n", -255);
  return 0;
}
