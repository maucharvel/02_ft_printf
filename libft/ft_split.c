/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcharvel <mcharvel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:47:58 by mcharvel          #+#    #+#             */
/*   Updated: 2022/09/23 16:17:16 by mcharvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_string(const char *s, char c)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && check == 0)
		{
			check = 1;
			i++;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	int		slen;
	int		strt;
	char	**split;

	j = 0;
	i = -1;
	strt = i;
	slen = ft_strlen(s);
	split = (char **)malloc(sizeof(char *) * (count_string(s, c) + 1));
	if (!split)
		return (NULL);
	while (++i <= slen)
	{
		if (s[i] != c && strt < 0)
			strt = i;
		else if (0 <= strt && (s[i] == c || i == slen))
		{
			split[j++] = ft_substr(s, strt, i - strt);
			strt = -1;
		}
	}
	split[j] = NULL;
	return (split);
}

/*
int main(void)
{
	char const s[] = "  hola  que pasa";
	char c;
	char **result;
	c = ' ';
	result = ft_split(s, c);
	int check = -1;
	while (result[++check])
		printf("line [%d] -> %s\n", check, result[check]);
	//printf("%s", ft_split(s, c));
	return (0);
}
*/