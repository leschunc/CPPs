NAME	= Zombie
SRCS	= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 $(SRCS) -o $(NAME)


# clean:
# 	rm -r $(OBJS) 
	
# fclean:
# 	rm -r $(NAME) $(OBJS)

# re: fclean all

PHONY: all clean fclean re