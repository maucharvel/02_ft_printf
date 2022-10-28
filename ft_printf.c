/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maucharvel <maucharvel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:41:56 by mcharvel          #+#    #+#             */
/*   Updated: 2022/10/28 09:20:43 by maucharvel       ###   ########.fr       */
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

int	ft_putstr(char *s)
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
// This function is like putnbr but only for positive numbers (unsigned)
// printf turns negative number into binary, WIP

int	ft_putnbr_un(int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}

int	ft_putnbrhexa(size_t n, char fs)
{
	int	count;

	count = 0;
	if (n >= 16)
			count += ft_putnbrhexa(n / 16, fs);
	if (fs == 'x')
			count += ft_putchar("0123456789abcdef"[n % 16]);
	if (fs == 'X')
			count += ft_putchar("0123456789ABCDEF"[n % 16] + 48);
	return (count);
}

static int	format_select(va_list *ap, char fs)
{
	int	count;

	count = 0;
	if (fs == '%')
		count += ft_putchar('%');
	else if (fs == 'c')
		count += ft_putchar(va_arg(*ap, int)); //Porque es int
	else if (fs == 's')
		count += ft_putstr(va_arg(*ap, char *));
	else if (fs == 'i' || fs == 'd')
		count += ft_putnbr(va_arg(*ap, int));
	else if (fs == 'u')
		count += ft_putnbr_un(va_arg(*ap, unsigned int));
 	else if (fs == 'x' || fs == 'X') 
		count += ft_putnbrhexa(va_arg(*ap, size_t), fs);
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

int	main(void)
{
	int		i, a, b;
	char	c;
	char	*s;

	i = 563;
	c = 'K';
	s = "Mauricio";
	a = printf("character: %c string: %s integer(int): %i integer(decimal): %d unsigned: %u Hexadecimal: %x\n", c, s, i, i, i, i);
	b = ft_printf("character: %c string: %s integer(int): %i integer(decimal): %d unsigned: %u Hexadecimal: %x\n", c, s, i, i, i, i);

	printf("printf: %i ft_printf: %i\n", a, b);

}
