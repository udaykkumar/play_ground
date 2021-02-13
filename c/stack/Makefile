AR=ar
CC=gcc
CFLAGS=-c -fPIC -Wall  -g

INC= -I ./public/inc
LIB= ./out/libstack.a

SRC     := $(shell find src -type f -name *.c)
OBJ     := $(patsubst src/%,obj/%,$(SRC:.c=.o))

TESTSRC := $(shell find test -type f -name *.c)
TESTOBJ := $(patsubst test/%,obj/%,$(TESTSRC:.c=.o))

SH_LIB_FLAGS= -shared 
ST_LIB_FLAGS= rcs 

SHAREDLIB=out/libstack.so
STATICLIB=out/libstack.a
TEST_EXE=out/stack


all: $(SHAREDLIB) $(STATICLIB) $(TEST_EXE)

$(STATICLIB): $(OBJ) 
	mkdir -p out
	$(AR) $(ST_LIB_FLAGS) $@ $^

$(SHAREDLIB): $(OBJ) 
	mkdir -p out
	$(CC) $(SH_LIB_FLAGS) -o $@ $^

$(OBJ): $(SRC) 
	mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(TEST_EXE): $(TESTOBJ)
	mkdir -p obj
	$(CC) -o $@ $< $(LIB)
	$(TEST_EXE)

$(TESTOBJ): $(TESTSRC) 
	mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean: 
	rm -rf *.o *.a *.so $(TEST_EXE)
	rm -rf obj/* lib/* out/* out obj


