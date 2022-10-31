/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:02:17 by mcharvel          #+#    #+#             */
/*   Updated: 2022/10/31 15:50:06 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	if (n > 9)
			count += ft_putnbr(n / 10);
		count += ft_putchar(48 + n % 10);
	return (count);
}
