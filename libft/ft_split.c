/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:21:23 by bterral           #+#    #+#             */
/*   Updated: 2021/11/18 10:29:18 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(const char *s, char c);
static size_t	get_len(const char *str, char c);
static char		**get_strings(char const *s, char c, size_t split_size);
static char		**ft_clean_malloc(char **output);

static size_t	get_size(const char *s, char c)
{
	size_t	count;
	char	boolean;

	count = 0;
	boolean = 0;
	while (*s)
	{
		if (*s != c)
			boolean = 1;
		else if (*s == c && boolean == 1)
		{
			count++;
			boolean = 0;
		}
		s++;
	}
	if (boolean == 1)
		count++;
	return (count);
}

static size_t	get_len(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

static char	**ft_clean_malloc(char **output)
{
	size_t	i;

	i = 0;
	while (output[i++])
		free(output[i]);
	free(output);
	return (NULL);
}

static char	**get_strings(char const *s, char c, size_t split_size)
{
	char	**str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(s) * (split_size + 1));
	if (!str)
		return (NULL);
	while (split_size-- > 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			str[j] = ft_substr(s, i, get_len(&s[i], c));
			if (str[j] == NULL)
				return (ft_clean_malloc(str));
			i += get_len(&s[i], c);
			j++;
		}
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**output;
	size_t			split_size;

	if (!s)
		return (NULL);
	split_size = get_size(s, c);
	output = get_strings(s, c, split_size);
	return (output);
}
