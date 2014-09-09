PREFIX := ../
USER_MARCOS := #_FILE_OFFSET_BITS=64 _LARGEFILE_SOURCE

CPPFLAGS := -Wall -Werror -g -fPIC -std=c++11
CC = g++

INSTALL := cp -p

MAIN := main

OBJS := main.o
all: $(MAIN)

%.o:%.cpp
	$(CC) $(CPPFLAGS) $(addprefix -D,$(USER_MARCOS))   -c $< -o $@

$(MAIN): main.o

clean:
	rm -f *.o
	rm -f $(MAIN)
