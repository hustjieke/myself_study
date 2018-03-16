CXXFLAGS=-O0 -g -Wall -fmessage-length=0 -Iperson_job -Iinclude
CXX=g++

LIB+=-L/usr/local/lib

SRCS=$(wildcard ./src/*.cpp) 

#DIR=$(notdir $(SRCS))

OBJS=$(patsubst %.cpp,%.o,$(SRCS))

EXEC=app

$(EXEC):$(OBJS)
	$(CXX) -o $@ $^  $(LIB)
	@echo "---------OK--------"
	@echo "---------OK--------"
	@echo "---------OK--------"

.cpp.o:
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -f  $(OBJS)


