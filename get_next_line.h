/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:36:47 by astachni          #+#    #+#             */
/*   Updated: 2023/01/07 15:43:23 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 650
# endif

char	*get_next_line(int fd);
void	ft_bzero(char *str);
char	*ft_strjoin(char const *s1, char const *buffer);
size_t	verify_end(char *str, char *buffer);
size_t	ft_strlen(char const *str);

#endif