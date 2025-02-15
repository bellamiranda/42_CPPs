SRCS = srcs/main.cpp srcs/PhoneBook.cpp srcs/Contact.cpp srcs/PhoneBookUtils.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re