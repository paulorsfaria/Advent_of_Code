#ifndef GONDOLA_H
# define GONDOLA_H

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

#endif