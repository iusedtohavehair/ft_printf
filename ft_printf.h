/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchouina <cchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:36:30 by cchouina          #+#    #+#             */
/*   Updated: 2023/01/24 12:38:36 by cchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
int		ft_decto_hex(uintptr_t nb, int mode);
int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int		ft_print_adress(unsigned long long adress);
int		ft_print_unsigned(unsigned int num);

#endif