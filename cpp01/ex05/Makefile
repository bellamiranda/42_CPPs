BLUE = \e[1;034m
ORANGE = \033[1;38;5;208m
GREY = \033[0;37m
GREEN = \e[0;32m
MGT = \033[1;35m
RED = \e[0;31m
CYAN = \e[1;36m
RESET = \e[0m

SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = harl

CC = c++ -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJS)
	
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[✔] Harl 2.0 ready $(RESET)"

$(OBJS): %.o: %.cpp	
	@$(CC) -c $< -o $@ 

clean:
	@rm -f $(OBJS)
	@echo "$(ORANGE)[✔] Cleaning $(RESET) "

fclean: clean
	@rm -f $(NAME) 
	@echo "$(RED)[✔] Full cleaning $(RESET) "

re: fclean all

.PHONY: all clean fclean re
# > /dev/null 2>&1