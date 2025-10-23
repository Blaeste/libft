NAME	= libft.a

SRCS	= ${LIBC} ${SUPP}

LIBC	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c

SUPP	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${BONUS:.c=.o}

CC		= gcc

FLAGS	= -Wall -Werror -Wextra

LIB		= ranlib

# Variables progress bar

total_files := $(words ${SRCS})
GREEN = \033[0;32m
NC = \033[0m

# Fonction progress bar

define progress_bar
	$(eval current_file := $(shell echo $$(ls -1 *.o 2>/dev/null | wc -l || echo 0)))
	$(eval percent := $(shell echo $$((100 * $(current_file) / $(total_files)))))
	$(eval progress := $(shell echo $$(($(percent) / 2))))

	@printf "\r[${GREEN}"
	@for i in $$(seq 1 $(progress)); do printf "#"; done
	@if [ $(progress) -lt 50 ]; then \
		for i in $$(seq $(progress) 50); do printf "."; done \
	fi
	@printf "${NC}] [$(percent)%%] Compiling: $(current_file)/$(total_files) 🛠️"
endef

all:		${NAME}

.c.o:
			${progress_bar}
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}
			@${LIB} ${NAME}
			${progress_bar}
			@echo "\n✅ Compilation terminee !"

bonus:		${OBJS} ${OBJS_BONUS}
			@ar rc ${NAME} ${OBJS} ${OBJS_BONUS}
			@${LIB} ${NAME}
			${progress_bar}
			@echo "\n✅ Compilation terminee !"

clean:
			@rm -f ${OBJS} ${OBJS_BONUS}
			@echo "✅ (clean) Suppression des fichiers .o !"

fclean:		clean
			@rm -f ${NAME}
			@echo "✅ (fclean) Suppression de l'Archive !"

re:			fclean all

.PHONY:		all bonus clean fclean re