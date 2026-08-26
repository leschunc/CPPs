NAME	= animals
CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

FILES	= main Animal Cat Dog
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

mute:
	@rm -f $(NAME) $(OBJS)

go: re
	clear
	./$(NAME)
	@$(MAKE) --no-print-directory mute

.PHONY: all clean fclean re mute go