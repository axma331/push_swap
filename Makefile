PUSH_SWAP	= push_swap
CHECKER		= checker

CC		= gcc
RM		= rm -rf
# ERFLG	= -fsanitize=address
CFLAGS	= -Wall -Wextra -Werror -g $(ERFLG)

LIBFT	= -L ./libft -lft
HEDER	= *.h

# SRC	:= $(wildcard *.c)
SRC		=	sorting_functions_1.c	sorting_functions_2.c \
			cheking_and_search.c	parser_functions.c	node_functions.c 
PS_SRC	=	$(SRC)	basic_sorting_algorithm_1.c	basic_sorting_algorithm_2.c \
					basic_sorting_functions_1.c	basic_sorting_functions_2.c	push_swap.c
CH_SRC	=	$(SRC)	checker.c

OBJDIR	= .obj
PS_OBJ	= $(PS_SRC:%.c=$(OBJDIR)/%.o)
CH_OBJ	= $(CH_SRC:%.c=$(OBJDIR)/%.o)

DEPDIR	= .dep
DEPFILES = $(PS_SRC:%.c=$(DEPDIR)/%.d) $(CH_SRC:%.c=$(DEPDIR)/%.d)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d


all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(PS_OBJ) $(HEDER)
	@echo "$(CLRCY)Подключение$(CLRPR)$(LIBFT)$(CLRRS)"
	@$(CC) $(CFLAGS) $(LIBFT) $(PS_OBJ) -o $@
	@echo "$(CLRCY)Создан$(CLREL)$@$(CLRRS)"

$(CHECKER): $(CH_OBJ) $(HEDER)
	@echo "$(CLRCY)Подключение$(CLRPR)$(LIBFT)$(CLRRS)"
	@$(CC) $(CFLAGS) $(LIBFT) $(CH_OBJ) -o $@
	@echo "$(CLRCY)Создан$(CLREL)$@$(CLRRS)"
	
$(OBJDIR)/%.o: %.c | $(OBJDIR) $(DEPDIR)
	@$(MAKE) -C ./libft
	@echo "$(CLRCY)Создан$(CLRGR)$@$(CLRRS)"
	@$(CC) -c $(CFLAGS) $(DEPFLAGS) -o $@ $<

$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

$(DEPFILES):
include $(wildcard $(DEPFILES))

re:
	@$(MAKE) fclean
	@$(MAKE) all

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJDIR) $(DEPDIR)
	@echo "$(CLRCY)Очистка$(CLRRE)$(OBJDIR)$(DEPDIR)$(CLRRS)"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(PUSH_SWAP) $(CHECKER)
	@echo "$(CLRCY)Удаление$(CLRRE)$(PUSH_SWAP)$(CLRRS)"

gitpush: fclean
	git add *.c *.h Makefile libft/
	git commit -m "New edition"
	git push

.PHONY: all clean fclean re

#-c говорит не запускать линкер, потому что нет main
#-g порождает отладочную информацию в родном формате операционной системы
#включает использование дополнительной отладочной информации, 
#которую может использовать только GDB; 
#эта дополнительная отладочная информация делает работу отладки в GDB лучше, но может, 
#вероятно испортить работу других отладчиков, или помешать им прочитать программу.

CLRRS = \033[0m #сброс цвета
BOLDf = \033[1m #жирный шрифт
UNDRL = \033[4m #подчеркивание
FONGR = \033[47m #серый цвет фона
CLRGR = \033[37m #серый цвет шрифта
FONCY = \033[46m #цвет морской волны фона		
CLRCY = \033[36m #цвет морской волны шрифта
FONPR = \033[45m #фиолетовый цвет фона
CLRPR = \033[35m #фиолетовый цвет шрифта
FONBL = \033[44m #синий цвет фона
CLRBL = \033[34m #синий цвет шрифта
FONEL = \033[43m #желтый цвет фона
CLREL = \033[33m #желтый цвет шрифта
FONGR = \033[42m #зелёный цвет фона
CLRGR = \033[32m #зелёный цвет шрифта
FONRE = \033[41m #красный цвет фона
CLRRE = \033[31m #красный цвет шрифта
FONBC = \033[40m #чёрный цвет фона
CLRBC = \033[30m #чёрный цвет шрифта
#COLOR+FON = \033[6;35m - можно совмещать \033[6 - цвет шрифта ;35m - цвет фона