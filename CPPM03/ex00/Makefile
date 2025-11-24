NAME = claptrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SRCS = ClapTrap.cpp main.cpp
OBJS = $(OBJDIR)/ClapTrap.o $(OBJDIR)/main.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/ClapTrap.o: $(SRCDIR)/ClapTrap.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/ClapTrap.cpp -o $(OBJDIR)/ClapTrap.o

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re