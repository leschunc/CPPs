NAME        := stl_test
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS        := $(addsuffix .cpp, main Span)
OBJ_DIR     := objs
OBJS        := $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
MAKEFLAGS	+= -s

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

g: re
	valgrind ./$(NAME)
	make fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re g