/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:23:25 by tyamauch          #+#    #+#             */
/*   Updated: 2023/01/01 03:42:02 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static void	ft_putpointer(unsigned long long pointer)
{
	unsigned long long	pointer_div;
	int					pointer_mod;
	char				hexsa;

	pointer_div = pointer / 16;
	pointer_mod = (int)(pointer % 16);
	if (pointer_div)
		ft_putpointer(pointer_div);
	else
		ft_putstr_fd("0x", 1);
	if (pointer_mod < 10)
		ft_putnbr_fd(pointer_mod, 1);
	else
	{
		hexsa = 'a' + pointer_mod - 10;
		ft_putchar_fd(hexsa, 1);
	}
}

static void	ft_puthexsa(unsigned int hexsa_num, char c)
{
	unsigned int	hexsa_div;
	int				hexsa_mod;
	char			hexsa;

	hexsa_div = hexsa_num / 16;
	hexsa_mod = (int)(hexsa_num % 16);
	if (hexsa_div)
		ft_puthexsa(hexsa_div, c);
	if (hexsa_mod < 10)
		ft_putnbr_fd(hexsa_mod, 1);
	else
	{
		if (c == 'x')
			hexsa = 'a' + hexsa_mod - 10;
		else
			hexsa = 'A' + hexsa_mod - 10;
		ft_putchar_fd(hexsa, 1);
	}
}

static void	ft_unsigned_putnbr_fd(unsigned int un, int fd)
{
	char	c;

	if (un >= 10)
	{
		ft_unsigned_putnbr_fd(un / 10, fd);
		un %= 10;
		c = un + '0';
		ft_putchar_fd(c, fd);
	}
	else
		ft_putchar_fd(un + '0', fd);
}

static void	format_check(const char *s, va_list ap)
{
	/* if (!*s) */
	/* 	return (1); */
	while (*s != '%')
	{
		write(1, s, 1);
		s++;
	}
	/* format_check(s,ap); */
	/* printf("may be %c", *s); */
	/* write(1, s, 1); */
	/* while (*s++) */
	/* { */
		/* if (*s != '%') */
		/* { */
		/* 	write(1, s, 1); */
		/* } */
		if (*s == 'c')
		{
			ft_putchar_fd(va_arg(ap, int), 1);
			/* printf("%s","\n"); */
		}
		else if (*s == 's')
		{
			ft_putstr_fd(va_arg(ap, char *), 1);
			/* printf("%s","\n"); */
		}
		else if (*s == 'p')
		{
			ft_putpointer(va_arg(ap, unsigned long long));
			/* printf("%s","\n"); */
		}
		else if (*s == 'd' || *s == 'i')
		{
			/* write(1, s, 1); */
			ft_putnbr_fd(va_arg(ap, int), 1);
			/* s++; */
			/* printf("%s","\n"); */
		}
		else if (*s == 'u')
		{
			ft_unsigned_putnbr_fd(va_arg(ap, unsigned int), 1);
			/* printf("%s","\n"); */
		}
		else if (*s == 'x' || *s == 'X')
		{
			ft_puthexsa(va_arg(ap, unsigned int), *s);
			/* printf("%s","\n"); */
		}
		else if (*s == '%')
		{
			ft_putchar_fd(*s, 1);
			/* printf("%s","\n"); */
		}
		/* s = s+1; */
	/* } */
	/* return (s); */
}

int	ft_printf(const char *s, ...)
{
	const char	*format;
	va_list		ap;

	va_start(ap, s);
	format = s;
	/* %hogeをごとに出力する関数 */
	if (!*s)
		return (0);
	while (*s || ft_strchr(s,'%'))
	{
		if(*s == '%')
			format_check(format + 1, ap);
		/* { */
			/* write(1, s, 1); */
			/* write(1, s, 1); */
			/* s = s + 1; */
		/* } */
		/* else */
		/* 	write(1, s, 1); */
		/* s++; */
	/* } */
	va_end(ap);
	return (1);
}

/* #include <stdio.h> */
/* #include "libft/libft.h" */
/* #include "libftprintf.h" */
/* #include <limits.h> */
int	main(void)
{
	int x=42;
	char *str = "Tokyo";
/* int len1 = ft_printf("%c %s %d %p %i %u",
			'c',"42Tokyo",123456789,&p,10,-1); */
/* int len1 = ft_printf(" %c",'0'); */
/* int len2 = printf(" %c",'0'); */
printf("%d %s \n",x,str);
ft_printf("%d %s \n",x,str);
/* printf("what is: %u\n",UINT_MAX); */
/* printf("what is: %lu\n",ULONG_MAX); */
/* int len3 = ft_printf("%d\n", 123456789); */
/* printf(" %c", '0'); */
/* printf("%d\n", len1); */
/* printf("%d\n", len2); */
/* printf("%d\n", len3); */

}
