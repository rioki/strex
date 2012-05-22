
CXX 		?= g++
CXXFLAGS 	?= -g -Wall -W -ansi # -pedantic
CXXFLAGS 	+= -Iinclude -Iinclude/strex

.PHONY: clean test
.SUFFIXES: .o .cpp

all: lib/libstrex.a bin/strextest

src 		= src/files.cpp \
			  src/strings.cpp
test_src 	= test/main.cpp \
			  test/test_compose.cpp \
			  test_lexical_cast.cpp
	
ifeq ($(MSYSTEM), MINGW32)
  EXEEXT=*.exe
endif

objs = $(patsubst %.cpp, %.o, $(src))
test_objs = $(patsubst %.cpp, %.o, $(test_src))
deps = $(subst .o,.d,$(objs))
test_deps = $(subst .o,.d,$(test_objs))

lib/libstrex.a: src/files.o src/strings.o 
	@echo Creating $@ library...
	@$(AR) crf $@ $^
	
bin/strextest: test/main.o test/test_compose.o test/test_lexical_cast.o lib/libstrex.a
	@echo Linking $@ 
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -lUnitTest++ -Llib -lstrex  -o $@

clean: 
	rm -f src/*.o src/*.d test/*.o test/*.d lib/libstrex.a bin/strextest$(EXEEXT)

test: bin/strextest
	@echo Running unit tests.
	@./bin/strextest

%.o : %.cpp
	@echo Building $<
	@$(CXX) $(CXXFLAGS) -MD -c $< -o $(patsubst %.cpp, %.o, $<)

ifneq "$(MAKECMDGOALS)" "clean"
-include $(deps)
-include $(test_deps)
endif