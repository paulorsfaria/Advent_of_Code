/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:41:02 by paulo-do          #+#    #+#             */
/*   Updated: 2023/12/02 15:29:54 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gondola.h"
static long int	count_numbers(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		counter++;
	}
	while (n != 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}
int	checknumbers(char *line1, char *line2, char *line3)
{
	int i = 0;
	int temp = 0;
	int nbr = 0;
	while(line1[i] != '\0' && line2[i] != '\0' && line3[i] != '\0')
	{
		if((line1[i] >= '0' && line1[i] <= '9')  && line2[i] == )
		{
			nbr = atoi(&line1[i]);
			if()
			temp += atoi(&line1[i]);

		}
		i++;
	}
}

int	main(void)
{
	int file;
	char *line1;
	char *line2;
	char *line3;
	int id = 0;

	file = open("input", O_RDONLY);
	while(((line1 = get_next_line(file)) != NULL))
	{
		line2 = get_next_line(file);
		line3 = get_next_line(file);
		checknumbers(line1, line2, line3);
	}
	printf("%d", id);
	close(file);
	return 0;
}