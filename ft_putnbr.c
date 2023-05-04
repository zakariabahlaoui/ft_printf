#include "ft_printf.h"

static void ft_putnbr_fd_recursive(unsigned int n)
{
    if (n > 9)
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}

void ft_putnbr2(int n)
{
    if (n >= 0)
        return ft_putnbr_fd_recursive(n);

    ft_putchar('-');
    ft_putnbr_fd_recursive(n * -1);
}
int ft_putnbr(int n)
{
    int nb;
    unsigned int i;

    nb = n;
    i = 1;
    if (n < 0 && n != -2147483648)
    {
        nb = -n;
        i++;
    }
    while (nb > 9)
    {
        nb = nb / 10;
        i++;
    }
    ft_putnbr2(n);
    if (n == -2147483648)
        return (11);
    return (i);
}

// int ft_putnbr_recursive(int n)
// {
//     int len = 0;
//     if (n > 9)
//         ft_putnbr(n / 10);
//     len += ft_putchar((n % 10) + '0');
//     return len;
// }

// int ft_putnbr(long int n)
// {
//     int len = 0;
//     if (n >= 0)
//         return len += ft_putnbr_recursive(n);

//     len += ft_putchar('-');
//     len += ft_putnbr_recursive(n * -1);
//     return len;
// }

// int ft_putnbr(long int nb)
// {
//     int len;
//     len = 0;
//     if (nb < 0)
//     {
//         nb = nb * -1;
//         ft_putchar('-');
//     }
//     if (nb >= 10)
//     {
//         len += ft_putnbr(nb / 10);
//         len += ft_putnbr(nb % 10);
//     }
//     else
//         len += ft_putchar(nb + '0');
//     return len;
// }
// int ft_power(int n)
// {
//     int r;
//     r = 1;
//     while (n >= 10 || n <= -10)
//     {
//         n = n / 10;
//         r = r * 10;
//     }

//     return r;
// }

// int ft_putnbr(int n)
// {
//     int r;
//     int power = ft_power(n);
//     int len = 0;
//     if (n == 0)
//     {
//         len += ft_putchar('0');
//     }
//     else
//     {
//         if (n < 0)
//         {
//             len += ft_putchar('-');
//             while (n < 0)
//             {
//                 r = n / power;
//                 len += ft_putchar(r * -1 + '0');
//                 n = n - (r * power);
//                 power = power / 10;
//             }
//         }
//         else if (n > 0)
//         {
//             while (n > 0)
//             {
//                 len += ft_putchar((n / power) + '0');
//                 n = n - ((n / power) * power);
//                 power = power / 10;
//             }
//         }
//     }
//     return len;
// }
