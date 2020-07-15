#include "../ft_printf.h"
#include <stdio.h>

int main() {


    printf("\n-----------------------------\n");
    printf("\n--------conversion s---------\n");
    printf("\n-----------------------------\n");
    printf("1%s\n", "teste");
    	// printf("1%0s\n", "teste");
	printf("2%-s\n", "teste");
    	//printf("1%-0s\n", "teste");
	printf("3%4sG\n", "teste");
	printf("4%7sG\n", "teste");
	printf("5%8.0sG\n", "teste");
	printf("6%8.3sG\n", "teste");
	printf("7%-8.0sG\n", "teste");
	printf("8%-8.3sG\n", "teste");
	printf("9%-8.sG\n", "teste");
	printf("10%8sG\n", "teste");
	printf("11%4.5sG\n", "teste");
	printf("12%4.4sG\n", "teste");
	printf("13%4.7sG\n", "teste");
	printf("14%8.7sG\n", "teste");
	printf("15%-8.7sG\n", "teste");
	printf("16%-.7sG\n", "teste");
	printf("17%8.5sG\n", "teste");



    printf("------------18\n");

	ft_printf("1%s\n", "teste");
    	// ft_printf("1%0s\n", "teste");
	ft_printf("2%-s\n", "teste");
    	// ft_printf("1%-0s\n", "teste");
    ft_printf("3%4sG\n", "teste");
    ft_printf("4%7sG\n", "teste");
    ft_printf("5%8.0sG\n", "teste");
    ft_printf("6%8.3sG\n", "teste");
    ft_printf("7%-8.0sG\n", "teste");
    ft_printf("8%-8.3sG\n", "teste");
    ft_printf("9%-8.sG\n", "teste");
    ft_printf("10%8sG\n", "teste");
    ft_printf("11%4.5sG\n", "teste");
    ft_printf("12%4.4sG\n", "teste");
    ft_printf("13%4.7sG\n", "teste");
    ft_printf("14%8.7sG\n", "teste");
    ft_printf("15%-8.7sG\n", "teste");
    ft_printf("16%-.7sG\n", "teste");
    ft_printf("17%8.5sG\n", "teste");

    //numeros positivos

    	printf("teste%1.3dteste\n", 65432);
    	//printf("teste%01.3dteste\n", 65432);
        printf("teste%-1.3dteste\n", 65432);
        //printf("teste%0-1.3dteste\n", 65432);
        //printf("teste%-01.3dteste\n", 65432);
    	printf("7\n");

    	ft_printf("teste%1.3dteste\n", 65432);
    	//ft_printf("teste%01.3dteste\n", 65432);
    	ft_printf("teste%-1.3dteste\n", 65432);
    	//ft_printf("teste%0-1.3dteste\n", 65432);
    	//ft_printf("teste%-01.3dteste\n", 65432);
        ft_printf("\n---------------------------\n");

        printf("teste%3.1dteste\n", 65432);
        //printf("teste%03.1dteste\n", 65432);
        printf("teste%-3.1dteste\n", 65432);
        //printf("teste%0-3.1dteste\n", 65432);
        //printf("teste%-03.1dteste\n", 65432);
        printf("8\n");

    	ft_printf("teste%3.1dteste\n", 65432);
        //ft_printf("teste%03.1dteste\n", 65432);
        ft_printf("teste%-3.1dteste\n", 65432);
        //ft_printf("teste%0-3.1dteste\n", 65432);
        //ft_printf("teste%-03.1dteste\n", 65432);
        ft_printf("\n---------------------------\n");

        printf("teste%1.5dteste\n", 654);
        //printf("teste%01.5dteste\n", 654);
        printf("teste%-1.5dteste\n", 654);
        //printf("teste%0-1.5dteste\n", 654);
        //printf("teste%-01.5dteste\n", 654);
        printf("9\n");

    	ft_printf("teste%1.5dteste\n", 654);
        //ft_printf("teste%01.5dteste\n", 654);
        ft_printf("teste%-1.5dteste\n", 654);
        //ft_printf("teste%0-1.5dteste\n", 654);
        //ft_printf("teste%-01.5dteste\n", 654);
        ft_printf("\n---------------------------\n");

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
printf("|%4.15s|\n", "42");
ft_printf("|%4.15s|\n", "42");
//ft_printf("|%0*i|\n", -7, -54);
// printf("|%0*i|\n", -7, -54);
// ft_printf("|%0*i|\n", -7, -54);
// printf("|%-*.*s|-*.* -7, -3\n", -7, -3, "yolo");
// ft_printf("|%-*.*s|-*.* -7, -3\n", -7, -3, "yolo");
// printf("|%-*.*s|-*.* -7, -3\n",-7, -3, "teste");
// ft_printf("|%-*.*s|-*.* -7, -3\n",-7, -3, "teste");

  return 0;
}
