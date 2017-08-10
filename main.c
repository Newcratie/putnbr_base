#include <stdio.h>
#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(int argc, char **argv)
{	
	if (argc == 1)
		return (0);
	ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}

