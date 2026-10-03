NAME	= bureaucrat
CXX		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

FILES	= main Bureaucrat Form
SRCS	= $(addsuffix .cpp, $(FILES))
OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(OBJS:$(OBJS_DIR)%.o=$(OBJS_DIR)%.d)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

-include $(DEPS)

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

er: re
	clear
	valgrind ./$(NAME)
	@$(MAKE) --no-print-directory mute

.PHONY: all clean fclean re mute go er
