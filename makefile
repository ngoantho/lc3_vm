OUT := .
DEBUG = 0

FLAGS = -Wall -pedantic -std=c++17
ifeq ($(DEBUG), 1)
	FLAGS += -g
endif

.PHONY: run clean debug
all: main-build post-build

pre-build:
	@mkdir -p $(OUT)

main-build: pre-build
	g++ $(FLAGS) -c *.cpp
	g++ $(FLAGS) *.o

post-build:
ifneq ($(OUT), .)
	@mv *.o a.out $(OUT)
endif

run: all
		$(OUT)/a.out

debug:
	make DEBUG=1

clean:
	@rm $(OUT)/*.o
	@rm $(OUT)/a.out
