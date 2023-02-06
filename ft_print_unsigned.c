/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:30:21 by cchouina          #+#    #+#             */
/*   Updated: 2023/01/24 11:33:14 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_unsigned(unsigned int num)
{
	int		num_len;
	char	*new_nb;

	num_len = ft_unsigned_num_len(num);
	new_nb = malloc(sizeof(char) * (num_len + 1));
	if (!new_nb)
		return (0);
	new_nb[num_len] = '\0';
	while (num != 0)
	{
		num_len--;
		new_nb[num_len] = num % 10 + 48;
		num /= 10;
	}
	return (new_nb);
}

int	ft_print_unsigned(unsigned int num)
{
	int		len;
	char	*new_nb;

	len = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		new_nb = ft_itoa_unsigned(num);
		len += ft_putstr(new_nb);
		free(new_nb);
	}
	return (len);
}
