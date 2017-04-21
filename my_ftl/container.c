/*
** container.c for  in /home/piscine/my_ftl
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Mon Apr 10 13:04:08 2017 BENKRIZI El harag
** Last update Fri Apr 14 13:19:34 2017 BENKRIZI El harag
*/

#include <stdlib.h>
#include "ftl.h"

int	add_container_to_ship(t_ship *ship)
{
  t_container	*container = NULL;

  my_putstr("Ajout du container en cours ...\n");
  container = malloc(sizeof(*container));
  if(container == NULL)
    {
      my_putstr("Votre vaisseaua explose lorsque vous avez pose le container !");
      return (0);
    }
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;
  my_putstr("Le container a été ajouté avec succes !\n");
  return (1);
}

void	add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if (freight == NULL)
    return ;
  if (ship->container->last == NULL)
    {
      freight->prev = NULL;
      ship->container->first = freight;
      ship->container->last = freight;
      freight->next = NULL;
    }
  else if (ship->container->last != NULL)
    {
      ship->container->last->next = freight;
      freight->prev = ship->container->last;
      ship->container->last = freight;
      ship->container->last->next = NULL;
    }
  ship->container->nb_elem++;
}

void	del_freight_from_container(t_ship *ship, t_freight *freight)
{
  t_freight *addr;
  t_freight *tmp;
  t_freight *temp;

  if (freight == NULL)
      return ;
  tmp = ship->container->first;
    addr = freight;
  while ((tmp != NULL) && (tmp != addr))
      tmp = tmp->next;
  if (tmp->next == NULL)
    {
      ship->container->last = freight->prev;
      ship->container->last->next = NULL;
      free(freight);
    }
  else if (tmp->prev == NULL)
    {
      ship->container->first = freight->next;
      ship->container->first->prev = NULL;
      free(freight);
    }
  else
    {
      temp = tmp;
      tmp = tmp->prev;
      tmp->next = temp->next;
      temp = temp->next;
      temp->prev = tmp;
      free(freight);
    }
}

void	get_bonus(t_ship *ship)
{
  t_freight	*tempo;
  
  tempo = ship->container->first;
  while(tempo != NULL)
    {
      if (my_strcmp(tempo->item, "attackbonus") == 0)
	{
	  ship->weapon->damage += 5;
	  del_freight_from_container(ship, tempo);
	}
      if (my_strcmp(tempo->item, "evadebonus") == 0)
	{
	  ship->navigation_tools->evade += 3;
	  del_freight_from_container(ship, tempo);
	}
      if (my_strcmp(tempo->item, "energy") == 0)
	{
	  ship->drive->energy += 1;
	  del_freight_from_container(ship, tempo);
	}
      if (my_strcmp(tempo->item, "scrap") == 0)
	{
	  //tempo = tempo;
	  del_freight_from_container(ship, tempo);
	}
      tempo = tempo->next;
    }
}
