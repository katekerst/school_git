
char		*ft_inttobin(long mantissa)
{
	char	*mant;
	char	*reverse;
	int		i;
	int		k;

	if (!(mant = (char *)malloc(sizeof(char) * (53))))
		return (NULL);
	mant[52] = '\0';
	i = 51;
	while (i >= 0)
	{
		mant[i] = (mantissa % 2) + '0';
		mantissa /= 2;
		i--;
	}
	//printf ("mantissa array is %s\n", mant);

	return (mant);
}

char		*ft_inttobin2(int exponent)
{
	char	*expon;
	int		i;

	if (!(expon = (char *)malloc(sizeof(char) * (33))))
		return (NULL);
	expon[32] = '\0';
	i = 31;
	while (i >= 0)
	{
		expon[i] = (exponent % 2) + '0';
		exponent /= 2;
		i--;
	}
	//printf ("exponent array is %s\n", expon);
	return (expon);
}

double	ft_double_recovery(char *mantissa, int exponent)
{
	double result;

	result = 0;
	while (mantissa[exponent] != '\0')
	{
		result += ((mantissa[exponent] - 48) * pow(2, exponent));
		exponent--;
	}
	return (result);
}


	// printf ("string before rounding is %s\n", copy);
	//printf ("n is %f, temp is %d\n", n, temp);
	// if ((int)n > 5 || temp % 2 == 1 || copy[*i - 1] > 53)
	// {
	// 	if (copy[*i - 1] == '9')
	// 	{
	// 		printf ("1\n");
	// 		copy[*i - 1] = 48;
	// 		copy[*i - 2] += 1;
	// 	}
	// 	else
	// 	{
	// 		copy[*i - 1] = (temp + 1) + 48;
	// 		printf ("2\n");
	// 	}
		// if (temp > 5)
		// {
		// 	printf ("check first\n");
			// if (copy[*i - 2] == '9')
			// {
			// 	printf ("check second\n");
			// 	(*i)--;
			// 	while (copy[*i] == '9')
			// 		(*i)--;
			// 	copy[*i] += 1;
				// if (copy[*i] == '9')
				// {
				// 	(*i)--;
				// 	while (copy[*i] == '9')
				// 		(*i)--;
				// 	copy[*i] += 1;
				// }
			// 	(*i)++;
			// 	while (copy[*i] != '\0')
			// 	{
			// 		copy[*i] = '0';
			// 		(*i)++;
			// 	}
			// }
			// else
			// {
			// 	copy[(*i - 2)] += 1;
			// 	copy[(*i - 1)] = 48;
			// }