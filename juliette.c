#include "header.h"

int		my_strcmp(char s1, char s2)
{
	if (s1 == s2)
		return (0);
	if (s1 == '\0' || s1 < s2)
		return (-1);
	return (1);
}

void	color_element(char	element)
{
	if (my_strcmp(element, '+') == 0)
	{
		my_putstr("\e[34;47m");
		my_putchar(element);
		my_putstr("\e[0m");
	}
	else if (my_strcmp(element, '#') == 0)
	{
		my_putstr("\e[37;41m");
		my_putchar(element);
		my_putstr("\e[0m");
	}
	else if (my_strcmp(element, '@') == 0)
	{
		my_putstr("\e[32;47m");
		my_putchar(element);
		my_putstr("\e[0m");
	}
	else
		my_putchar(element);
}

void	color_map(char **tab)
{	
	for (int i = 0; i < LINE; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (my_strcmp(tab[i][j], '*') == 0)
			{
				my_putstr("\e[0;30;1;40m");
				my_putchar(tab[i][j]);
				my_putstr("\e[0m");
			}
			else if (my_strcmp(tab[i][j], ' ') == 0)
			{
				my_putstr("\e[0;37;1;47m");
				my_putchar(tab[i][j]);
				my_putstr("\e[0m");
			}
			else
				color_element(tab[i][j]);
		}
	}
}

char	**tab_double(char buffer[210])
{
	int		aide;
	char	**tab;

	tab = malloc(LINE * sizeof(char*));
	aide = 0;
	for (int i = 0; i < LINE && buffer[aide]; i++)
	{
		tab[i] = malloc(COL * sizeof(char));
		for (int j = 0; j < COL && buffer[aide]; j++)
		{
			tab[i][j] = buffer[aide];
			aide++;
		}
	}
	return (tab);
}