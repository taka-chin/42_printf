/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:05:25 by tyamauch          #+#    #+#             */
/*   Updated: 2023/01/26 12:53:55 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putpointer(unsigned long long pointer, int count)
{
	unsigned long long	pointer_div;
	int					pointer_mod;
	char				hexsa;

	pointer_div = pointer / 16;
	pointer_mod = (int)(pointer % 16);
	if (pointer_div)
		count += ft_putpointer(pointer_div, count);
	else
		count += my_putstr_fd("0x", 1);
	if (pointer_mod < 10)
		count += my_putnbr_fd(pointer_mod, 1);
	else
	{
		hexsa = 'a' + pointer_mod - 10;
		count += my_putchar_fd(hexsa, 1);
	}
	return (count);
}

static int	ft_puthexsa(unsigned int hexsa_num, char c)
{
	unsigned int	hexsa_div;
	int				hexsa_mod;
	char			hexsa;
	int				count;

	count = 0;
	hexsa_div = hexsa_num / 16;
	hexsa_mod = (int)(hexsa_num % 16);
	if (hexsa_div)
		count += ft_puthexsa(hexsa_div, c);
	if (hexsa_mod < 10)
		count += my_putnbr_fd(hexsa_mod, 1);
	else
	{
		if (c == 'x')
			hexsa = 'a' + hexsa_mod - 10;
		else
			hexsa = 'A' + hexsa_mod - 10;
		count += my_putchar_fd(hexsa, 1);
	}
	return (count);
}

static int	ft_unsigned_putnbr_fd(unsigned int un, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (un >= 10)
	{
		count += ft_unsigned_putnbr_fd(un / 10, fd);
		un %= 10;
		c = un + '0';
		count += my_putchar_fd(c, fd);
	}
	else
		count += my_putchar_fd(un + '0', fd);
	return (count);
}

static int	format_check(const char *s, va_list ap)
{
	int	count;

	count = 0;
	if (!*s)
		return (0);
	if (*s == 'c')
		count += my_putchar_fd(va_arg(ap, int), 1);
	else if (*s == 's')
		count += my_putstr_fd(va_arg(ap, char *), 1);
	else if (*s == 'p')
		count += ft_putpointer(va_arg(ap, unsigned long long), count);
	else if (*s == 'd' || *s == 'i')
		count += my_putnbr_fd(va_arg(ap, int), 1);
	else if (*s == 'u')
		count += ft_unsigned_putnbr_fd(va_arg(ap, unsigned int), 1);
	else if (*s == 'x' || *s == 'X')
		count += ft_puthexsa(va_arg(ap, unsigned int), *s);
	else if (*s == '%')
		count += my_putchar_fd(*s, 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	const char	*format;
	va_list		ap;
	int			count;

	count = 0;
	va_start(ap, s);
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s != '%')
			count += write(1, s, 1);
		else
		{
			s++;
			format = s;
			count += format_check(format, ap);
		}
		s++;
	}
	va_end(ap);
	return (count);
}

/* #include <stdio.h> */
/* #include "ft_printf.h" */
/* int main(void) */
/* { */
/* 	int return1 = ft_printf(" %s\n","42tokyo"); */
/* 	printf("%d\n",return1); */
/* 	int return2 = printf(" %s\n","42tokyo"); */
/* 	printf("%d\n",return2); */
/* } */
