
CXX 		?= g++ -std=c++0x
CXXFLAGS 	?= -g -Wall 
CXXFLAGS 	+= -Iinclude -Iinclude/strex
LDFLAGS     += -Llib

strex_hdr	= 

strex_src   = src/files.cpp \
			  src/strings.cpp
test_src 	= test/main.cpp \
			  test/test_compose.cpp \
			  test/test_lexical_cast.cpp \
			  test/test_strings.cpp \
			  test/test_files.cpp
			  
test_libs   = -lUnitTest++
			  
dist_files  = $(strex_hdr) \
			  $(strex_src) \
			  $(text_src) \
			  Makefile \
			  README.md
	
ifeq ($(MSYSTEM), MINGW32)
  EXEEXT=.exe
  LIBEXT=.dll
else
  EXEEXT=
  LIBEXT=.so
endif

.PHONY: all check install uninstall dist
.SUFFIXES: .o .cpp

all: bin/strex.$(LIBEXT)

check: bin/test$(EXEEXT)
	./bin/test$(EXEEXT)

install:
	echo TODO

uninstall:
	echo TODO

dist:
	echo TODO

bin/strex$(LIBEXT): $(patsubst %.cpp, %.o, $(strex_src))
	mkdir -p bin
	mkdir -p lib
	$(CXX) -shared -fPIC $(LDFLAGS) -Wl,--out-implib=$(patsubst bin/%.$(LIBEXT),lib/lib%.a, $@) $^ -o $@
	
bin/test$(EXEEXT): bin/strex$(LIBEXT) $(patsubst %.cpp, %.o, $(test_src)) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(test_libs) -o $@

clean: 
	rm -f */*.o */*.d bin/* lib/*


	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MD -c $< -o $(patsubst %.cpp, %.o, $<)	

ifneq "$(MAKECMDGOALS)" "clean"
deps  = $(patsubst %.cpp, %.d, $(src))
deps  = $(patsubst %.cpp, %.d, $(test_src))
-include $(deps)
endif