#include "../ft_printf.h"
#include <stdio.h>

int main() {
  int a = 10;
int *p;

*p = 10;
/*
printf("%p\n",b);
//printf("%X\n",b);
ft_printf("...1...\n");
ft_printf("%p\n",b);
ft_printf("%X\n",b);
ft_printf("...1...\n");
*/
  //char *p = "ab";
  printf("|%p|\n", p);
  printf("|%2.40p|\n", &p);
  printf("|%40.2p|\n", &p);
  printf("|%040.2p|\n", &p);
  printf("|%-40.2p|\n", &p);
  printf("|%40.20p|\n", &p);
  printf("|%-40.20p|\n", &p);
  ft_printf("...1...\n");
  ft_printf("|%p|\n", p);
  ft_printf("|%2.40p|\n", &p);
  ft_printf("|%40.2p|\n", &p);
  ft_printf("|%040.2p|\n", &p);
  ft_printf("|%-40.2p|\n", &p);
  ft_printf("|%40.20p|\n", &p);
  ft_printf("|%-40.20p|\n", &p);

  ft_printf("\n\n");

  printf("|%p|\n", 0);
  printf("|%2.40p|\n", 0);
  printf("|%40.2p|\n", 0);
  printf("|%040.2p|\n", 0);
  printf("|%-40.2p|\n", 0);
  printf("|%40.20p|\n", 0);
  printf("|%-40.20p|\n", 0);
  ft_printf("...2...\n");
  ft_printf("|%p|\n", 0);
  ft_printf("|%2.40p|\n", 0);
  ft_printf("|%40.2p|\n", 0);
  ft_printf("|%040.2p|\n", 0);
  ft_printf("|%-40.2p|\n", 0);
  ft_printf("|%40.20p|\n", 0);
  ft_printf("|%-40.20p|\n", 0);



  //ft_printf("|%018p|\n", &p);

  return 0;
}
