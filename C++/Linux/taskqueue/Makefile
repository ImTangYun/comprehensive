PREFIX := ../
LIB :=  -lpthread
INCS := $(PREFIX)extern_include

CPPFLAGS := -Wall -Werror -g -fPIC -std=c++11
CC = g++

INSTALL := cp -p

MAIN := main

OBJS := main.o 
all: $(MAIN)

%.o:%.cpp
	$(CC) $(CPPFLAGS) $(addprefix -D,$(USER_MARCOS)) $(addprefix -I,$(INCS))  -c $< -o $@

$(MAIN): main.o  $(LIB)


clean:
	rm -f *.o
	rm -f $(MAIN)
