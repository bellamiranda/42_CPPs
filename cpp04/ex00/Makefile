GREEN = \033[1;32m
YELLOW = \033[1;38;5;220m
ORANGE = \033[1;38;5;208m
RED = \033[31;1m
MGT = \033[1;35m
CYAN = \e[1;36m
BLUE = \e[1;034m
GREY = \033[0;37m
RESET = \e[0m

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Wrong.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = Polymorphism

CC = c++ -Wall -Wextra -Werror -std=c++98 -g -Wshadow

all: $(NAME)

$(NAME): $(OBJS)
	
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[✔] Polymorphism ready $(RESET)"

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