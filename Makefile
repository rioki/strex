
CXX 		?= g++
CXXFLAGS 	?= -g -Wall -W -ansi # -pedantic
CXXFLAGS 	+= -Iinclude -Iinclude/strex

.PHONY: clean test
.SUFFIXES: .o .cpp

all: lib/libstrex.a

src 		= src/files.cpp \
			  src/strings.cpp
test_src 	= test/main.cpp \
			  test/test_compose.cpp \
			  test/test_lexical_cast.cpp \
			  test/test_strings.cpp
	
ifeq ($(MSYSTEM), MINGW32)
  EXEEXT=*.exe
endif

objs = $(patsubst %.cpp, %.o, $(src))
test_objs = $(patsubst %.cpp, %.o, $(test_src))
deps = $(subst .o,.d,$(objs))
test_deps = $(subst .o,.d,$(test_objs))

lib/libstrex.a: $(objs) 
	@echo Creating $@ library...
	@$(AR) crf $@ $^
	
bin/strextest: $(test_objs) lib/libstrex.a
	@echo Linking $@ 
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -lUnitTest++ -Llib -lstrex  -o $@

clean: 
	rm -f */*.o */*.d lib/libstrex.a bin/strextest$(EXEEXT)

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