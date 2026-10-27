NAME := phonebook
CPPC := c++
CPPFLAGS := -Wall -Wextra -Werror
CPPVER := -std=c++98

SRCS := Contact.cpp \
        PhoneBook.cpp \
        main.cpp

OBJS := $(SRCS:.cpp=.o)

HEADERS := Contact.hpp PhoneBook.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CPPC) $(CPPFLAGS) $(CPPVER) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CPPC) $(CPPFLAGS) $(CPPVER) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all
