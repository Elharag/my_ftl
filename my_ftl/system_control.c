/*
** system_control.c for  in /home/piscine/my_ftl
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Tue Apr 11 11:56:46 2017 BENKRIZI El harag
** Last update Thu Apr 13 16:50:05 2017 BENKRIZI El harag
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("blue", "Verification du reacteur en cours...\n");
  if (my_strcmp(ship->drive->system_state, "online") == 0)
    my_putstr_color("green", "Reacteur OK !\n");
  else
    my_putstr_color("red", "Reacteur hors service !\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("blue", "Verification du systeme de navigation en cours...\n");
  if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    my_putstr_color("green", "Systeme de navigation en marche !\n");
  else
    my_putstr_color("red", "Systeme de navigation hors service !\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr_color("blue", "verification du systeme d'armement en cours...\n");
  if (my_strcmp(ship->weapon->system_state, "online") == 0)
    my_putstr_color("green", "Systeme d'armement OK !\n");
  else
    my_putstr_color("red", "Systeme d'armement hors service !\n");
}

void	system_control(t_ship *ship)
{
  my_putstr_color("yellow", "-----------------------------------\n");
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
  my_putstr_color("yellow", "-----------------------------------\n");
}
