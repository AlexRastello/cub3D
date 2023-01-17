SRCS	=	get_next_line.c \
			get_next_line_utils.c 

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

NAME	= libgnl.a

LIB		= gnl

.c.o:
	@gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	@ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
	@${RM} ${OBJS}

fclean:	clean
	@${RM} ${NAME}

re:	fclean all

.PHONY: all clean flcean re