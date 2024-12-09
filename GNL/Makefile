# Nombre del compilador
CC = gcc

# Opciones del compilador
CFLAGS = -Wall -Wextra -Werror

# Nombre del ejecutable
NAME = get_next_line

# Archivos fuente
SRCS = get_next_line.c get_next_line_utils.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Regla por defecto
all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(OBJS)
    $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Regla para compilar archivos .c en archivos .o
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar archivos objeto y el ejecutable
clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(NAME)

# Regla para recompilar todo
re: fclean all

.PHONY: all clean fclean re