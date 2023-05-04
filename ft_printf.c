#include "ft_printf.h"

static int fprint(char c, va_list arg)
{
    int len;
    len = 0;

    if (c == 'c')
        len += ft_putchar(va_arg(arg, int));
    else if (c == 's')
        len += ft_putstr(va_arg(arg, char *));
    else if (c == 'd' || c == 'i')
        len = ft_putnbr(va_arg(arg, int));
    else if (c == 'x' || c == 'X')
        len += ft_print_hex(va_arg(arg, unsigned int), c);
    else if (c == 'p')
        len += ft_putpointer(va_arg(arg, long));
    else if (c == 'u')
        len += ft_putunsigned(va_arg(arg, unsigned int));
    else if (c == '%')
        len += ft_putchar('%');

    // printf("|%d|\n", len);
    return len;
}

int ft_printf(const char *s, ...)
{
    int i;
    int len;
    va_list arg;

    va_start(arg, s);

    len = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            len += fprint(s[i], arg);
        }
        else
            len += ft_putchar(s[i]);
        i++;
    }

    va_end(arg);
    return len;
}

// int i = 0;
//     if (c == 'c')
//     {
//         ft_putchar(va_arg(arg, int));
//         i++;
//     }
//     else if (c == 's')
//     {
//         ft_putstr(va_arg(arg, char *));
//         i++;
//     }
//     else if (c == 'd' || c == 'i')
//     {
//         ft_putnbr(va_arg(arg, int));
//         i++;
//     }
//     else if (c == 'x')
//     {
//         ft_putnbr_base(va_arg(arg, int));
//         i++;
//     }
//     else if (c == 'p')
//     {
//         ft_putpointer(va_arg(arg, int));
//         i++;
//     }
//     else if (c == 'u')
//     {
//         ft_putunsigned(va_arg(arg, int));
//         i++;
//     }

//     else if (c == '%')
//     {
//         ft_putchar('%');
//         i++;
//     }
//     return i;