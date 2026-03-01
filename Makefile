MYCC		= clang++
MYCC		= g++

CF_DEPS		= -MMD -MP
CF_INCL		=
#CF_OPTIM	= -O30 -g
CF_OPTIM	= -O3 -g
CF_OPTIM	+= -mavx -msse4.2 -maes -mpclmul
CF_WARN		= -Wall -Wextra -Wpedantic -Wdeprecated -Wconversion -Wno-unknown-warning-option -Wno-stringop-truncation

CF_ALL		= -std=c++17	\
			$(CF_DEPS)	\
			$(CF_INCL)	\
			$(CF_OPTIM)	\
			$(CF_WARN)

CXX		= $(MYCC) -c $(CF_ALL)

LINK		= $(MYCC) -o $@ $^ -lstdc++



TARGETS		= main_map main_set

all: 	$(TARGETS)

clean:
	rm -f	\
		*.o	\
		*.d	\
		$(TARGETS)

.PHONY: all clean

-include $(wildcard *.d)



main_map.o: main_map.cc
	$(CXX) $<

main_set.o: main_set.cc
	$(CXX) $<

main_map: main_map.o
	$(LINK)

main_set: main_set.o
	$(LINK)

