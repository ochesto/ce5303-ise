CC = g++
SRC = test_fsm_coffee.cpp
INCLUDE_SYSTEM_C = /opt/systemc/include/
LIB_SYSTEM_C = /opt/systemc/lib-linux64/
LIB = systemc
OUTPUT = coffee-machine

LINK_LIB = -I$(INCLUDE_SYSTEM_C) -L$(LIB_SYSTEM_C)
FLAGS = $(LINK_LIB) -l$(LIB) -lm -std=c++98

all: $(OUTPUT)

$(OUTPUT): $(SRC)
		$(CC) $(FLAGS) -o $(OUTPUT) $(SRC)

clean:
		rm $(OUTPUT)
		rm coffee-machine.vcd