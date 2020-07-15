#include "../ft_printf.h"
#include <stdio.h>

int main() {

/*
int a = 10;
int *p;

*p = 10;

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
*/
/*
printf("|%%| -> |%|\n");
printf("|%2%| -> | %|\n");
printf("|%5%| -> |    %|\n");
printf("|%05%| -> |0000%|\n");
printf("|%-5%| -> |%    |\n");
printf("|%5.2%| -> |    %|\n");
printf("|%05.2%| -> |0000%|\n");
printf("|%-5.2%| -> |%    |\n");
printf("|%5.7%| -> |    %|\n");
printf("|%05.7%| -> |0000%|\n");
printf("|%-5.7%| -> |%    |\n");
ft_printf("...3...\n");
*/
/*
ft_printf("|%%|\n");
ft_printf("|%2%|\n");
ft_printf("|%5%|\n");
ft_printf("|%05%|\n");
ft_printf("|%-5%|\n");
ft_printf("|%5.2%|\n");
ft_printf("|%05.2%|\n");
ft_printf("|%-5.2%|\n");
ft_printf("|%5.7%|\n");
ft_printf("|%05.7%|\n");
ft_printf("|%-5.7%|\n");

ft_printf("%x\n", 4294967295u);
ft_printf("%%d 0000042 == |%d|\n", 0000042);
ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
ft_printf("%%-5d -42 == |%-5d|\n", -42);
ft_printf("%x\n", 4294967295u);
*/
printf("|%0*i|\n", -7, -54);
ft_printf("|%0*i|\n", -7, -54);
ft_printf("|%-*.*s|\n", -7, -3, "yolo");
ft_printf("|%*.*s|\n", 7, -3, "yolo");
//printf("|%*.*s|\n", 7, -3, "yolo");
ft_printf("|%-*s|\n", -32, "abc");
ft_printf("|%*s|\n", -32, "abc");
ft_printf("|%*.*i|\n", -14, -3, 94827);
ft_printf("|%0*i|\n", -7, -54);



  return 0;
}
