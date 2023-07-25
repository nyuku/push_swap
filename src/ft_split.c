
#include "../includes/push_swap.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	len_word(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static char	*malloc_word(char const *s, char c, int index)
{
	int		len;
	int		i;
	char	*ptr;

	len = len_word(s, c, index);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[index];
		i++;
		index++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ptr;
	int		count_words;
	int		index;

	if (!s)
		return (0);
	count_words = count_word(s, c);
	ptr = ft_calloc((count_word(s, c) + 1), sizeof(char *));
	if (!ptr)
		return (0);
	i = 0;
	index = 0;
	while (i < count_words && s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		if (s[index] != '\0' && s[index] != c)
			ptr[i] = malloc_word(s, c, index);
		while (s[index] != c && s[index] != '\0')
			index++;
		i++;
		ptr[i] = 0;
	}
	return (ptr);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = 0;
	ptr = (char *)(malloc(size * count));
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}
void	*ft_memset(void *p, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)p;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (p);
}
