CC		=	clang++

NAME	=	unnecessary_violence

HEAD	=	-I srcs

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp \
			Weapon.cpp \
			HumanA.cpp \
			HumanB.cpp

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
