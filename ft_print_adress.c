/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:29:48 by cchouina          #+#    #+#             */
/*   Updated: 2023/01/24 12:38:20 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	adress_len(uintptr_t adress)
{
	int	len;

	len = 0;
	while (adress != 0)
	{
		len++;
		adress = adress / 16;
	}
	return (len);
}

static void	ft_put_adress(uintptr_t adress)
{
	int	writabble;

	if (adress >= 16)
	{
		ft_put_adress(adress / 16);
		ft_put_adress(adress % 16);
	}
	else
	{
		if (adress <= 9)
		{
			writabble = adress + 48;
			write(1, &writabble, 1);
		}
		else
		{
			writabble = adress - 10 + 97;
			write(1, &writabble, 1);
		}
	}
}

int	ft_print_adress(unsigned long long adress)
{
	write(1, "0x", 2);
	if (adress == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		ft_put_adress(adress);
	return (adress_len(adress) + 2);
}
