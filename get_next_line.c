/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:35:22 by astachni          #+#    #+#             */
/*   Updated: 2022/12/15 20:54:37 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (buffer_index >= BUFFER_SIZE)
			buffer_index = 0;
		else if (buffer_index <= BUFFER_SIZE && read_value >= BUFFER_SIZE)
		{
			return_str = ft_strjoin(return_str, &buffer[buffer_index]);
			buffer_index += verify_end(return_str, &buffer[buffer_index]);
			if (buffer_index >= BUFFER_SIZE)
				buffer_index = 0;
			if (buffer_index < BUFFER_SIZE && return_str[ft_strlen(return_str) - 1] == '\n')
				break ;
		}
		if (return_str && return_str[ft_strlen(return_str) - 1] == '\n')
			break ;
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == -1)
			return (ft_bzero(buffer), NULL);
		if (read_value == 0)
			break ;
		return_str = ft_strjoin(return_str, buffer);
		buffer_index += verify_end(return_str, buffer);
		if (buffer_index < BUFFER_SIZE && return_str[ft_strlen(return_str) - 1] == '\n')
			break ;
	}
	return (return_str);
}
