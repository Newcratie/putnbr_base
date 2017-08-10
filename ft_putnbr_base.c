
#include <unistd.h>
#include <stdio.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_double_occ(char *s1, char *s2, int conf)
{
	int		i;

	i = 0;
	while (s1[i + conf])
	{
		if (s1[i + conf] == s2[i])
			return (1);
		i++;
	}
	if (s1[conf] != '\0')
		return (ft_double_occ(s1, s2, conf + 1));
	return (0);
}

int		ft_lbase(char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (ft_double_occ(base, base, 1) == 1)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	int nb_conv[64];
	int lbase;
	unsigned int nbr2;

	lbase = ft_lbase(base);
	i = 0;
	if (nbr < 0 && lbase != 0)
	{
		nbr2 = nbr * -1;
		ft_putchar(45);
	}
	else
		nbr2 = nbr;
	if (nbr2 == 0 && lbase != 0)
		ft_putchar(base[0]);
	while (nbr2 > 0 && lbase != 0)
	{
		nb_conv[i++] = nbr2 % lbase;
		nbr2 = nbr2 / lbase;
	}
	while (i > 0 && lbase != 0)
		ft_putchar(base[nb_conv[i-- - 1]]);
}
