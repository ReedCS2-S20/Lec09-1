CXX=g++
CXX_FLAGS=-g -std=c++11
.PHONY: all clean
TARGETS=test_cmpx

all: $(TARGETS)


Cmpx.o: Cmpx.hh
Cmpx.o: Cmpx.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

test_cmpx.o: Cmpx.hh
test_cmpx.o: test_cmpx.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

test_cmpx: test_cmpx.o Cmpx.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

