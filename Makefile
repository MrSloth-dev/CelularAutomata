NAME = life high brian
SOURCES = main.c utils.c
CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)


life :
	cc $(SOURCES) gameoflife.c -o life

high :
	cc $(SOURCES) high.c -o high

brian :
	cc $(SOURCES) brian.c -o brian

clean : 
	rm -rf  *.o
fclean : clean
	rm $(NAME)

re : fclean all

valgrind : re
	valgrind ./$(NAME)

.PHONY : all clean fclean re valgrind
