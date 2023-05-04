#include "ft_printf.h"

// int ft_print_hex(long int nbr)
// {
//     char *str = "0123456789abcdef";
//     char buffer[20];
//     int i;
//     int len;

//     len = 0;
//     if (nbr == 0)
//         len += ft_putchar('0');
//     if (nbr < 0)
//     {
//         len += ft_putchar('-');
//         nbr *= -1;
//     }

//     i = 0;
//     while (nbr)
//     {
//         buffer[i] = str[nbr % 16];
//         nbr /= 16;
//         i++;
//     }

//     i--;
//     while (i >= 0)
//     {
//         len += ft_putchar(buffer[i]);
//         i--;
//     }

//     return len;
// }

// int ft_hex_len(int num)
// {
//     int len;

//     len = 0;
//     while (num != 0)
//     {
//         len++;
//         num = num / 16;
//     }
//     return len;
// }

// int ft_print_hex(int nbr)
// {
//     int i;
//     int nb;
//     int r;
//     int size;
//     char buffer[8];
//     char *base = "0123456789abcsef";
//     int len;

//     len = 0;
//     len = ft_hex_len(nbr);
//     if (nbr == 0)
//         ft_putchar('0');

//     if (nbr < 0)
//         ft_putchar('-');
//     // nb = ft_abs(nbr);
//     size = 0;
//     while (base[size])
//         size++;
//     i = 0;
//     while (nb != 0)
//     {
//         r = nb % size;
//         nb = nb / size;
//         if (r < 0)
//             r *= -1;
//         buffer[i] = base[r];
//         i++;
//     }
//     i--;
//     while (i >= 0)
//     {
//         ft_putchar(buffer[i]);
//         i--;
//     }

//     return len;
// }
#include <limits.h>

int ft_hex_len(unsigned int nbr)
{
    int len;

    len = 0;
    while (nbr != 0)
    {
        len++;
        nbr = nbr / 16;
    }
    return (len);
}

void ft_put_hex(unsigned int nbr, const char c)
{
    if (nbr >= 16)
    {
        ft_put_hex(nbr / 16, c);
        ft_put_hex(nbr % 16, c);
    }
    else
    {
        if (nbr <= 9)
            ft_putchar((nbr + '0'));
        else
        {
            if (c == 'x')
                ft_putchar(nbr - 10 + 'a');
            if (c == 'X')
                ft_putchar(nbr - 10 + 'A');
        }
    }
}

int ft_print_hex(unsigned int nbr, const char c)
{
    if (nbr == 0)
        return ft_putchar('0');
    else
        ft_put_hex(nbr, c);
    return (ft_hex_len(nbr));
}

// int main()
// {
//     ft_print_hex(-11, 'x');
//     printf("\n%x\n", -11);
// }