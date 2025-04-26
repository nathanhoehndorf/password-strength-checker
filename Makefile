TARGET = password-checker
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
SRCS = src/main.cpp src/password_utils.cpp src/terminal_io.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
