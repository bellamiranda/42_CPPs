GREEN = \033[1;32m
YELLOW = \033[1;38;5;220m
ORANGE = \033[1;38;5;208m
RED = \033[31;1m
MGT = \033[1;35m
CYAN = \e[1;36m
BLUE = \e[1;034m
GREY = \033[0;37m
RESET = \e[0m

SRCS = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = Unnecessary_violence

CC = c++ -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJS)
	
	@$(CC) $(OBJS) -o $(NAME) > /dev/null 2>&1
	@echo "$(GREEN)[✔] Unnecessary violence ready $(RESET)"

$(OBJS): %.o: %.cpp	
	@$(CC) -c $< -o $@ > /dev/null 2>&1

clean:
	@rm -f $(OBJS) > /dev/null 2>&1
	@echo "$(ORANGE)[✔] Cleaning $(RESET) "

fclean: clean
	@rm -f $(NAME) > /dev/null 2>&1
	@echo "$(RED)[✔] Full cleaning $(RESET) "

re: fclean all

.PHONY: all clean fclean re
#> /dev/null 2>&1