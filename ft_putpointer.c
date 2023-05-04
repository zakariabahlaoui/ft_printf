#include "ft_printf.h"

int ft_putpointer(unsigned long long nbr)
{
    char *str = "0123456789abcdef";
    char buffer[20];
    int i;
    int len;

    if (nbr == 0)
        return ft_putstr("(nil)");

    len = ft_putstr("0x");
    i = 0;
    while (nbr)
    {
        buffer[i] = str[nbr % 16];
        nbr /= 16;
        i++;
    }

    i--;
    while (i >= 0)
    {
        len += ft_putchar(buffer[i]);
        i--;
    }

    return len;
}

// int chek(char *base)
// {
//     int i;
//     int z;

//     i = 0;
//     z = 0;
//     if (base[0] == '\0')
//         return (0);
//     while (base[i])
//     {
//         if (base[i] == '+' || base[i] == '-')
//             return (0);

//         z = i + 1;
//         while (base[z])
//         {
//             if (base[i] == base[z])
//                 return (0);
//             z++;
//         }
//         i++;
//     }
//     return (1);
// }
// unsigned int ft_ab(int n)
// {
//     if (n < 0)
//         return n * -1;
//     else
//         return n;
// }

// int ft_putpointer(int nbr)
// {
//     int i;
//     int nb;
//     int r;
//     int size;
//     char buffer[8];
//     char *base = "0123456789abcsef";
//     int len;

//     len = 0;

//     if (nbr == 0)
//         len += ft_putchar('0');

//     if (chek(base))
//     {
//         if (nbr < 0)
//             len += ft_putchar('-');
//         nb = ft_ab(nbr);
//         size = 0;
//         while (base[size])
//             size++;
//         i = 0;
//         while (nb != 0)
//         {
//             r = nb % size;
//             nb = nb / size;
//             // if(r < 0)
//             //     r *= -1;
//             buffer[i] = base[r];
//             i++;
//         }
//         len += ft_putstr("0x");
//         i--;
//         while (i >= 0)
//         {
//             len += ft_putchar(buffer[i]);
//             i--;
//         }
//     }
//     return len;
// }
