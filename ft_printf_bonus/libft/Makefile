# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igncipri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 21:27:51 by igncipri          #+#    #+#              #
#    Updated: 2023/01/14 14:58:24 by igncipri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

NAME = libft.a
BONUS = bonus
MY = my

###### VARIABLE ######

SOURCE =	ft_memset.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strmapi.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

		
OBJECTS = ${SOURCE:.c=.o}

BONUSSOURCE =	ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstadd_front.c \
				ft_lstadd_back.c \
				ft_lstsize.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstlast.c

BONUSOBJECT = ${BONUSSOURCE:.c=.o}

MYSOURCE =	ft_free.c \
			ft_strjoinevo.c \
			ft_strlcpyevo.c \
			ft_itoa_base.c \
			ft_utoa.c \
			ft_utohex_up.c \
			ft_utohex.c \
			ft_utoa_base.c \
			ft_ptrtoa.c

MYOBJECT = ${MYSOURCE:.c=.o}

CC = gcc
AR = ar -rsv
REMOVECOMMAND = rm -f
CFALGS = -Wall -Wextra -Werror

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

.c.o:
	${CC} ${CFALGS} -c $< -o $@

####### RULES ########

all: ${NAME}

${NAME}: ${OBJECTS} ${BONUS} ${MY}
	@echo "===++== CREATE/UPDATE ARCHIVE ==++=="
	${AR} ${NAME} ${OBJECTS}
	@echo ""

${BONUS}: ${BONUSOBJECT}
	@echo "===++== ADD BONUS IN ARCHIVE ==++==="
	${AR} ${NAME} ${BONUSOBJECT}
	@echo ""

${MY}: ${MYOBJECT}
	@echo "===++== ADD MY IN ARCHIVE ==++==="
	${AR} ${NAME} ${MYOBJECT}
	@echo ""

clean:
	@echo "====++=== CLEAN ALL OBJECTS ===++==="
	${REMOVECOMMAND} ${OBJECTS} ${BONUSOBJECT} ${MYOBJECT}
	@echo ""

fclean: clean
	@echo "====++==== DELETE ARCHIVE ====++===="
	${REMOVECOMMAND} ${NAME}
	@echo ""
	@echo "====++==== ==++==++==++== ====++===="

re: fclean all

#debug: ${OBJECTS}
#	@${CC} ${CFALGS} ${OBJECTS} -o ${NAME} -g
#	lldb ${NAME}
#
#	ar -crs ${NAME} ${OBJECTS}

#.c.o:
#	@${CC} ${CFALGS} -c $< -o ${<:.c=.o}

.PHONY: all clean fclean re .c.o debug marchive
.SUFFIXES: .c .o 
