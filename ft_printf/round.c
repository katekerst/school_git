size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		++i;
	return (i);
}

int			is_not_even_str(char *str)
{
	return ((str[ft_strlen(str) - 1] - '0') % 2);
}

int			count_big_f(long double f)
{
	int count;
	int result;

	count = 0;
	while (f > 1)
	{
		count++;
		f /= 10;
	}
	if (count > 1)
		result = count;
	else
		result = 1;
	return (result);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		*(str + i) = (char)c;
		++i;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	if (!n)
		return ;
	ft_memset(s, 0, n);
}

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	else
		ft_bzero(ptr, size);
	return (ptr);
}

long double	pf_atof_helper(char *s)
{
	long double f;

	f = 0;
	while (*s)
	{
		f *= 10;
		f += (long double)(*s - '0');
		++s;
	}
	return (f);
}

char		*big_f(long double f)
{
	char		*s;
	char		*ptr;
	int			count;
	int			i;
	long double	temp;

	count = count_big_f(f);
	if (!(s = (char*)ft_memalloc(count + 1)))
		return (NULL);
	ptr = s;
	while (count)
	{
		i = count - 1;
		temp = f;
		while (i--)
			temp /= 10;
		*ptr++ = (int)temp + '0';
		temp = (int)temp;
		while (++i < count - 1)
			temp *= 10;
		f -= temp;
		--count;
	}
	return (s);
}

char		*little_f(long double f, int p, char *big_f)
{
	char	*s;
	int		i;

	i = 0;
	f = f < 0 ? -f : f;
	f -= pf_atof_helper(big_f);
	if (!(s = (char*)ft_memalloc(p + 1)))
		return (NULL);
	while (i < p)
	{
		f *= 10;
		s[i++] = (f > 0) ? (int)f + '0' : '0';
		f -= (int)f;
	}
	return (s);
}

long double	ten_pow(int pow)
{
	long double f;

	f = 1;
	while (pow > 0)
	{
		f = f * 10;
		--pow;
	}
	while (pow < 0)
	{
		f = f / 10;
		++pow;
	}
	return (f);
}

long double	ft_round(double f, int precision)
{
	long double	temp;
	char		*big_s;
	char		*little_s;

	f = f < 0 ? -f : f;
	temp = f * ten_pow(precision);
	big_s = big_f(temp);
	little_s = little_f(temp, precision, big_s);
	temp -= pf_atof_helper(big_s);
	free(big_s);
	if (temp > 0.5 || (temp == 0.5 && is_not_even_str(big_s)))
		f += 0.5 * ten_pow(-precision);
	return (f);
}