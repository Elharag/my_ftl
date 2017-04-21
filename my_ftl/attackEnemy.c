/*
** attackEnemy.c for  in /home/piscine/my_ftl/benkri_e
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Fri Apr 14 12:45:57 2017 BENKRIZI El harag
** Last update Sat Apr 14 16:28:19 2017 BENKRIZI El harag
*/

#include <stdlib.h>
#include <time.h>
#include "ftl.h"

void	attackEnemy(t_ship *ship, t_rebel *rebel)
{
  int	evite;
  int	tmp;
  int	random;

  random = 0;
  srand(time (NULL));
  tmp = 10;
  evite = 0;
  evite = 100 / ship->navigation_tools->evade;
  tmp -= evite;
  random = (rand() % 10) + 1;
  if (random < tmp)
      my_putstr_color("green", "Attack évité ! ! !\n");
  else
    {
      my_putstr_color("red", "Touché ! ! !\n");
      ship->hull -= rebel->dammage;
      random = (rand() % 10) + 1;
      if (random > 7)
	{
	  if (random == 8)
	    ship->weapon->system_state = my_strdup("offline");
	  else if (random == 9)
	    ship->navigation_tools->system_state = my_strdup("offline");
	  else if (random == 10)
	    ship->drive->system_state = my_strdup("offline");
	  my_putstr_color("blue", "Systeme de controle abime ! ! !\n");
	}
    }
}
