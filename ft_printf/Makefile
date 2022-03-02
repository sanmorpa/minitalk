SRCS	=	ft_printf.c ft_putchar_fd.c ft_strlen.c ft_toupper.c ft_itoa.c \
ft_copy.c ft_tohex.c ft_tohex_ptr.c ft_check.c ft_putstr_fd.c

NAME	=	libftprintf.a

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}

.PHONY:		all clean fclean re bonus
