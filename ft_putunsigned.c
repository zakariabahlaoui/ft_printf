#include "ft_printf.h"

int ft_num_len(unsigned int num)
{
    int len;

    len = 0;
    while (num != 0)
    {
        len++;
        num = num / 10;
    }
    return len;
}

char *ft_uitoa(unsigned int n)
{
    char *num;
    int len;

    len = ft_num_len(n);
    num = (char *)malloc(sizeof(char) * (len + 1));
    if (!num)
        return 0;
    num[len] = '\0';
    while (n != 0)
    {
        num[len - 1] = n % 10 + 48;
        n = n / 10;
        len--;
    }
    return (num);
}

int ft_putunsigned(unsigned int n)
{
    int len;
    char *num;

    len = 0;
    if (n == 0)
        len += ft_putchar('0');
    else
    {
        num = ft_uitoa(n);
        len += ft_putstr(num);
        free(num);
    }
    return len;
}
