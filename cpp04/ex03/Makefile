CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  ICharacter.cpp  IMateriaSource.cpp  main.cpp  MateriaSource.cpp


NAME = Interface

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all