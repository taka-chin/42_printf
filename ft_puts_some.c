/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_some.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:13:53 by tyamauch          #+#    #+#             */
/*   Updated: 2023/01/22 19:42:55 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_putchar_fd(char c, int fd)
{
	int	count;

	count = 0;
	count += write(fd, &c, 1);
	return (count);
}

int	my_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += write(fd, "(null)", 6);
		return (count);
	}
	while (*s)
	{
		count += write(fd, s, 1);
		s++;
	}
	return (count);
}

int	my_putnbr_fd(int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n == INT_MIN)
	{
		count += my_putstr_fd("-2147483648", fd);
		return (count);
	}
	if (n < 0)
	{
		n = -n;
		count += my_putchar_fd('-', fd);
	}
	if (n >= 10)
	{
		count += my_putnbr_fd(n / 10, fd);
		n %= 10;
		c = n + '0';
		count += my_putchar_fd(c, fd);
	}
	else
		count += my_putchar_fd(n + '0', fd);
	return (count);
}
