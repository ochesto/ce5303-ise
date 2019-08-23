
CC = gcc
AR = ar
RV = rv
RANLIB = ranlib
LD = ld

LIB_NAME = operaciones
SRC_LIB = $(LIB_NAME).c
OBJ_LIB = $(LIB_NAME).o

STATIC_LIB = lib$(LIB_NAME).a
DYNAMIC_LIB = lib$(LIB_NAME).so

all: $(STATIC_LIB) $(DYNAMIC_LIB)

$(STATIC_LIB): $(OBJ_LIB)
		$(AR) $(RV) $(STATIC_LIB) $(OBJ_LIB)
		$(RANLIB) $(STATIC_LIB)

$(DYNAMIC_LIB): $(OBJ_LIB)
		$(LD) -o $(DYNAMIC_LIB) $(OBJ_LIB) -shared

$(OBJ_LIB): $(SRC_LIB)
		$(CC) -c $(SRC_LIB)

clean: 
		rm $(OBJ_LIB)
		rm $(STATIC_LIB)
		rm $(DYNAMIC_LIB)
