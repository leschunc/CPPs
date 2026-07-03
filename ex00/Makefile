NAME	= Zombie
COMP	= c++
SRCS	= main.cpp Zombie.cpp
SRCS	+= newZombie.cpp randomChump.cpp
FLAGS	= -Wall -Wextra -Werror -std=c++98
# OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): 
	$(COMP) $(SRCS) $(FLAGS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re