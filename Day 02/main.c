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

#include "cube.h"

int get_red(char *pnt, int i)
{
	int red = 0;
	red = atoi(&pnt[i]);
//	printf("get_red %d\n" ,red);
	return red;
}

int get_green(char *pnt, int i)
{
	int green = 0;
	green = atoi(&pnt[i]);
//	printf("get_green %d\n" ,green);

	return green;
}

int get_blue(char *pnt, int i)
{
	int blue = 0;
	blue = atoi(&pnt[i]);
//	printf("get_blue %d\n" ,blue);
	return blue;
}
int get_game_id(char *pnt)
{
	int i = 0;
	int id = 0;
	int red = 0;
	int green = 0;
	int blue = 0;

	id = atoi(&pnt[5]);

	while(pnt[i])
	{
		if(pnt[i] >= '0' && pnt[i] <= '9')
		{
			if(pnt[i + 2]  == 'r'&& pnt[i + 3] == 'e' && pnt[i + 4] == 'd' || pnt[i + 3] == 'r' && pnt[i + 4] == 'e' && pnt[i + 5] == 'd')
			{
				red += get_red(pnt, i);
				if(pnt[i + 3] == 'r')
					i++;
				if(red > 12)
					return 0;
			}
			if(pnt[i + 2] == 'g' && pnt[i + 3] == 'r' || pnt[i + 3] == 'g' && pnt[i + 4] == 'r' )
			{
				green += get_green(pnt, i);
				if(pnt[i + 3] == 'g')
					i++;
				if(green > 13)
					return 0;
			}
			if(pnt[i + 2] == 'b' && pnt[i + 3] == 'l'|| pnt[i + 3] == 'b' && pnt[i + 4] == 'l')
			{
				blue += get_blue(pnt, i);
				if(pnt[i + 3] == 'b')
					i++;
				if(blue > 14)
					return 0;
			}
		}
		i++;
	}
	printf("red: %d\nblue: %d\ngreen: %d\nid:%d\ngame:%s\n",red ,blue , green, id, pnt);
		return id;
}

int	main(void)
{
	int file;
	char *pnt;
	int id = 0;

	file = open("input", O_RDONLY);
	while(((pnt = get_next_line(file)) != NULL))
	{
		id += get_game_id(pnt);
		free(pnt);
	}
	printf("%d", id);
	close(file);
	return 0;
}