/*
** gameplay.c for  in /home/piscine/my_ftl/benkri_e
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Thu Apr 13 11:36:01 2017 BENKRIZI El harag
** Last update Tue Apr 18 12:08:43 2017 BENKRIZI El harag
*/


#include <stdlib.h>
#include "ftl.h"

void	stat(t_ship *ship)
{
  my_putstr_color("blue", "  |\tHull :    ");
  my_put_nbr(ship->hull);
  my_putstr("\n");
  my_putstr_color("blue", "  |\tDamage :  ");
  my_put_nbr(ship->weapon->damage);
  my_putstr("\n");
  my_putstr_color("blue", "  |\tEnergy :  ");
  my_put_nbr(ship->drive->energy);
  my_putstr("\n");
  my_putstr_color("blue", "  |\tSector :   ");
  if (ship->navigation_tools->sector == 0)
    my_putstr("0");
  else
    my_put_nbr(ship->navigation_tools->sector);
  my_putstr("\n");
  my_putstr_color("blue", "  |\tEvade :   ");
  my_put_nbr(ship->navigation_tools->evade);
  my_putstr("\n");
}

void	reparerSysteme(t_ship *ship)
{
  my_putstr_color("yellow", "-------------------------------------------\n");
  my_putstr_color("blue", "Que souhaitez vous faire ?\n");
  my_putstr_color("yellow", "Reparer le systeme de jump->\t\t|  ftl_d\
rive\n");
  my_putstr_color("yellow", "Reparer le systeme de detection->\t|  na\
vigation_tools\n");
  my_putstr_color("yellow", "Reparer le systeme d'armement->\t\t|  we\
apon\n");
  my_putstr_color("yellow", "Revenir au menu !->\t\t\t|  exit\n");
  system_repair(ship);
}

void	verifCommande(char *entree)
{
  while ((my_strcmp(entree, "stat") != 0)&&(my_strcmp(entree, "contro\
l_system") != 0)&&(my_strcmp(entree, "repair_system") != 0)&&(my_strcmp(entree, "getbonus") != 0)&&(my_strcmp(entree, "jump") != 0)&&(my_strcmp(entree, "detect") != 0)&&(my_strcmp(entree, "attack") != 0))
    {
      my_putstr("Vous avez choisi la commande : ");
      my_putstr_color("yellow", entree);
      my_putstr("\n");
      my_putstr("Cette commande n'existe pas !\n");
      my_putstr_color("blue", "ftl$>");
      entree = readLine();
    }
}

t_rebel	*createRebel(int nb)
{
  static int	damage;
  static int	life;
  t_rebel	*rebel;

  rebel = malloc(sizeof(t_rebel));
  if (rebel == NULL)
      return NULL;
  if (nb == 1)
    {
      damage = 10;
      life = 20;
      rebel->dammage = damage;
      rebel->life = life;
    }
  else
    {
      rebel->dammage = damage + (damage * 50/100);
      rebel->life = life + (life * 50/100);
      damage = rebel->dammage;
      life = rebel->life;
    }
  return (rebel);
}  

void	gameplay(t_ship *ship)
{
  char		*entree;
  int		detect;
  int		nbEnemy;
  t_rebel	*rebel;
  int		chanceEnemy;
  int		resCombat;

  resCombat = 1;
  nbEnemy = 1;
  detect = 0;
  chanceEnemy = 0;
  while ((ship->navigation_tools->sector < 10) && (ship->hull > 0))
    {
      if (chanceEnemy == 1)
	{
	  attackEnemy(ship, rebel);
	}
      my_putstr_color("yellow", "-------------------------------------------\n");
      my_putstr_color("blue", "Que souhaitez vous faire ?\n");
      my_putstr_color("yellow", "attack\tdetect\tjump\tgetbonus\trepair_system\tcontrol_system\tstat\n");
      my_putstr_color("blue", "ftl$>");
      entree = readLine();
      my_putstr("\n");
      if ((my_strcmp(entree, "stat") != 0)
	  && (my_strcmp(entree, "control_system") != 0)&&(my_strcmp(entree, "repair_system") != 0)&&(my_strcmp(entree, "getbonus") != 0)&&(my_strcmp(entree, "jump") != 0)&&(my_strcmp(entree, "detect") != 0)&&(my_strcmp(entree, "attack") != 0))
	  verifCommande(entree);
      if (my_strcmp(entree, "attack") == 0)
	{
	  if (my_strcmp(ship->weapon->system_state, "online") != 0)
	    {
	      my_putstr_color("red","[IMPOSSIBLE ! ! !]Vos canon sont  H.S\n reparer avec repair_system ! ! !\n");
	      continue;
	    }
	  if (chanceEnemy == 1)
	    {
	      resCombat = attack(ship, rebel);
	      if (resCombat == 1)
		{
		  my_putstr_color("cyan", "Vous avez pulveriser l'ennemie ! ! !\n");
		  chanceEnemy = 0;
		}
	    }
	  else
	    my_putstr_color("red", "Aucun ennemie ! ! Ne gaspillez pas vos munitions ! ! !\n");
	}
      else if (my_strcmp(entree, "detect") == 0)
	{
	  if (my_strcmp(ship->drive->system_state, "online") != 0)
	    {
	      my_putstr_color("red","[IMPOSSIBLE ! ! !]Votre systeme de detection est H.S\n reparer avec repair_system ! ! !\n");
	      continue;
	    }
	  if (detect == 0 && resCombat == 1)
	    detect = detectActivate(ship);
	  else
	    my_putstr_color("blue", "Commande déja utiliser !\n");
	}
      else if (my_strcmp(entree, "jump") == 0)
	{
	  if (my_strcmp(ship->navigation_tools->system_state, "online") != 0)
	    {
	      my_putstr_color("red","[IMPOSSIBLE ! ! !]Votre systeme de jump est H.S\n reparer avec repair_system ! ! !\n");
	      continue;
	    }
	  ship->navigation_tools->sector++;
	  detect = 0;
	  chanceEnemy = chance();
	  if (chanceEnemy == 1)
	    {
	      my_putstr_color("red", "[ATTENTION ! ! !] Rebel détécté ...\n\n");
	      rebel = createRebel(nbEnemy);
	      nbEnemy++;
	    }
	}
      else if (my_strcmp(entree, "getbonus") == 0)
	{
	  if (ship->container == NULL)
	    {
	      my_putstr_color("blue", "Votre container est vide ! ! ! Allez a la chasse\n");
	      continue;
	    }
	  else if (ship->container->first != NULL)
	      get_bonus(ship);
	  my_putstr_color("yellow", "Chargement de la cargaison ! ! !\n");
	}
      else if (my_strcmp(entree, "repair_system") == 0)
	  reparerSysteme(ship);
      else if (my_strcmp(entree, "control_system") == 0)
	  system_control(ship);
      else if (my_strcmp(entree, "stat") == 0)
	  stat(ship);
    }
  if (ship->hull == 0)
    my_putstr_color("blue", "Vous vous etes fais atomisé ! ! !\n");
  else
    my_putstr_color("green", "[B R A V O] Vous avez traversez la galaxie ! ! !\n");
}
