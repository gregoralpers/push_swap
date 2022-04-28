
SRCS	= ${wildcard *.c}
PSSRCS	= ../error_check.c ../push.c ../rmoves.c ../rrmoves.c ../smoves.c ../stack_initiation.c ../stack_calc.c ../stack_functions.c
NAME	= checker
CC	= gcc
FLAGS	= -Wall -Werror -Wextra
RM	= rm -f
INCS	= ../includes
LIBFT	= -L ../libft -lft

${NAME}: runlibft
	${CC} ${FLAGS} -I ${INCS} ${LIBFT} ${SRCS} ${PSSRCS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${NAME}

fclean: clean
	make -C .. fclean

re: fclean all

runlibft:
	make -C ../libft

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean
