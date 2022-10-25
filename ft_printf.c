/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:41:56 by mcharvel          #+#    #+#             */
/*   Updated: 2022/10/25 19:02:12 by mcharvel         ###   ########.fr       */
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

static int	conv_sel(va_list *ap, char cs)
{
	int	count;

	count = 0;
	if (cs == '%')
		count += ft_putchar('%');
	else if (cs == 'c')
		count += ft_putchar(va_arg(*ap, int));
	else if (cs == 's')
		count += ft_putstr(va_arg(*ap, char *));
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
				i += conv_sel(&args, *str);
			}
		else
			i += ft_putchar(*str);
		str++;
	}
	//return (i);
va_end(args);
return (i);
}

int	main(void)
{
	int		i, a, b;
	char	c;
	char	*s;
	
	i = -123456;
	c = 'K';
	s = "Tequila";
	a = printf("c: %c, s: %s\n", c, s);
	b = ft_printf("c: %c, s: %s\n", c, s);

	printf("printf: %i ft_printf: %i\n", a, b);

}

