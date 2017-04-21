/*
** my_put_nbr.c for  in /home/piscine/jourC05
** 
** Made by BENKRIZI El harag
** Login   <benkri_e@etna-alternance.net>
** 
** Started on  Fri Mar 24 09:38:49 2017 BENKRIZI El harag
** Last update Thu Apr 13 16:29:36 2017 BENKRIZI El harag
*/

#include <unistd.h>

void	my_putnbr(int n);
void	my_number();
void	my_putnbrC(int res, int mod);

void	my_number()
{
  write(1, "-", 1);
  write(1, "2", 1);
  write(1, "1", 1);
  write(1, "4", 1);
  write(1, "7", 1);
  write(1, "4", 1);
  write(1, "8", 1);
  write(1, "3", 1);
  write(1, "6", 1);
  write(1, "4", 1);
  write(1, "8", 1);
}

void	my_putnbrC(int res, int mod)
{
  int	i;
  char	number[100];

  i = 0;
  while(res > 0)
    {
      if(mod >= 0)
	{
	  mod = res % 10;
	  res = res / 10;
	  number[i] = mod + 48;
	  i++;
	}
    }
  number[i] = '\0';
  i--;
  while(i >= 0)
    {
      write(1, &number[i], 1);
      i--;
    }
}

void	my_put_nbr(int n)
{
  int	res;
  int	mod;

  res = n;
  mod = n;
  if(n == -2147483648)
  {
    //write(1, "-", 1);
    my_number();
  }
  if(n < 0)
    {
      write(1, "-", 1);
      n = n * -1;
      res = n;
      mod = n;
    }
  if(n >= 2147483647)
    my_putnbrC(res, mod);
  if (n == 0)
    my_putnbrC(n, mod);
  my_putnbrC(res, mod);
}
