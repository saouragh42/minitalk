NAME_CLIENT			=	client
NAME_SERVER			=	server

# Directories
LIBFT				=	./libft/libft.a
FT_PRINTF			=	./ft_printf/libftprintf.a
INC					=	include/
SRC_DIR				=	srcs/
OBJ_DIR				=	obj/

# Compiler and CFlags
CC 					=	cc
CFLAGS				=	-Wall -Werror -Wextra -g

# Sources
SRC_CLIENT_FILES	=	client.c
SRC_SERVER_FILES	=	server.c

SRCS_CLIENT			= $(addprefix $(SRC_DIR), $(SRC_CLIENT_FILES))
SRCS_SERVER			= $(addprefix $(SRC_DIR), $(SRC_SERVER_FILES))
OBJ_CLIENT			= $(SRCS_CLIENT:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJ_SERVER			= $(SRCS_SERVER:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Build rules 
all:			$(LIBFT) $(FT_PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
					@echo "Building libft..."
					@make -s -C ./libft

$(FT_PRINTF):
					@echo "Building ft_printf..."
					@make -s -C ./ft_printf

$(NAME_CLIENT):		$(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF)
					@echo "Building $(NAME_CLIENT)..."
					@$(CC) $(CFLAGS) -I $(INC) $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT)
					@echo "client built successfully"

$(NAME_SERVER):		$(OBJ_SERVER) $(LIBFT) $(FT_PRINTF)
					@echo "Building $(NAME_SERVER)..."
					@$(CC) $(CFLAGS) -I $(INC) $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER)
					@echo "server built successfully"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) -I $(INC) -I ./ft_printf -c $< -o $@

clean:
				@echo "Cleaning up..."
				@rm -rf $(OBJ_DIR)
				@make -s clean -C ./libft
				@make -s clean -C ./ft_printf
				@echo "Cleaned successfully"

fclean:			clean
				@echo "Removing executables..."
				@rm -f $(NAME_CLIENT) $(NAME_SERVER)
				@rm -f $(LIBFT) $(FT_PRINTF)
				@echo "Executables removed"

re:				fclean all

.PHONY:			all clean fclean re
