NAME		:= bureaucrat

SRCS_DIR	:= srcs/
OBJS_DIR	:= objs/
INCS_DIR	:= incs/

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -I$(INCS_DIR)

FILES		:= main Bureaucrat AForm ShrubberyCreationForm
SRCS		:= $(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(FILES)))
OBJS		:= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)
DEPS		:= $(OBJS:$(OBJS_DIR)%.o=$(OBJS_DIR)%.d)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MP

-include $(DEPS)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re