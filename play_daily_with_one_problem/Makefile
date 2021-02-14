SOURCES 		:= $(shell find src -name '*.cpp')
TEST_SOURCES 	:= $(shell find tests -name '*.cpp')

INC_PATH		:= -I ./src
INC_PATH		+= -I ./deps/boost_1_68_0/

LIBS            := -L ./deps/boost_1_68_0/stage/lib -lboost_unit_test_framework
OBJECTS     	:= $(notdir $(SOURCES:.cpp=.o))
TEST_OBJECTS	:= $(notdir $(TEST_SOURCES:.cpp=.o))

PROGRM 	 		:= "daily-problem-test"

CFLAGS		= -Wall -std=c++17 -g -c
DEBUGFlags 	= -DDEBUG
LDFLAGS		= -static

all: $(PROGRM) #test


$(PROGRM): ${TEST_OBJECTS} ${OBJECTS}
	@printf "\t\t[LINK] $(TEST_EXE)\n"
	@$(CXX) -o $@ $^ ${LIB_PATH} ${LDFLAGS} ${LIBS}

$(OBJECTS): $(SOURCES)
	@printf "\t\t[C] Objects\n"
	@$(CXX) $(CFLAGS) $(INC_PATH) $(CFLAGS) $^	

$(TEST_OBJECTS): $(TEST_SOURCES)
	@printf "\t\t[C] Test Objects\n"
	@$(CXX) $(CFLAGS) $(INC_PATH) $(CFLAGS) $^	

test:
	./$(PROGRM)

clean:
	@printf "\t[CLEAN] ...\n"
	@rm -f $(PROGRM) ${TEST_OBJECTS} ${OBJECTS} *.o
