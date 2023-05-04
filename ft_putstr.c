#include "ft_printf.h"

int ft_putstr(const char *str)
{
    int len;

    if (!str)
    {
        write(1, "(null)", 6);
        return 6;
    }

    len = ft_strlen(str);
    write(1, str, len);
    return len;
}
