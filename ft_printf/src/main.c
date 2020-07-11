#include "../ft_printf.h"
#include <stdio.h>

int main() {
  printf("|%x|\n", 255);
  printf("|%10x|\n", 255);
  printf("|%010x|\n", 255);
  printf("...1...");
  ft_printf("|%x|\n", 255);
  ft_printf("|%10x|\n", 255);
  ft_printf("|%010x|\n", 255);
  return 0;
}
