NAME = life
SOURCES = main.c 
CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)


$(NAME) :
	cc $(SOURCES) -o $(NAME)

clean : 
	rm -rf  *.o
fclean : clean
	rm $(NAME)

re : fclean all

valgrind : re
	valgrind ./$(NAME)

.PHONY : all clean fclean re valgrind
