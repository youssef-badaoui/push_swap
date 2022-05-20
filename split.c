#include "push_swap.h"

static int	hms(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	if (str[0] == 0)
		return (0);
	if (str[0] != c)
		count ++;
	while (str[i])
	{
		if (str[i] != c)
			if (str[i - 1] == c)
				count ++;
		i++;
	}
	return (count);
}

static int	s_lent(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	find_i(const char *s, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (s[0] != c)
	{
		if (n == 0)
			return (0);
		i++;
	}
	while (s[j])
	{
		if (s[j] != c && s[j - 1] == c)
		{
			if (n == i)
				return (j);
			i++;
		}
		j++;
	}
	return (0);
}

static char	*ft_strd(const char *str, char *ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	t_variables	vr;
	char		**str;

	if (!s)
		return (0);
	vr.v_hms = hms((char *)s, c);
	vr.i = -1;
	str = (char **)malloc((sizeof(char *) * (vr.v_hms + 1)));
	if (!str)
		return (0);
	while (++(vr.i) < vr.v_hms)
	{
		vr.n = find_i(s, c, vr.i);
		vr.size = s_lent(s + (vr.n), c);
		str[vr.i] = malloc(1 * (vr.size +1));
		if (!str[vr.i])
		{
			while (--(vr.i) >= 0)
				free(str[(vr.i)]);
			return (free(str), NULL);
		}
		ft_strd(s + (vr.n), str[vr.i], vr.size);
	}
	str[vr.i] = NULL;
	return (str);
}
