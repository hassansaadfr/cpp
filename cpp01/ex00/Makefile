CC		=	clang++

NAME	=	BraiiiiiiinnnzzzZ

HEAD	=	-I srcs

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp \
			Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp

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
