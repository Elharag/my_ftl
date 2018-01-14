/*
** detect.c for  in /home/piscine/my_ftl/benkri_e
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Thu Apr 13 12:45:31 2017 BENKRIZI El harag
** Last update Tue Apr 18 12:02:51 2017 BENKRIZI El harag
*/

#include <stdlib.h>
#include <time.h>
#include "ftl.h"


char	*pourcentage()
{
  int   random;

  random = 0;
  random = (rand() % 10) + 1;
  if (random == 1)
    {
      my_putstr_color("green", "fret d'energy ! ! ! Super ...\n");
      my_putstr_color("cyan", "<-------------------------------->\n");
      return ("energy");
    }
  else if (random == 2)
    {
      my_putstr_color("green", "fret d'attack ! ! ! Super ...\n");
      my_putstr_color("cyan", "<-------------------------------->\n");
      return ("attackbonus");
    }
  else if (random == 3)
    {
      my_putstr_color("green", "fret d'evade ! ! ! Super ...\n");
      my_putstr_color("cyan", "<-------------------------------->\n");
      return ("evadebonus");
    }
  my_putstr_color("green", "fret de scrap ! ! ! Dommage ...\n");
  my_putstr_color("cyan", "<-------------------------------->\n");
  return ("scrap");
}


int	detectActivate(t_ship *ship)
{
  int	i;

  i = 0;
  t_freight	**tab;

  add_container_to_ship(ship);
  srand(time (NULL));
  tab = malloc(sizeof(t_freight) * 11);
  if (tab == NULL)
    return (0);
  my_putstr_color("cyan", "On décharge . . .\n");
  while (i < 10)
    {
      tab[i] = malloc(sizeof(t_freight));
      if (tab[i] == NULL)
	  return (0);
      tab[i]->item = my_strdup(pourcentage());
      tab[i]->next = NULL;
      add_freight_to_container(ship, tab[i]);
      i++;
    }
  return (1);
}
