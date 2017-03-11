CC=g++
DEBUG=-g
CPPFLAGS+=-std=c++11

SRCS=$(wildcard *.cpp)
HDRS=$(wildcard *.hpp)

OBJS=$(SRCS:%.cpp=%.o)

DEPS=$(SRCS:%.cpp=%.d)

game: $(OBJS)	
	$(CC) $(CPPFLAGS) $^ -o game

-include $(DEPS)

%.d: $(SRCS)
	@set -e; rm -f $@; \
	$(CC) -MM -MD -MP -E $< -o $@;	

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) game
