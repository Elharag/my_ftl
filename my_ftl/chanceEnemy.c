/*
** chanceEnemy.c for  in /home/piscine/my_ftl/benkri_e
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Fri Apr 14 11:55:58 2017 BENKRIZI El harag
** Last update Tue Apr 18 12:02:51 2017 BENKRIZI El harag
*/

#include <stdlib.h>
#include <time.h>

int	chance()
{
  float	chance;

  chance = 0.0;
  srand(time(NULL));
  chance = (rand() % 3) + 1;
  if (chance == 1)
    return (1);
  return (0);
}
