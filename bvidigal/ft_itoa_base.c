int    digitcounter(int n)
{
    if (!(n / 16))
        return (1);
    else
        return (digitcounter(n / 16) + 1);
}

char    *ft_itoa_base(int n, char type)
{
    char    *hexnumber;
    int        len;
    char    *base


    base = type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
    len = digitcounter(n);
    if (!(hexnumber = malloc((len + 1) * sizeof(*hexnumber))))
        return (NULL);
    hexnumber[len] = '\0';
    while (len--)
    {
        hexnumber[len] = base[n % 16];
        n /= 16;
    }
    //tratar as flags
    //free(hexnumber) em algum lugar;
    return (hexnumber);
}

int ft_printf_xX(t_flags *flags, va_list args)
{
    int        number;
    char    *hexnumber;
    int        count;
    char    base;

    base = flags->type == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
    count = 0;
    if (flags->star == 1)
        flags->width = va_arg(args, int);
    else if (flags->star == 2)
        flags->point = va_arg(args, int);
    else if (flags->star == 3)
    {
        flags->width = va_arg(args, int);
        flags->point = va_arg(args, int);
    }
    number = va_arg(args, int);
    hexnumber = ft_conversion(number, base);
    while(hexnumber)
        count += ft_putchar(*hexnumber++);
    return(count);
}
