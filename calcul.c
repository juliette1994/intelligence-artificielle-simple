#include "header.h"

int 	trajet(t_perso *pers)
{
	int		distance;
	int		firstP;
	int		secondP;

	firstP = pers->sortie_x - pers->player_x;
	secondP = pers->sortie_y - pers->player_y;
	distance = abs(firstP) + abs(secondP);
	pers->distance = distance;
	return (distance);
}
 
int 	abs(int num)
{
	int		i;
	int		numtmp;

	i = 0;
	numtmp = num;
	if (num < 0)
	{
		while (numtmp < 0)
		{
			numtmp++;
			i++;
		}
		return(i);
	}
	if (num >= 0 )
		return (num);
	return (1);
}