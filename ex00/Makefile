NAME	= BraiiiiiiinnnzzzZ
CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

FILES	= main Zombie newZombie randomChump
SRCS	= $(addsuffix .cpp, $(FILES))

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re