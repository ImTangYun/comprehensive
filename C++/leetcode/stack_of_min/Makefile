PREFIX := ./
LIB := -Wl,-rpath,/opt/apps/gcc-4.7.3/lib64,-rpath,/opt/apps/gcc-4.7.3/lib -lrt
USER_MARCOS := _FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE

CPPFLAGS := -Wall -Werror -g -fPIC -std=c++11
CC = g++

INSTALL := cp -p

MAIN := main

OBJS := main.o stack_of_min.o
all: $(MAIN) 

%.o:%.cpp
	$(CC) $(CPPFLAGS) $(addprefix -D,$(USER_MARCOS)) $(addprefix -I,$(INCS)) -c $< -o $@
$(MAIN): main.o stack_of_min.o

clean:
	rm -f *.o
	rm -f $(MAIN)
