NAME = libft.a
SRCS_DIR = src/
OBJS_DIR = obj/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lbsd -I./includes

FT_DIR = ft_is ft_mem ft_puts ft_str ft_to

FT_ISDIR = ft_is/
FT_IS = ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint

FT_MEMDIR = ft_mem/
FT_MEM = ft_bzero ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset

FT_PUTSDIR = ft_puts/
FT_PUTS = ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FT_STRDIR = ft_str/
FT_STR = ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr

FT_TODIR = ft_to/
FT_TO = ft_atoi ft_itoa ft_tolower ft_toupper


SRC_FILES+=$(addprefix $(FT_ISDIR), $(FT_IS))
SRC_FILES+=$(addprefix $(FT_MEMDIR), $(FT_MEM))
SRC_FILES+=$(addprefix $(FT_PUTSDIR), $(FT_PUTS))
SRC_FILES+=$(addprefix $(FT_STRDIR), $(FT_STR))
SRC_FILES+=$(addprefix $(FT_TODIR), $(FT_TO))

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
