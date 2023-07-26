NAME= bsq
CFLAGS= -Wall -Wextra -Werror

$(NAME): main.o my_lib2.o my_lib.o my_basic_functions2.o my_basic_functions.o
	cc $(CFLAGS) main.o my_lib2.o my_lib.o my_basic_functions2.o my_basic_functions.o -o $(NAME)

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)