NAME = bsp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SRCS = Fixed.cpp Point.cpp bsp.cpp main.cpp
OBJS = $(OBJDIR)/Fixed.o $(OBJDIR)/Point.o $(OBJDIR)/bsp.o $(OBJDIR)/main.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/Fixed.o: $(SRCDIR)/Fixed.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Fixed.cpp -o $(OBJDIR)/Fixed.o

$(OBJDIR)/Point.o: $(SRCDIR)/Point.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/Point.cpp -o $(OBJDIR)/Point.o

$(OBJDIR)/bsp.o: $(SRCDIR)/bsp.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/bsp.cpp -o $(OBJDIR)/bsp.o

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