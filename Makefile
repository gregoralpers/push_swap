SRCS	= ${wildcard *.c}
NAME	= push_swap
CC	= gcc
FLAGS	= -Wall -Werror -Wextra -fsanitize=address -g
RM	= rm -f
INCS	= includes
LIBFT	= libft/libft.a 
CHECK	= ./tests/checker_OS

${NAME}: runlibft
	${CC} ${FLAGS} -I ${INCS} ${LIBFT} ${SRCS} -o ${NAME}

ignore: runlibft
	${CC} -I ${INCS} ${LIBFT} ${SRCS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${NAME}

fclean: clean
	make -C libft fclean

re: fclean all

runlibft:
	@cd libft && make all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS}

.PHONY: all re clean fclean
