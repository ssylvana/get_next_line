/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssylvana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 07:27:10 by ssylvana          #+#    #+#             */
/*   Updated: 2021/01/18 07:35:31 by ssylvana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize > 0)
	{
		while ((src[i]) && dstsize - 1 > 0)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j] != '\0' && (i + j + 1) < (dstsize))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen((char *)src));
}

char	*ft_join(char *stat, char *buf)
{
	int		i;
	int		j;
	char	*concat;

	i = 0;
	if (stat != NULL)
		i = ft_strlen(stat);
	else
	{
		if (!(stat = malloc(sizeof(char))))
			return (error(stat));
		stat[0] = '\0';
	}
	j = ft_strlen(buf);
	if (!(concat = malloc(sizeof(char) * (i + j + 1))))
		return (error(stat));
	if (stat != NULL)
		ft_strlcpy(concat, stat, i + 1);
	ft_strlcat(concat, buf, i + j + 1);
	if (stat != NULL)
		free(stat);
	return (concat);
}

int		get_next_line(int fd, char **line)
{
	int				byte_size;
	char			buf[BUFFER_SIZE + 1];
	static char		*stat = NULL;

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1 || (read(fd, buf, 0)) < 0)
		return (-1);
	byte_size = 1;
	while (!(check_nl(stat, byte_size)))
	{
		if ((byte_size = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[byte_size] = '\0';
		stat = ft_join(stat, buf);
	}
	*line = save_line(stat);
	stat = save_stat(stat);
	if (byte_size != 0)
		return (1);
	free(stat);
	stat = NULL;
	return (0);
}
