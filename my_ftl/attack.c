/*
** attack.c for  in /home/piscine/my_ftl/benkri_e
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Fri Apr 14 12:22:58 2017 BENKRIZI El harag
** Last update Fri Apr 14 12:33:47 2017 BENKRIZI El harag
*/

#include <stdlib.h>
#include "ftl.h"

int	attack(t_ship *ship, t_rebel *rebel)
{
  rebel->life = rebel->life - ship->weapon->damage;
  if (rebel->life <= 0)
    {
      free(rebel);
      return (1);
    }
  return (0);
}
