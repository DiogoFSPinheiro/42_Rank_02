MAKEFLAGS += -s

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = free_funcs.c push.c swap.c rotate.c reverse_rotate.c verify_args.c utils.c orderthree.c mega_sort.c movements.c main.c ready_a.c ready_b.c push_swap.c 

LIBFT = ./libft/libft.a
PRINTF = ./printf/ft_printf.a

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
RESET 		= \033[0m

#BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)
#BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME) 

$(NAME): $(LIBFT) $(PRINTF) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created"
	@echo "/###### /##           /##       /##                               /##"
	@echo "|_  ##_/| ##          | ##      |__/                              | ##"
	@echo "  | ## /######        | ##       /## /##    /## /######   /#######| ##"
	@echo "  | ##|_  ##_/        | ##      | ##|  ##  /##//##__  ## /##_____/| ##"
	@echo "  | ##  | ##          | ##      | ## \  ##/##/| ########|  ###### |__"
	@echo "  | ##  | ## /##      | ##      | ##  \  ###/ | ##_____/ \____ ##"
	@echo "/######|  ####/       | ########| ##   \  #/  |  ####### /######/ /##"
	@echo "|______/ \___/        |________/|__/    \_/    \_______/|_______/ |__$(RESET)"

#bonus: $(BONUS_OBJS) $(OBJS)
#	ar rc $(NAME) $(BONUS_OBJS) $(OBJS)  mete no clean -> $(BONUS_OBJS)

clean:
	rm -rf $(OBJS) 
	@echo "$(YELLOW)Removing $(NAME) objects files$(RESET)" 
	cd libft && make clean
	cd printf && make clean

fclean: clean
	rm -rf $(NAME) 
	@echo "$(RED)Removing $(NAME) executable$(RESET)"
	cd libft && make fclean
	cd printf && make fclean

re: fclean all 

.phony: all bonus clean fclean re 

################################# Making librarys #########################
$(LIBFT):
	cd libft && make 
$(PRINTF):
	cd printf && make 

