##
## Makefile for  in /home/piscine/chifumi
## 
## Made by BENKRIZI El harag
## Login   <benkri_e@etna-alternance.net>
## 
## Started on  Sat Apr  1 10:24:47 2017 BENKRIZI El harag
## Last update Tue Apr 14 08:58:20 2017 BENKRIZI El harag
##

CC	=	gcc -W -Wall -Werror -Wextra
NAME	=	my_ftl
SRC	=	air_shed.c \
		attack.c \
		attackEnemy.c \
		chanceEnemy.c \
		container.c \
		detect.c \
		gameplay.c \
		main.c \
		my_put_nbr.c \
		my_string.c \
		readLine.c \
		system_control.c \
		system_repair.c
OBJ	=	$(SRC:%.c=%.o)
RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC)	$(OBJ)	-o	$(NAME)
		$(RM)	$(OBJ)
all:	$(NAME)

clean:
	$(RM)	$(OBJ)

fclean:		clean
	$(RM)	$(NAME)
re:	fclean	all
