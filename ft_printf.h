/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:43:21 by tyamauch          #+#    #+#             */
/*   Updated: 2023/01/26 12:49:34 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	my_putchar_fd(char c, int fd);
int	my_putstr_fd(char *s, int fd);
int	my_putnbr_fd(int n, int fd);
#endif
