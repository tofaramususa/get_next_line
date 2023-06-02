/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmususa <tmususa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:28:26 by tmususa           #+#    #+#             */
/*   Updated: 2023/02/26 17:24:13 by tmususa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			value;
	unsigned char	*bp;

	ptr = malloc(count * size);
	if (count && SIZE_MAX / count < size)
		return (NULL);
	if (!ptr)
		return (NULL);
	value = count * size;
	bp = (unsigned char *) ptr;
	while (value--)
	{
		*bp = (unsigned char) 0;
		bp++;
	}
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *) dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*s12;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *) s1);
	s2_len = ft_strlen((char *) s2);
	s12 = (char *) malloc(s2_len + s1_len + 1);
	if (s12 == NULL)
		return (NULL);
	j = 0;
	ft_memcpy(s12, s1, s1_len);
	ft_memcpy(s12 + s1_len, s2, s2_len);
	s12[s2_len + s1_len] = '\0';
	free(s1);
	return (s12);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((char ) c == s[i])
			return (((char *)s + i));
		i++;
	}
	if ((char) c == '\0')
		return ((char *)s + i);
	return (NULL);
}
