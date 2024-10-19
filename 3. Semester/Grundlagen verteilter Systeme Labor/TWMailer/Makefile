# Makefile for TW-Mailer Client and Server

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O2

# Executable names
CLIENT_EXEC = twmailer-client
SERVER_EXEC = twmailer-server

# Source files
CLIENT_SRC = client.cpp
SERVER_SRC = server.cpp

# Default target
all: $(CLIENT_EXEC) $(SERVER_EXEC)

# Build the client executable
$(CLIENT_EXEC): $(CLIENT_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build the server executable
$(SERVER_EXEC): $(SERVER_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean up build artifacts
clean:
	rm -f $(CLIENT_EXEC) $(SERVER_EXEC) *.o

.PHONY: all clean
