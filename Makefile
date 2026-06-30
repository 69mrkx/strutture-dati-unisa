CC = gcc
CFLAGS = -Wall -I.

IMPL ?= heap
HEAP_IMPL ?= heap_tree
# Se IMPL è stack, puoi decidere quale implementazione usare
STACK_IMPL ?= stack_array
OBJS = main.o item_int.o utils.o Btree.o

# 3. LOGICA DINAMICA
# Aggiungiamo l'oggetto corretto agli OBJS in base alla macro IMPL
ifeq ($(IMPL),stack)
    OBJS += $(STACK_IMPL).o
else ifeq ($(IMPL),heap)
    OBJS += $(HEAP_IMPL).o
else
	OBJS += $(IMPL).o
endif

TARGET = main

# 4. VPATH (La vera magia)
# Diciamo a Make in quali cartelle andare a cercare i file sorgente .c
# Così non dovrai mai più specificare i percorsi a mano.
VPATH = item list stack Btree algoritmi-di-sorting heap

.PHONY: all clean

all: $(TARGET)

# Regola di linking (genera l'eseguibile)
# $@ prende il TARGET, $^ prende tutti gli OBJS
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regola generica di compilazione
# Per ogni file .o, cerca il corrispondente file .c nelle cartelle del VPATH e lo compila.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)