/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scratchcards.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:34:36 by paulo-do          #+#    #+#             */
/*   Updated: 2024/01/04 00:43:01 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*get_new_line(char *stash);
char	*trim_stash(char *stash);
char	*strjoin(char *stash, char *temp);
char	*read_file(int fd, char *stash );
int		ft_strlen(const char *str);
int		checkenter(char *stash);
int	ft_atoi(const char *str, int j);

#endif