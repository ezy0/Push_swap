/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmoren <migmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:59:47 by alflores          #+#    #+#             */
/*   Updated: 2023/06/07 09:26:58 by migmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero_gnl(void *str, size_t n)
{
	unsigned char	*aux;

	aux = str;
	if (n == 0)
		return ;
	while (n > 0)
	{
		*aux = '\0';
		aux++;
		n--;
	}
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*result;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	result = malloc(count * size);
	if (!result)
		return (0);
	ft_bzero_gnl(result, (count * size));
	return (result);
}

char	*ft_strchr_gnl(const char *str, int c)
{
	int	i;
	int	comp;

	if (!str)
		return (NULL);
	comp = 0;
	i = 0;
	while (((char *)str)[i] != '\0' && comp == 0)
	{
		if (((char *)str)[i] == (char)c)
		{
			return ((char *)&str[i]);
			comp = 1;
		}
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen_gnl(s1);
	b = ft_strlen_gnl(s2);
	i = 0;
	str = malloc(a + b + 1);
	if (!(str))
		return (NULL);
	while (a--)
	{
		str[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		str[a++] = s2[i++];
	str[a] = '\0';
	free((void *)s1);
	return (str);
}
