CXX = g++
LDFLAGS = -lGL -lGLEW -lglfw -lGLU

SRC = main.cpp \
      graphics/window.cpp

OUT = app

all:$(OUT)
$(OUT): $(SRC)
	$(CXX) $(SRC) -o $(OUT) $(LDFLAGS)
clean:
	rm -f $(OUT)
run: $(OUT)
	./$(OUT)