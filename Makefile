NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	ft_decto_hex.c \
					ft_putstr.c \
					ft_print_adress.c \
					ft_print_unsigned.c \
					ft_itoa.c \
					ft_calloc.c \
					ft_bzero.c \
					ft_printf.c \

OBJS			=	$(SRCS:%.c=%.o)


CYAN = \033[0;96m
YELLOW = \033[0;93m
GREEN = \033[0;92m
RED = \033[0;91m
GRAY = \033[0;90m
RESET = \033[0m

all:				$(NAME) $(SRCS)


$(NAME):			$(OBJS)
					ar -rcs $(NAME) $(OBJS)
					@echo "\n$(GREEN)LIBFTPRINTF.A DONE !\n"


clean: 
					@echo "$(GRAY)Cleaning library..."
					rm -f $(OBJS)

					@echo "\n $(CYAN)Library cleaned ! \n"

fclean:				clean
					rm -f $(NAME)
					@echo "\n $(CYAN)Library fcleaned ! \n"


re:					fclean all

.PHONY:				all clean fclean re 