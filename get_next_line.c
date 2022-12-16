/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:35:22 by astachni          #+#    #+#             */
/*   Updated: 2022/12/16 16:43:01 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	veri_index(int buffer_index, int read_value, char *return_str, char *buffer)
{
	if (!buffer)
		return (buffer_index);
	if (buffer_index >= BUFFER_SIZE)
			buffer_index = 0;
	else if (buffer_index <= BUFFER_SIZE && read_value >= BUFFER_SIZE)
	{
		return_str = ft_strjoin(return_str, &buffer[buffer_index]);
		buffer_index += verify_end(return_str, &buffer[buffer_index]);
		if (buffer_index >= BUFFER_SIZE)
			buffer_index = 0;
	}
	return (buffer_index);
}

int	is_end(size_t buffer_index, char *return_str)
{
	if (!return_str)
		return (0);
	if (buffer_index < BUFFER_SIZE
		&& return_str[ft_strlen(return_str) - 1] == '\n')
		return (-1);
	if (return_str && return_str[ft_strlen(return_str) - 1] == '\n')
		return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char				buffer[BUFFER_SIZE + 1];
	char					*return_str;
	static size_t			buffer_index = 0;
	static size_t			str_index = 0;
	static long long int	read_value;

	return_str = NULL;
	while (1)
	{
		buffer_index = veri_index(buffer_index, read_value, return_str, buffer);
		if (is_end(buffer_index, return_str) == -1)
			break ;
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == -1)
			return (ft_bzero(buffer), NULL);
		if (read_value == 0)
			return (ft_bzero(buffer), NULL);
		return_str = ft_strjoin(return_str, buffer);
		buffer_index += verify_end(return_str, buffer);
		if (buffer_index < BUFFER_SIZE
			&& return_str[ft_strlen(return_str) - 1] == '\n')
			break ;
	}
	return (return_str);
}
