/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:41:02 by paulo-do          #+#    #+#             */
/*   Updated: 2024/01/04 01:22:27 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scratchcards.h"

//int get_numbers(char *pnt)
//{
//
//}

int get_winning_points(char *str)
{
	int nbr[10];
	int n = 0;
	int	pool[25];
	int p =0;
	int i = 0;
	int result = 1;
	int dups = 0;

	while(str[i] != ':')
		i++;
	i++;
	while(str[i] != '|')
	{
		while(str[i] == ' ')
			i++;
		if(str[i] == '|')
			break;
		nbr[n] = ft_atoi(str, i);
		n++;
		while(str[i] != ' ')
			i++;
	}
	i++;
	while(str[i] != '\0')
	{
		while(str[i] == ' ')
			i++;
		pool[p] = ft_atoi(str, i);
		p++;
		while(str[i] != ' ' && str[i] != '\0')
			i++;
	}
 	n = 0;
	p = 0;
	while(n < 10)
	{
		while(p < 25)
		{
			if(nbr[n] == pool[p]) { dups++; break;}
			p++;
		}
		p = 0;
		n++;
	}
//	if(dups == 0)
//		return 0;
	if(dups == 1)
		return 1;
	while(dups - 1 > 0)
	{
		result = result * 2;
	//	printf("%d\n", dups);
		dups--;
		//printf("result %d\n", result);
	}
	return result;

}
int	main(void)
{
	int file;
	char *pnt;
	int id = 0;

	file = open("input", O_RDONLY);
	while(((pnt = get_next_line(file)) != NULL))
	{
		id += get_winning_points(pnt);
		free(pnt);
	}
	printf("%d", id);
	close(file);
	return 0;
}