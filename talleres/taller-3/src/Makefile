
CC = gcc

SRC = calculadora.c
LIB_NAME = operaciones

BIN_PATH = ../bin
LIB_PATH = ../lib
INCLUDE_PATH = ../include

STATIC_APP = calculadora_e
DYNAMIC_APP = calculadora_d

all: $(STATIC_APP) $(DYNAMIC_APP)

$(STATIC_APP): $(SRC)
		$(CC) $(SRC) -L$(LIB_PATH) -I$(INCLUDE_PATH) -o $(BIN_PATH)/$(STATIC_APP) -static -l$(LIB_NAME)

$(DYNAMIC_APP): $(SRC)
		$(CC) $(SRC) -L$(LIB_PATH) -I$(INCLUDE_PATH) -o $(BIN_PATH)/$(DYNAMIC_APP) -Bdynamic -l$(LIB_NAME)

clean:
		rm $(BIN_PATH)/$(STATIC_APP)
		rm $(BIN_PATH)/$(DYNAMIC_APP)
