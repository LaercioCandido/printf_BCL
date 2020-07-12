#include "../ft_printf.h"
#include <stdio.h>

int main() {
  int a = 10;
int *b = &a;
printf("%p\n",b);
printf("%X\n",b);
ft_printf("...1...\n");
ft_printf("%p\n",b);
ft_printf("%X\n",b);
ft_printf("...1...\n");
  char *p = "ab";
  printf("|%p|\n", &p);
  printf("|%-18p|\n", &p);
  printf("|%18p|\n", &p);
  //printf("|%018p|\n", &p);
  ft_printf("...1...\n");
  ft_printf("|%p|\n", &p);
  ft_printf("|%-18p|\n", &p);
  ft_printf("|%18p|\n", &p);
  //ft_printf("|%018p|\n", &p);

  return 0;
}
