NAME		= bureaucrat
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			  RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Bureaucrat/Forms compiled - 42 Madrid - ismherna"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
