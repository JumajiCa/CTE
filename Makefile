
CC = gcc
# CFLGAS = -std=c++2a -Wall
CFLAGS = -std=c99 -Wall
LDFLAGS = 

SRC := $(wildcard src/*.c) 
OBJS := $(SRC:%.c=%.o) 
BIN = bin

.PHONY: all clean 

all: clean dir libs main 

check: 
	@echo $(OBJS) 

dir: 
	@echo "Creating Bin Directory. " 
	mkdir -p $(BIN) 

libs:  
 
%.o: %.c
	@echo "Creating Object. " # This Just Prints Out The Contents Inside Of teh Quotations. 
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS) # This Is The Decrypted Interpretation Of This. 

main: $(OBJS) 
	@echo "Creating The Main Executable. " 
	$(CC) -o $(BIN)/main $^ $(LDFLAGS) 

run: all 
	$(BIN)/main 

clean: 
	@echo "Cleaning Up Everything. " 
	rm -rvf src/*.o ${BINS} 

