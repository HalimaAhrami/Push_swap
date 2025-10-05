/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:15:48 by h-el-ahr          #+#    #+#             */
/*   Updated: 2025/03/12 03:37:45 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_cword(char **str, char c)
{
	int	i;
	int	j;
	int	w;

	i = 1;
	w = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] == c && str[i][j])
			j++;
		while (str[i][j])
		{
			w++;
			while (str[i][j] != c && str[i][j])
				j++;
			while (str[i][j] == c && str[i][j])
				j++;
		}
		i++;
	}
	return (w);
}

char	**ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	*ft_substr(char const *s, int start, int len)
{
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

static	char	**ft_mini_split(char **str, char **s, int i, int k)
{
	int	l;
	int	j;

	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == ' ')
				j++;
			if (str[i][j])
			{
				l = j;
				while (str[i][j] && str[i][j] != ' ')
					j++;
				s[k] = ft_substr(str[i], l, j - l);
				if (!s[k])
					return (ft_free(s));
				k++;
			}
		}
		i++;
	}
	s[k] = NULL;
	return (s);
}

char	**ft_split(char **str)
{
	char	**s;

	if (ft_cword(str, ' ') == 0)
		return (NULL);
	s = (char **)malloc(sizeof(char *) * (ft_cword(str, ' ') + 1));
	if (!s)
		return (NULL);
	return (ft_mini_split(str, s, 1, 0));
}
