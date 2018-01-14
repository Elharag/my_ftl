#ifndef __FTL_H__

#define __FTL_H__

typedef struct		s_weapon
{
  char		       *system_state;
  int			damage;
  struct s_weapon      *next;
}			t_weapon;

typedef struct		s_ftl_drive
{
  char			*system_state;
  int			energy;
}			t_ftl_drive;

typedef struct		s_navigation_tools
{
  char			*system_state;
  int			sector;
  int			evade;
}			t_navigation_tools;

typedef struct		s_freight
{
  char			*item;
  struct s_freight    	*next;
  struct s_freight     	*prev;
}			t_freight;

typedef struct		s_container
{
  struct s_freight	*first;
  struct s_freight    	*last;
  int			nb_elem;
}			t_container;

typedef	struct		s_rebel
{
  int			dammage;
  int			life;
}			t_rebel;

typedef	struct		s_ship
{
  int				hull;
  struct s_weapon		*weapon;
  struct s_ftl_drive		*drive;
  struct s_navigation_tools	*navigation_tools;
  struct s_container		*container;
}			t_ship;

typedef struct          s_repair_command
{
  char                  *repair;
  void                  (*f)(t_ship *ship);
}                       t_repair_command;

t_ship	*create_ship();
void	my_putstr(char *str);
char	*my_strdup(char *str);
int	my_strcmp(char *s1, char *s2);
int	add_weapon_to_ship(t_ship *weapon);
int	add_ftl_drive_to_ship(t_ship *drive);
int	add_navigation_tools_to_ship(t_ship *navigation_tools);
int	add_container_to_ship(t_ship *container);
void	add_freight_to_container(t_ship *ship, t_freight *freight);
void	del_freight_from_container(t_ship *ship, t_freight *freight);
void	get_bonus(t_ship *ship);
void	ftl_drive_system_check(t_ship *ship);
void	navigaiton_tools_system_check(t_ship *ship);
void	weapon_system_check(t_ship *ship);
void	system_control(t_ship *ship);
void	ftl_drive_system_repair(t_ship *ship);
void	navigation_tools_system_repair(t_ship *ship);
void	weapon_system_repair(t_ship *ship);
char	*readLine();
void	system_repair(t_ship *ship);
void	gameplay(t_ship *ship);
void	my_putstr_color(const char *color, const char *str);
int	detectActivate(t_ship *ship);
void	my_put_nbr(int n);
void	stat(t_ship *ship);
void	reparerSysteme(t_ship *ship);
int	chance();
int	attack(t_ship *ship, t_rebel *rebel);
void	attackEnemy(t_ship *ship, t_rebel *rebel);
#endif
