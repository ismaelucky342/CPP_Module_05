NAME		= ex03
CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror

SRCS		= main.cpp \
			  Bureaucrat.cpp \
			  Form.cpp \
			  PresidentialPardonForm.cpp \
			  RobotomyRequestForm.cpp \
			  ShrubberyCreationForm.cpp \
			  StrToLower.cpp \
			  IntToStr.cpp \
			  Intern.cpp

OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "																													"
	@echo "	 ██████╗██████╗ ██████╗    ███╗   ███╗ ██████╗ ██████╗ ██╗   ██╗██╗     ███████╗         ██████╗ ███████╗	"
	@echo "	██╔════╝██╔══██╗██╔══██╗   ████╗ ████║██╔═══██╗██╔══██╗██║   ██║██║     ██╔════╝        ██╔═████╗██╔════╝	"
	@echo "	██║     ██████╔╝██████╔╝   ██╔████╔██║██║   ██║██║  ██║██║   ██║██║     █████╗          ██║██╔██║███████╗	"
	@echo "	██║     ██╔═══╝ ██╔═══╝    ██║╚██╔╝██║██║   ██║██║  ██║██║   ██║██║     ██╔══╝          ████╔╝██║╚════██║	"
	@echo "	╚██████╗██║     ██║███████╗██║ ╚═╝ ██║╚██████╔╝██████╔╝╚██████╔╝███████╗███████╗███████╗╚██████╔╝███████║	"
	@echo "	 ╚═════╝╚═╝     ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝╚══════╝╚══════╝ ╚═════╝ ╚══════╝	"
	@echo "																													"
	@echo "			14/11/2025 - ismherna@student.42.fr - 42 Madrid - Ismael Hernández	 "


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
