/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bterral <bterral@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:20:30 by bterral           #+#    #+#             */
/*   Updated: 2021/11/16 11:30:48 by bterral          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set, size_t set_len);
static size_t	get_end(char const *s1, char const *set, size_t set_len);

static size_t	get_start(char const *s1, char const *set, size_t set_len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j] != s1[i] && set[j])
			j++;
		if (j == set_len)
			return (i);
		else
			i++;
	}
	return (i);
}

static size_t	get_end(char const *s1, char const *set, size_t set_len)
{
	size_t	s1_index;
	size_t	i;

	s1_index = ft_strlen(s1);
	while (s1_index > 0)
	{
		i = 0;
		while (set[i] != s1[s1_index - 1] && set[i])
			i++;
		if (i == set_len)
			return (s1_index);
		else
			s1_index--;
	}
	return (s1_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	first;
	size_t	last;
	char	*output;

	if (!s1 ||!set)
		return (NULL);
	set_len = ft_strlen(set);
	first = get_start(s1, set, set_len);
	last = get_end(s1, set, set_len);
	if (first > last)
		return (ft_strdup(""));
	else
		output = ft_substr(s1, (unsigned int)first, (last - first));
	return (output);
}
