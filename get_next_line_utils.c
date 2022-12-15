/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:37:14 by astachni          #+#    #+#             */
/*   Updated: 2022/12/15 18:54:52 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	verify_end(char *str, char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != buffer[j])
	{
		if (str[i] == '\n')
			return (0);
			i++;
	}
	while (str[i++] == buffer[j++])
		if (str[i] == '\n')
			return (j + 1);
	return (j);
}

void	ft_bzero(char *str)
{
	size_t	index;

	index = 0;
	while (str && str[index])
		str[index++] = '\0';
}

size_t	ft_strlen(char const *str)
{
	const char	*str_start;

	str_start = str;
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		str++;
	return (str - str_start);
}

size_t	ft_strcpy(char	*s1, char *s2)
{
	int	i;

	i = -1;
	if (s1)
		while (s1[++i])
			s2[i] = s1[i];
	if (i == -1)
		return (0);
	return (i);
}

char	*ft_strjoin(char const *s1, char const *buffer)
{
	char	*str;
	int		i;
	int		j;
	size_t	s1_len;

	if (buffer == NULL)
		return (NULL);
	if (s1 == NULL)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	str = malloc(((s1_len + ft_strlen(buffer) + 1) * sizeof(char)));
	if (str == NULL)
		return (NULL);
	i = ft_strcpy((char *)s1, str);
	j = 0;
	while (buffer && buffer[j] && buffer[j] != '\n')
		str[i++] = buffer[j++];
	if (buffer[j] == '\n')
		str[i++] = '\n';
	str[i] = 0;
	return (str);
}
