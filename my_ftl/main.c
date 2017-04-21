/*
1;3801;0c** main.c for  in /home/piscine/my_ftl
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Mon Apr 10 10:37:20 2017 BENKRIZI El harag
** Last update Thu Apr 13 18:34:10 2017 BENKRIZI El harag
*/

#include "ftl.h"
#include <stdio.h>

void	afficheMyftl()
{
  my_putstr_color("cyan", " ___  ___   ___    ___          _______    ________    __\n");
  my_putstr_color("cyan", "|   \x5c/   |  \x5c  \x5c  /  /         | ______|  |__    __|  |  |\n");
  my_putstr_color("cyan", "|        |   \x5c  \x5c/  /          | |____       |  |     |  | \n");
  my_putstr_color("cyan", "|  |\x5c/|  |    \x5c    /           |  ____|      |  |     |  | \n");
  my_putstr_color("cyan", "|  |  |  |     |  |            | |           |  |     |  |___ \n");
  my_putstr_color("cyan", "|__|  |__|     |__|            |_|           |__|     |______|\n");
  
}

int	main()
{
  t_ship	*p;
  my_putstr("\033[H\033[2J");
  afficheMyftl();
  p = create_ship();
  gameplay(p);
  return (0);
}
