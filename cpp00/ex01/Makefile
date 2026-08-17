NAME	= MyAwesomePhoneBook
CXX		= c++
FLAGS	= -Wall -Wextra -std=c++98
FLAGS	+= -Werror

FILES	= phoneBook contact main
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