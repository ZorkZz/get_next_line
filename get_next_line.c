/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:03:49 by astachni          #+#    #+#             */
/*   Updated: 2023/01/07 18:44:17 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	take_read(char *str, char *buffer, int read_buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		while (str[i] && buffer[0] && str[i] != buffer[0])
			i++;
		j = read_buffer;
		while (str[i] && buffer[j] && str[i] == buffer[j])
		{
			write(1, &str[i], 1);
			write(1, "\n", 1);
			write(1, &buffer[j], 1);
			write(1, "\n", 1);
			i++;
			j++;
		}
		if (str[i] && buffer[j] && str[i] != buffer[j])
		{
			j = read_buffer;
			i++;
		}
	}
	if (j >= BUFFER_SIZE)
		j = 0;
	return (j);
}

char	*get_next_line(int fd)
{
	char					*str;
	static char				buffer[BUFFER_SIZE + 1];
	static long long int	read_value;
	static size_t			read_buffer = 0;

	if (fd < 0)
		return (NULL);
	str = NULL;
	while (str == NULL || str[ft_strlen(str) - 1] != '\n')
	{
		if (read_buffer == 0 || read_buffer >= BUFFER_SIZE)
			read_value = read(fd, buffer, BUFFER_SIZE);
		str = ft_strjoin(str, &buffer[read_buffer]);
		if (read_value == 0)
			return (str);
		if (read_value == -1)
			return (ft_bzero(buffer), NULL);
		read_buffer = take_read(str, &buffer[read_buffer], read_buffer);
	}
	return (str);
}
