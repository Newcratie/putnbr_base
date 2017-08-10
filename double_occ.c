#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1[i] == '\0' || s2[i] == '\0')
		return (s1[i] - s2[i]);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		if (s1[i] == '\0' || s2[i] == '\0')
			return (s1[i] - s2[i]);
	}
	return (0);
}

int		ft_double_occ(char *s1, char *s2, int conf)
{
	int	i;

	i = 0;
	printf("\nINIT:  conf = %d, i = %d, s1: %s, s2: %s\n",conf, i, &s1[conf], s2);

	while (s1[i + conf])
	{
		printf("conf = %d, i = %d, s1: %c, s2: %c,\n",conf, i,s1[i + conf],s2[i]);
		if (s1[i + conf] == s2[i])
		{
			return (1);

		}
		i++;
	}
	if (s1[conf] != '\0')
		return(ft_double_occ(s1, s2, conf + 1));
	return (0);
}


int	main(int argc, char **argv)
{	
	if (argc == 1)
		return (0);
	printf("%d\n", ft_double_occ(argv[1], argv[1],1));
	return (0);
}
