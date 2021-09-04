CC		=	clang++

NAME	=	megaphone

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRCS	=	megaphone.cpp

OBJS	=	${addprefix srcs/,${SRCS:.cpp=.o}}

$(NAME)	:	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all		:	$(NAME)

clean	:
			@rm -f $(OBJS)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
