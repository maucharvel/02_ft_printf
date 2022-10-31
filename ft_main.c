/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:07:03 by mcharvel          #+#    #+#             */
/*   Updated: 2022/10/31 15:37:57 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int		i;
	int		a;
	int		b;
	char	c;
	char	*s;

	i = 563;
	c = 'K';
	s = "Mauricio";
	a = printf("c: %c s: %s i: %i id: %d U: %u Hexa: %p\n", c, s, i, i, i, s);
	b = ft_printf("c: %c s: %s i: %i id: %d U: %u H: %p\n", c, s, i, i, i, s);
	printf("printf: %i ft_printf: %i\n", a, b);
}
