NAME := philo

SHELL := /bin/bash
CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -Wshadow -MMD -MP
INCLUDES := -I./includes


SRCDIR := srcs
OBJDIR := objs
SRCFILE := $(shell find $(SRCDIR) -name "*.cpp" -type f)
OBJS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.cpp=.o))
DEPS = $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCFILE:.cpp=.d))

# ==== Path to makefile for google test ==== #
GTESTDIR := googletest

# ==== Align length to format compile message ==== #
ALIGN := $(shell tr ' ' '\n' <<<"$(SRCFILE)" | while read line; do echo \
	$$((`echo $$line | wc -m`)); done | awk 'm<$$1{ m=$$1} END{print m}')

all: $(NAME)
-include $(DEPS)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ $(INCLUDES) -o $@
	@echo -e "flags  : $(YLW)$(CXXFLAGS)$(NC)\nbuild  : $(GRN)$^$(NC)\n=> $(BLU)$@$(NC)" 

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)/$(*D)
	@$(CXX) $(CXXFLAGS) -c $< $(INCLUDES) -o $@
	@echo -e "compile: $(MGN)$<$(NC)\
	$$(yes ' ' | head -n $$(expr $(ALIGN) - $$((`echo $< | wc -m` - 1))) | tr -d '\n') -> \
	$(GRN)$@$(NC)"

debug: CXXFLAGS += -g -fsanitize=integer -fsanitize=address -DDEBUG
debug: re

test: $(filter-out %main.o,$(OBJS))
	$(MAKE) -C $(GTESTDIR) 

.PHONY: ref
ref:
	cd ref && ./make_ref.sh

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) $(NAME) std

re: fclean
	$(MAKE) all

run: all
	./$(NAME)

.PHONY: all clean fclean re debug test cmp run

# ==== Color define ==== #
YLW := \033[33m
GRN := \033[32m
YLW := \033[33m
BLU := \033[34m
MGN := \033[35m
CYN := \033[36m
NC := \033[m

# ==== suggest 'j' option of make command ==== #
ifeq ($(shell uname), Linux)
	procs := $$(expr $$(grep cpu.cores /proc/cpuinfo | sort -u | sed 's/[^0-9]//g') + 1)
else
	procs := $$(expr $$(system_profiler SPHardwareDataType | grep Total | sed 's/[^0-9]//g') + 1)
endif

.PHONY: proc
proc:
	@echo -e "please do $(CYN)export MAKEFLAGS=-j$(procs)$(NC)"
