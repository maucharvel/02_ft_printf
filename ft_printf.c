/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maucharvel <maucharvel@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:41:56 by mcharvel          #+#    #+#             */
/*   Updated: 2022/10/24 14:35:55 by maucharvel       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = vfprintf (stdout, format, args);
	va_end (args);
	return (i);
}

int	main(void)
{
	ft_printf("Hello\n");
}
