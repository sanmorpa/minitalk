SRCS_CL	=	client.c

NAME_CL	=	client

OBJS_CL	=	${SRCS_CL:.c=.o}

SRCS_SR	=	server.c

NAME_SR	=	server

OBJS_SR	=	${SRCS_SR:.c=.o}

DIRLIB =  ./ft_printf/libftprintf.a

MAKELIB = cd ./ft_printf/ && ${MAKE}

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc

RM		=	rm -f

all:		${NAME_CL} ${NAME_SR}

${NAME_SR}: ${OBJS_SR}
			${MAKELIB}
			${CC} ${CFLAGS} -o ${NAME_SR} ${OBJS_SR} ${DIRLIB}

${NAME_CL}:	${OBJS_CL}
			${MAKELIB}
			${CC} ${CFLAGS} -o ${NAME_CL} ${OBJS_CL} ${DIRLIB}

clean:
			${RM} ${OBJS_CL}
			${RM} ${OBJS_SR}
			${MAKELIB} clean

fclean:		clean
			${RM} ${NAME_CL}
			${RM} ${NAME_SR}
			${MAKELIB} fclean

re:			fclean ${NAME_CL} ${NAME_SR}
			${MAKELIB} re

.PHONY:		all clean fclean re
