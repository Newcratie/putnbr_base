#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base);

char	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int	main(int argc, char **argv)
{	
	if (argc == 1)
		return (0);
	ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}

