TARGET = password-checker
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRCS = main.cpp password_utils.cpp terminal_io.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)