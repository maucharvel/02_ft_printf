/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:41:56 by mcharvel          #+#    #+#             */
/*   Updated: 2022/10/26 17:39:52 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/* #include "./includes/ft_printf.h"
#include "./libft/libft.h"
 */

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr (char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
// IMPORTANT: Add count = count + function that writes character
// in order to be able to count each character printed

int	ft_putnbr(int n)
{
	int	count;
	
	count  = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	else
	{
		if (n > 9)
		{
			count += ft_putnbr(n / 10);
		}
		count += ft_putchar(48 + n % 10);
	}
	return (count);
}

static int	format_select(va_list *ap, char fs)
{
	int	count;

	count = 0;
	if (fs== '%')
		count += ft_putchar('%');
	else if (fs == 'c')
		count += ft_putchar(va_arg(*ap, int));
	else if (fs == 's')
		count += ft_putstr(va_arg(*ap, char *));
	else if (fs == 'i' || fs == 'd')
		count += ft_putnbr(va_arg(*ap, int));
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
				str++; // aqui estas en c
				i += format_select(&args, *str);
			}
		else
			i += ft_putchar(*str);
		str++;
	}

va_end(args);
return (i);
}

int	main(void)
{
	int		i, d, a, b;
	char	c;
	char	*s;
	
	i = 123456;
	d = 1.234;
	c = 'K';
	s = "Mauricio";
	a = printf("character: %c string: %s integer(whole): %i integer(decimal): %d\n", c, s, i, d);
	b = ft_printf("character: %c string: %s integer(whole): %i integer(decimal): %d\n", c, s, i, d);

	printf("printf: %i ft_printf: %i\n", a, b);

}

