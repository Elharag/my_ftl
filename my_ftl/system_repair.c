/*
1;3801;0c** system_repair.c for  in /home/piscine/my_ftl
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Tue Apr 11 12:10:04 2017 BENKRIZI El harag
** Last update Tue Apr 18 12:01:12 2017 BENKRIZI El harag
*/

#include <stdlib.h>
#include "ftl.h"

static const t_repair_command	tab[] = {
  {.repair = "ftl_drive", .f = &ftl_drive_system_repair},
  {.repair = "navigation_tools", .f = &navigation_tools_system_repair},
  {.repair = "weapon", .f = &weapon_system_repair}};


void	ftl_drive_system_repair(t_ship *ship)
{
  my_putstr("Reparation du reacteur en cours...\n");
  free(ship->drive->system_state);
  ship->drive->system_state = my_strdup("online");
  if(ship->drive->system_state == NULL)
    my_putstr("Les reparations du reacteur ont échoué !\n");
  else
    my_putstr("Reparation terminé ! Systeme reacteur OK !\n");
}

void	navigation_tools_system_repair(t_ship *ship)
{
  my_putstr("Reparation du systeme de navigation en cours...\n");
  free(ship->navigation_tools->system_state);
  ship->navigation_tools->system_state = my_strdup("online");
  if(ship->navigation_tools->system_state == NULL)
    my_putstr("Les reparations du systeme de navigation ont échoué !\n");
  else
    my_putstr("Reparation terminé ! Systeme de navigation OK !\n");
}

void	weapon_system_repair(t_ship *ship)
{
  my_putstr("Reparation du systeme d'armement en cours...\n");
  free(ship->weapon->system_state);
  ship->weapon->system_state = my_strdup("online");
  if(ship->weapon->system_state == NULL)
    my_putstr("Les reparations du systeme d'armement ont échoué !\n");
  else
    my_putstr("Reparation terminé ! Systeme d'armement OK !\n");
}

void	system_repair(t_ship *ship)
{
  char	*entree = NULL;

  my_putstr_color("blue", "repair_system~>");
  entree = readLine();
  if (entree == NULL)
    my_putstr("[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
  if ((my_strcmp(entree, "ftl_drive") != 0)&&(my_strcmp(entree, "navigation_tools") != 0)&&(my_strcmp(entree, "weapon") != 0)&&(my_strcmp(entree, "exit") != 0))
    {
      while ((my_strcmp(entree, "ftl_drive") != 0)&&(my_strcmp(entree, "navigation_tools") != 0)&&(my_strcmp(entree, "weapon") != 0)&&(my_strcmp(entree, "exit") != 0))
	{
	  my_putstr("[SYSTEM FAILURE] : commande inconnue\n");
	  my_putstr_color("blue", "repair_system~>");
	  entree = readLine();
	}
    }
  if (my_strcmp(entree, "ftl_drive") == 0)
      tab[0].f(ship);
  else if (my_strcmp(entree, "navigation_tools") == 0)
      tab[1].f(ship);
  else if (my_strcmp(entree, "weapon") == 0)
      tab[2].f(ship);
  else if (my_strcmp(entree, "exit") == 0)
      return ;
}
