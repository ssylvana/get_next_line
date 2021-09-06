/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 07:27:34 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/18 07:27:37 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*error(char *stat)
{
	free(stat);
	return (NULL);
}

int		check_nl(char *stat, int byte_size)
{
	int	i;

	i = 0;
	if (stat == NULL)
		return (0);
	if (byte_size == 0)
		return (1);
	while (stat[i] != '\0')
	{
		if (stat[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*save_stat(char *stat)
{
	int		i;
	int		j;
	char	*new_stat;

	i = 0;
	while (stat[i] != '\n' && stat[i] != '\0')
		i++;
	j = ft_strlen(stat);
	if (!(new_stat = malloc(sizeof(char) * ((j - i) + 1))))
		return (error(stat));
	ft_strlcpy(new_stat, stat + (i + 1), (j - i) + 1);
	free(stat);
	return (new_stat);
}

char	*save_line(char *stat)
{
	int		j;
	int		i;
	char	*new_line;

	j = 0;
	i = 0;
	while (stat[i] != '\n' && stat[i] != '\0')
		i++;
	if (!(new_line = malloc(sizeof(char) * (i + 1))))
		return (error(stat));
	while (j < i)
	{
		new_line[j] = stat[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}
