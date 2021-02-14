AR			= ar
CFLAGS      = -c -Wall -std=c++11 -g -fPIC -fprofile-arcs -ftest-coverage
LDFLAGS     = -static -lgcov --coverage

ProblemSources     := $(shell find src -name '*.cxx' )
LibHeaders 	   := $(shell find src -name '*.hxx' )
LibObjects     := $(notdir $(ProblemSources:.cxx=.o) )

TestSources     := $(shell find  test -name '*.cxx' )
TestObjects     := $(notdir $(TestSources:.cxx=.o))
TestHeaders		 = -I ./public/inc
TestHeaders		+= -I ./deps/boost_1_68_0/

TestLibs 		= -L ./deps/boost_1_68_0/stage/lib -lboost_unit_test_framework
TestLibs 		+= -L ./lib -lsolutions


LibStatic  = libsolutions.a
TestBin    = solutionsBin

all: $(LibStatic) 

$(LibStatic): ${LibObjects}
	$(AR) -rcs -o $@ $^

$(LibObjects): $(ProblemSources)
	$(CXX) $(CFLAGS) $^	



test: all stage $(TestBin) run

$(TestObjects): $(TestSources)
	$(CXX) $(TestHeaders) $(CFLAGS) $^	

$(TestBin): $(TestObjects)
	$(CXX) -o $@ $^ $(LDFLAGS) $(TestLibs)

run:
	./${TestBin}

clean:
	rm -rf *.o *.so *.a public lib $(TestBin) *.gcno *.gcda

stage: 
	mkdir -p public/inc lib
	cp -rf $(LibHeaders) public/inc
	cp -rf $(LibDynamic) $(LibStatic) lib
