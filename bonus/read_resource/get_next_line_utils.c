#include "get_next_line.h"

size_t	ft_strlen(const char *senc)
{
	int	i;

	if (!senc)
		return (0);
	i = 0;
	while (senc[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	slen;
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	slen = ft_strlen(s1);
	str = (char *)(malloc((slen + 1) * sizeof(char)));
	if (!str)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)(ft_strlen(s)))
	{
		sub = (char *)(malloc(1));
		if (sub)
			sub[0] = '\0';
		return (sub);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}