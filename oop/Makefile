CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
SRCS = main.cpp Pessoa.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
