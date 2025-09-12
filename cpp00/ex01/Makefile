CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Contact.cpp main.cpp PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

NAME = PhoneBook

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
