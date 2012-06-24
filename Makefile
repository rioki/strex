
VERSION	     = 0.1.0
CXX 		?= g++ -std=c++0x
CXXFLAGS 	?= -g -Wall 
CXXFLAGS 	:= -I. $(CXXFLAGS)
prefix      ?= /usr/local

strex_hdr	= strex/files.h \
			  strex/strings.h

strex_src   = strex/files.cpp \
			  strex/strings.cpp
			  
test_src 	= test/main.cpp \
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

.PHONY: all check clean install uninstall dist
.SUFFIXES: .o .cpp

all: strex$(LIBEXT)

check: test$(EXEEXT)
	./test$(EXEEXT)

clean: 
	rm -f */*.o */*.d strex$(LIBEXT) libstrex.a test$(EXEEXT) 	
	
install:
	mkdir -p $(prefix)/include/strex
	mkdir -p $(prefix)/bin
	mkdir -p $(prefix)/lib
	cp $(strex_hdr) $(prefix)/include/strex
	cp strex$(LIBEXT) $(prefix)/bin
	cp libstrex.a $(prefix)/lib

uninstall:
	echo TODO

dist:
	echo TODO

strex$(LIBEXT): $(patsubst %.cpp, %.o, $(strex_src))
	$(CXX) -shared -fPIC $(LDFLAGS) -Wl,--out-implib=$(patsubst %$(LIBEXT),lib%.a, $@) $^ -o $@
	
test$(EXEEXT): strex$(LIBEXT) $(patsubst %.cpp, %.o, $(test_src)) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(test_libs) -o $@
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MD -c $< -o $(patsubst %.cpp, %.o, $<)	

ifneq "$(MAKECMDGOALS)" "clean"
deps  = $(patsubst %.cpp, %.d, $(src))
deps  = $(patsubst %.cpp, %.d, $(test_src))
-include $(deps)
endif
