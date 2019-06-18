##
## EPITECH PROJECT, 2018
## Fairefichier
## File description:
## This is a fairefichier
##

ECHO		=	/bin/echo -e
DEFAULT		=	"\e[0m"
BOLD_T		=	"\e[1m"
DIM_T		=	"\e[2m"
UNDLN_T		=	"\e[4m"
BLACK_C		=	"\e[30m"
RED_C		=	"\e[31m"
GREEN_C		=	"\e[32m"
YELLO_C		=	"\e[33m"
BLUE_C		=	"\e[34m"
MAGEN_C		=	"\e[35m"
CYAN_C		=	"\e[36m"
DEFAULT_C	=	"\e[39m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

NAME			=	chainmy
COLOR_THEME		=	$(YELLO_C)
DEBUG_THEME     =	$(CYAN_C)
INCLUDE_PATH	=	../include

SRC			=	my_chained/link_push.c \
				my_chained/link_pop.c \
				my_vector/vector_push.c \
				my_vector/vector_pop.c
TEST_SRC	=	tests/test_link_create.c \
				tests/test_link_push_after.c \
				tests/test_link_push_before.c \
				tests/test_link_pop_me.c \
				tests/test_vector_create.c \
				tests/test_vector_push_back.c \
				tests/test_vector_push_top.c \
				tests/test_vector_pop_me.c

CFLAGS		=	-Wall \
				-Wextra \
				-I $(INCLUDE_PATH)

TEST_FLAGS 	=	-lcriterion \
				-L . -l $(NAME) \
				$(CFLAGS)

DEBUG_FLAGS	=	-g3 -gdwarf-4

SRCS		=	$(SRC:%=%)
TEST_SRCS	=	$(TEST_SRC:%=%)

OBJ			=	$(SRCS:.c=.o)
TEST_OBJ 	=	$(TEST_SRCS:.c=.o)

all:	message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  _________   ___ ___    _____  .___ _______                   " $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  \_   ___ \ /   |   \  /  _  \ |   |\      \     _____ ___.__." $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  /    \  \//    ~    \/  /_\  \|   |/   |   \   /     <   |  |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"  \     \___\    Y    /    |    \   /    |    \ |  Y Y  \___  |" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"   \______  /\___|_  /\____|__  /___\____|__  / |__|_|  / ____|" $(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"          \/       \/         \/            \/        \/\/     " $(DEFAULT)
	@$(LINE_RETURN)

$(NAME):	$(OBJ)
	@ar rc ./lib$(NAME).a $(OBJ) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "lib$(NAME).a" $(DEFAULT) "\n" || \
		$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "lib$(NAME).a"$(DEFAULT) "\n"

clean:
	@$(RM) $(OBJ)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"lib$(NAME)'s object files"$(DEFAULT)

fclean:	clean
	@$(RM) ./lib$(NAME).a
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary lib$(NAME).a"$(DEFAULT)

re:	fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(DEBUG_THEME)
debug: fclean all

test_build:	fclean test_clean all $(TEST_OBJ)
	@$(CC) -o test_run $(TEST_OBJ) $(TEST_FLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] TEST COMPILATION SUCCESSFUL\n" $(DEFAULT) || \
		$(ECHO) $(RED_C)$(BOLD_T)"\n[✘] "$(UNDLN_T)"TEST COMPILATION FAILED" $(DEFAULT) "\n"

test_exec:
	@$(ECHO) -n $(BOLD_T)$(LIGHT_GREEN) "   Test lib" $(NAME) ": " $(DEFAULT)
	@./test_run

test_clean:
	@$(RM) $(TEST_OBJ)
	@$(RM) ./test_run
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"tests object files"$(DEFAULT)

test_run: test_build test_exec

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)$(BOLD_T)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all $(NAME) message clean fclean re debug test_build test_clean test_run
