/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:00:32 by mli               #+#    #+#             */
/*   Updated: 2019/10/18 00:48:40 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		w_len(char const *s, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] != c)
			len++;
	}
	return (len + 1);
}

static char		**ft_malloc_w_len(char const *s, char c, char **result)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		len = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			len++;
		}
		if (s[i - 1] != c)
			if (!(result[j++] = (char *)malloc(sizeof(char) * (len + 1))))
				return (NULL);
	}
	if (!(result[j] = (char *)malloc(sizeof(char))))
		return (NULL);
	return (result);
}

static char		**ft_tab_filled(char const *s, char c, char **result)
{
	int i;
	int k;
	int l;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		l = 0;
		while (s[i] != c && s[i])
			result[k][l++] = s[i++];
		if (s[i - 1] != c)
			result[k++][l] = '\0';
	}
	result[k] = NULL;
	return (result);
}

char			**ft_split(char const *s, char c)
{
	char	**result;

	if (s != NULL)
	{
		if (!(result = (char **)malloc(sizeof(char *) * w_len(s, c))))
			return (NULL);
		if ((result = ft_malloc_w_len(s, c, result)))
			return (ft_tab_filled(s, c, result));
	}
	return (NULL);
}
