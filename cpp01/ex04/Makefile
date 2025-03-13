BLUE = \e[1;034m
ORANGE = \033[1;38;5;208m
GREY = \033[0;37m
GREEN = \e[0;32m
MGT = \033[1;35m
RED = \e[0;31m
CYAN = \e[1;36m
RESET = \e[0m

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = file_manipulation

CC = c++ -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJS)
	
	@$(CC) $(OBJS) -o $(NAME) > /dev/null 2>&1
	@echo "$(GREEN)[✔] Sed is for losers ready $(RESET)"

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