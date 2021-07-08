#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	if (!dst && !src)
		return (dst);
	while (n-- > 0)
	{
		*dest++ = *source++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (!s1 && !s2)
		return (NULL);
	if (s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	ft_memcpy(str + ft_strlen(str), s2, ft_strlen(s2) + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*str;

	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (str == 0)
		return (NULL);
	return ((char *)ft_memcpy(str, s1, len));
}
