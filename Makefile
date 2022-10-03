NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

HEADER_SRCS	=	pipex.h 
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

FUNC_SRCS	=	ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c 
FUNC_DIR	=	functions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		=	$(FUNC:.c=.o)

SPATH_SRCS	=	check.c deallocate.c pipex.c processes.c
SPATH_DIR	=	sources/
SPATH		=	$(addprefix $(SPATH_DIR), $(SPATH_SRCS))
OBJ_S		=	$(SPATH:.c=.o)

%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_S)
				@$(CC) $(OBJ_F) $(OBJ_S) -o $(NAME)
				@echo "$(YELLOW)$(NAME) created$(DEFAULT)"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_S)
				@$(RM) $(OBJ_F)
				@echo "$(YELLOW)object files deleted$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(YELLOW)all deleted$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean re

YELLOW = \033[1;33m
DEFAULT = \033[0m
