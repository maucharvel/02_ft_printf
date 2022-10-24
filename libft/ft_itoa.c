/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:25:46 by mcharvel          #+#    #+#             */
/*   Updated: 2022/09/22 10:47:28 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	if (n < 0)
		len = len + 1;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*new_str;
	int		i;
	int		str_length;
	long	nbr;

	nbr = n;
	str_length = ft_len(nbr);
	new_str = (char *)malloc(sizeof(char) * (str_length + 1));
	if (new_str == 0)
		return (0);
	new_str[str_length] = 0;
	i = 0;
	if (nbr < 0)
	{
		new_str[i] = '-';
		nbr = nbr * -1;
	}
	if (nbr == 0)
		new_str[0] = '0';
	while (nbr > 0)
	{
		new_str[str_length - i++ - 1] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (new_str);
}
