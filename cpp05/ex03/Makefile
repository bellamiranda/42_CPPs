GREEN = \033[1;32m
YELLOW = \033[1;38;5;220m
ORANGE = \033[1;38;5;208m
RED = \033[31;1m
MGT = \033[1;35m
CYAN = \e[1;36m
BLUE = \e[1;034m
GREY = \033[0;37m
RESET = \e[0m

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = ex03

CC = c++ -Wall -Wextra -Werror -std=c++98 -g -Wshadow

all: $(NAME)

$(NAME): $(OBJS)
	
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[✔] At least this beats coffee-making ready $(RESET)"

$(OBJS): %.o: %.cpp	
	@$(CC) -c $< -o $@ 

clean:
	@rm -f $(OBJS)
	@echo "$(ORANGE)[✔] Cleaning $(RESET) "

fclean: clean
	@rm -f $(NAME) 
	@rm -f *_shrubbery
	@echo "$(RED)[✔] Full cleaning $(RESET) "

re: fclean all

.PHONY: all clean fclean re
# > /dev/null 2>&1