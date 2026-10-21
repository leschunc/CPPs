NAME        := btc
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS        := main.cpp BitcoinExchange.cpp
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
	rm -f run.sh

run.sh:
	echo 'valgrind ./btc "$$@"' > run.sh
	chmod +x run.sh

g: re run.sh
	@read args; \
	if [ -z "$$args" ]; then \
		args="data.csv"; \
	fi; \
	./run.sh "$$args"
	make fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re g