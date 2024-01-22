NAME = push_swap

NAME_BONUS = checker

PUSHSWAP = push_swap.a

CHECKER = checker.a

FILES = ps_src/actions.c \
ps_src/actions2.c \
ps_src/algorithm.c \
ps_src/assign_index.c \
ps_src/check_order_and_order_a.c \
ps_src/check.c \
ps_src/cost.c \
ps_src/initialize.c \
ps_src/push_swap.c \
ps_src/push.c \
ps_src/reverse_rotate.c \
ps_src/rotate.c \
ps_src/select_algorithm.c \
ps_src/swap.c 

FILES_BONUS = ck_src/checker.c

OBJECTS = $(FILES:.c=.o)

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

FLAGS = -Werror -Wall -Wextra

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME):			$(OBJECTS) $(LIBFT)
						@ ar rcs $(PUSHSWAP) $(OBJECTS)
						@ gcc $(FLAGS) $(PUSHSWAP) $(LIBFT) -o $(NAME)

$(OBJECTS):			ps_src/%.o : ps_src/%.c 
						@ gcc $(FLAGS) -c $< -o $@

$(OBJECTS_BONUS):	ck_src/%.o : ck_src/%.c 
						@ gcc $(FLAGS) -c $< -o $@

$(LIBFT):
						@ make -s -C ./libft

all: 				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME_BONUS): 		$(OBJECTS_BONUS) $(OBJECTS) $(LIBFT)
						@ ar rcs $(CHECKER) $(OBJECTS_BONUS) $(OBJECTS)
						@ gcc $(FLAGS) $(CHECKER) $(LIBFT) -o $(NAME_BONUS)

clean:
						@ rm -f $(OBJECTS) $(OBJECTS_BONUS)
						@ make clean -s -C ./libft

fclean:
						@ rm -f $(NAME_BONUS) $(NAME) $(OBJECTS) $(OBJECTS_BONUS) $(PUSHSWAP) $(CHECKER) $(LIBFT)
						@ make fclean -s -C ./libft

re: fclean all

.PHONY: all re clean fclean bonus
