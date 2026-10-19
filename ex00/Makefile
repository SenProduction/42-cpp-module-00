NAME := megaphone
CPPC := c++
CPPFLAGS := -Wall -Wextra -Werror
CPPVER := -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CPPC) $(CPPFLAGS) $(CPPVER) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPPC) $(CPPFLAGS) $(CPPVER) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all
