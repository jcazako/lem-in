#include "lem_in.h"

int	check_opt(char *str, int *opt)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	else
		return (1);
	while (str[i])
	{
		if (!ft_strchr(OPT_FLAG, str[i]))
			return (2);
		else
		{
			if (str[i] == 'a')
				*opt |= OPT_A;
			else if (str[i] == 'b')
				*opt |= OPT_B;
		}
		i++;
	}
	return (0);
}
