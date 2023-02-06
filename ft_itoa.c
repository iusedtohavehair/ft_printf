/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:12:13 by cchouina          #+#    #+#             */
/*   Updated: 2023/01/24 12:13:11 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_len(int n)
{
	int	minus;
	int	len;

	len = 0;
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	if (n <= 9)
		return (1 + minus);
	else
	{
		while (n >= 1)
		{
			n /= 10;
			len++;
		}
	}
	return (len + minus);
}

static char	*print_min(void)
{
	char	*str;
	int		index;
	int		n;

	n = 2147483647;
	str = ft_calloc(12, sizeof(char));
	if (!str)
		return (NULL);
	index = 10;
	while (index >= 1)
	{
		str[index--] = (n % 10) + 48;
		n /= 10;
	}
	str[0] = '-';
	str[10] = '8';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		minus;
	int		index;
	char	*str;

	minus = (n < 0);
	len = nbr_len(n) + 1;
	if (n == -2147483648)
		return (print_min());
	if (n < 0)
		n *= -1;
	index = len - 2;
	str = ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	while (index >= minus)
	{
		str[index--] = (n % 10) + 48;
		n /= 10;
	}
	if (minus)
		str[0] = '-';
	return (str);
}
