/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decto_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:29:05 by cchouina          #+#    #+#             */
/*   Updated: 2023/01/24 12:38:06 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	min_or_maj(int mode)
{
	if (mode == 'x' || mode == 'p')
		return (87);
	return (55);
}

static unsigned long long	ft_decto_hex_len(uintptr_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_decto_hex(uintptr_t nb, int mode)
{
	int	caps;
	int	printable;

	caps = min_or_maj(mode);
	if (nb <= 9)
	{
		printable = nb + 48;
		write(1, &printable, 1);
	}
	else if (nb < 16)
	{
		printable = nb + caps;
		write(1, &printable, 1);
	}
	else
	{
		ft_decto_hex(nb / 16, mode);
		ft_decto_hex(nb % 16, mode);
	}
	return (ft_decto_hex_len(nb));
}
