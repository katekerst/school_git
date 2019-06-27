#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void		ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10);
	}
}

int main(void)
{
	float i;
	
	i = 3.14;
	ft_putnbr(i);
	return (0);
}