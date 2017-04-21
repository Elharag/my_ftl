/*
** air_shed.c for  in /home/piscine/my_ftl
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Mon Apr 10 10:40:17 2017 BENKRIZI El harag
** Last update Tue Apr 14 09:12:17 2017 BENKRIZI El harag
*/

#include <stdlib.h>
#include "ftl.h"

t_ship		*create_ship()
{
  t_ship		*p_ship;
  //t_weapon		*p_weapon = NULL;
  //t_ftl_drive		*p_drive = NULL;
  //t_navigation_tools	*p_navigation_tools = NULL;
  //  t_container		*p_container = NULL;
  /*t_freight		*freight1 = NULL;
  
  freight1 = malloc(sizeof(*freight1));
  if (freight1 == NULL)
    {
      my_putstr("Erreur dans le freight /n!");
      return (0);
    }*/
  
  my_putstr("Construction du vaisseau en cours...\n");
  p_ship = malloc(sizeof(*p_ship));
  if (p_ship == NULL)
    {
      my_putstr("Le vaisseau n'a pas pu être construit par manque de matèriaux\n");
      return (NULL);
    }
  p_ship->hull = 50;
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  my_putstr("Amélioration du vaisseau terminé !\n");
  return (p_ship);
}

int		add_weapon_to_ship(t_ship *ship)
{
  t_weapon	*weapon = NULL;
  
  my_putstr("Ajout des armes en cours...\n");
  weapon = malloc(sizeof(*weapon));
  if (weapon == NULL)
    {
      my_putstr("Votre vaisseau a explosé quand vous avez tenté d'ajouter les armes !\n");
      return (0);
    }
  weapon->damage = 10;
  weapon->system_state = my_strdup("online");
  ship->weapon = weapon;
  my_putstr("Les armes ont été ajoutes avec succes!\n");
  return (1);
}

int             add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive      *drive = NULL;

  my_putstr("Ajout du reacteur en cours...\n");
  drive = malloc(sizeof(*drive));
  if (drive == NULL)
    {
      my_putstr("Votre vaisseau a explosé lorsque vous avez posé le reacteur !\n");
      return (0);
    }
  drive->energy = 10;
  drive->system_state = my_strdup("online");
  ship->drive = drive;
  my_putstr("Le reacteur a été ajoute avec succes!\n");
  return (1);
}

int		add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*navigation_tools = NULL;

  my_putstr("Ajout des outils de navigations...\n");
  navigation_tools = malloc(sizeof(*navigation_tools));
  if (navigation_tools == NULL)
    {
      my_putstr("Votre vaisseau a explosé lorsque vous vez pose les outils de navigations !\n");
      return (0);
    }
  navigation_tools->sector = 0;
  navigation_tools->evade = 25;
  navigation_tools->system_state = my_strdup("online");
  ship->navigation_tools = navigation_tools;
  my_putstr("Les outils de navigations ont été ajoutés avec succés !\n");
  return (1);
}
