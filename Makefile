NAME = libasm.a

CC = nasm
FLAGS = -felf64
# ELF64 (Executable and Linkable Format) object files

SRC = ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s \
	ft_write.s \
	ft_read.s \
	ft_strdup.s

SRC_BONUS = ft_atoi_base_bonus.s \
			ft_list_push_front_bonus.s \
			ft_list_size_bonus.s \
			ft_list_sort_bonus.s \
			ft_list_remove_if_bonus.s

OBJ_FILES = $(SRC:.s=.o)
OBJ_BONUS_FILES = $(SRC_BONUS:.s=.o)

ifdef WITH_BONUS
OBJ = $(OBJ_FILES) $(OBJ_BONUS_FILES)
else
OBJ = $(OBJ_FILES)
endif

all: $(NAME)

$(NAME): $(OBJ)
	ar rsc $@ $(OBJ)
	ranlib $@

%.o: %.s
	$(CC) $(FLAGS) $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJ_FILES) $(OBJ_BONUS_FILES)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

run: all
	gcc main.c -L. -lasm
	./a.out

.PHONY: all clean fclean re run
