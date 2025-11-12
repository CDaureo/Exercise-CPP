NAME = fixedPointNumbers

SRC = Fixed.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re