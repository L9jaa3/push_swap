#include "checker.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_error_message(char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		write (2, &message[i], 1);
		i++;
	}
	write (2, "\n", 1);
	exit(1);
	return (-1);
}

int	is_sort(t_list **lst)
{
	t_list	*iter;

	iter = (*lst);
	while (iter)
	{
		if (iter->next != NULL)
		{
			if (iter->data > iter->next->data)
				return (0);
		}
		iter = iter->next;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}