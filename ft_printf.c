/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:33:21 by cchouina          #+#    #+#             */
/*   Updated: 2023/01/24 11:36:04 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr_with_null(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	check_percent(char c, va_list args)
{
	char				*char_nb;
	unsigned long long	len;
	char				ch;

	len = 0;
	if (c == 'd' || c == 'i')
	{
		char_nb = ft_itoa(va_arg(args, int));
		len += ft_putstr_with_null(char_nb);
		free(char_nb);
	}
	if (c == 'c')
	{
		ch = va_arg(args, int);
		len += write(1, &ch, 1);
	}
	else if (c == 's')
		len += ft_putstr_with_null(va_arg(args, char *));
	else if (c == 'u')
		len += ft_print_unsigned(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		len += ft_decto_hex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		len += ft_print_adress(va_arg(args, unsigned long long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] != '%')
			len += write(1, &str[i], 1);
		else if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				len += write(1, &str[i], 1);
			else
				len += check_percent(str[i + 1], args);
			++i;
		}
	}
	va_end(args);
	return (len);
}
