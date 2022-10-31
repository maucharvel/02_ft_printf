/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:19 by mcharvel          #+#    #+#             */
/*   Updated: 2022/10/31 16:03:20 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhexa(size_t n, char fs)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbrhexa(n / 16, fs);
	if ((fs == 'x') || (fs == 'p'))
		count += ft_putchar("0123456789abcdef"[n % 16]);
	if (fs == 'X')
		count += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (count);
}
