#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_printf(const char *s, ...);
int ft_putchar(char c);
int ft_putstr(const char *str);
int ft_putnbr(int n);
// int ft_print_hex( int nbr);
int ft_print_hex(unsigned int nbr, const char c);
int ft_putpointer(unsigned long long nbr);
int ft_putunsigned(unsigned int n);
int ft_strlen(const char *str);

#endif