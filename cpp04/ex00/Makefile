CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Animal.cpp  Cat.cpp  Dog.cpp  main.cpp

SRC_TEST = WrongTest/WrongAnimal.cpp  WrongTest/WrongCat.cpp  WrongTest/WrongMain.cpp

NAME_WRONG = WrongAnimal
NAME = Animal

OBJ = $(SRC:.cpp=.o)
OBJ_TEST = $(SRC_TEST:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

wrong: $(NAME_WRONG)

$(NAME_WRONG): $(OBJ_TEST)
	$(CXX) $(CXXFLAGS) $(OBJ_TEST) -o $(NAME_WRONG)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_TEST)

fclean: clean
	rm -f $(NAME) $(NAME_WRONG)

re: fclean all