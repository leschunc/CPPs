NAME	= Zombie
SRCS	= main.cpp Zombie.cpp 
# SRCS	+= newZombie.cpp randomChump.cpp
# OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): 
	c++ -Wall -Wextra -Werror -std=c++98 $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re