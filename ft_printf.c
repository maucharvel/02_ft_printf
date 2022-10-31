/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:41:56 by mcharvel          #+#    #+#             */
/*   Updated: 2022/10/31 16:10:29 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_select(va_list *ap, char fs)
{
	int	count;

	count = 0;
	if (fs == '%')
		count += ft_putchar('%');
	else if (fs == 'c')
		count += ft_putchar(va_arg(*ap, int));
	else if (fs == 's')
		count += ft_putstr(va_arg(*ap, char *));
	else if (fs == 'i' || fs == 'd')
		count += ft_putnbr(va_arg(*ap, unsigned int));
	else if (fs == 'u')
		count += ft_putnbr_un(va_arg(*ap, unsigned int));
	else if (fs == 'x' || fs == 'X')
		count += ft_putnbrhexa(va_arg(*ap, unsigned int), fs);
	else if (fs == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbrhexa(va_arg(*ap, size_t), fs);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += format_select(&args, *str);
		}
		else
			i += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (i);
}
