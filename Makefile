NAME		=	test.out
BONUS		= 	test_bonus.out
CC			?=	clang
CFLAGS		=	-Wall -Wextra -Werror

###################
BUFFER_SIZE = 	16
###################
SAMPLE = sample1.txt
###################
SAMPLE_BONUS = sample1.txt sample2.txt sample3.txt
##################

all:
	$(CC) $(CFLAGS) get_next_line.c get_next_line_utils.c test_gnl.c -D BUFFER_SIZE=$(BUFFER_SIZE) -o $(NAME)

test: all
	./$(NAME) $(SAMPLE) | cat -e 

bonus:
	$(CC) $(CFLAGS) get_next_line_bonus.c get_next_line_utils_bonus.c test_gnl_bonus.c -D BUFFER_SIZE=$(BUFFER_SIZE) -o $(BONUS)
	./$(BONUS) $(SAMPLE_BONUS)

stdi:
	$(CC) $(CFLAGS) get_next_line.c get_next_line_utils.c test_gnl_stdi.c -D BUFFER_SIZE=$(BUFFER_SIZE) -o $(NAME)
	./$(NAME)

clean:
	rm -rf *.obj
	
fclean: clean
	rm -rf *.out

re: fclean all