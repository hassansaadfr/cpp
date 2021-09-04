CC		=	clang++

NAME	=	a.out

HEAD	=	-I srcs

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	$(wildcard srcs/*.cpp)

OBJS	=	${SRCS:.cpp=.o}

$(NAME)	:	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all		:	$(NAME)

clean	:
			@rm -f $(OBJS)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
