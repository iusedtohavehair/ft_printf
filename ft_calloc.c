/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:07:29 by cchouina          #+#    #+#             */
/*   Updated: 2023/01/24 12:13:15 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*malloc_array;

	malloc_array = malloc(count * size);
	if (!malloc_array)
		return (NULL);
	ft_bzero(malloc_array, count * size);
	return (malloc_array);
}
