SHOW	= 0
SRCS	= ${wildcard *.c}
NAME	= push_swap
CC	= gcc
FLAGS	= -Wall -Werror -Wextra -fsanitize=address -D SHOW=${SHOW}
RM	= rm -f
INCS	= libft/includes
LIBFT	= -Llibft -lft
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
	make -C libft

run_checker:
	ARG=${GEN}; ./push_swap $$ARG | ${CHECK} $$ARG 

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean
