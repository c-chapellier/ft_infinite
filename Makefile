SRCS =	main.c \
		core/reallocbi.c \
		core/freebi.c \
		core/cleanbi.c \
		core/swapbi.c \
		core/deepbi.c \
		converters/atobi.c \
		operators/arithmetic/addbi.c \
		operators/arithmetic/subbi.c \
		operators/arithmetic/mulbi.c \
		operators/arithmetic/divbi.c \
		operators/relationals.c \
		operators/logicals.c \
		operators/bitwises.c \
		io/printbi.c \
		debug/print_uint8.c \

OBJS = ${SRCS:.c=.o}

NAME = ft_infinite

# CFLAGS		= -Wall -Wextra -Werror

all :		${NAME}

${NAME} :	${OBJS}
			gcc -o ${NAME} ${OBJS}

test :		${NAME}
			bash test.sh

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all