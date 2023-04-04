# CXX = g++
# CXXFLAGS = -c -Wall
# INCLUDES = -I include -I include/commands -I include/media
# SRC = main.cpp media.cpp CD.cpp DVD.cpp magazine.cpp VHS.cpp digitalRessources.cpp book.cpp mediatheque.cpp user.cpp command.cpp commandManager.cpp addCommand.cpp
# OBJ = $(SRC:.cpp=.o)
# EXEC = program

# all: $(EXEC)

# $(EXEC): $(OBJ)
# 	$(CXX) $(INCLUDES) $(OBJ) -o $(EXEC)

# %.o: %.cpp
# 	$(CXX) $(INCLUDES) -c $(CXXFLAGS) $< -o $@

# clean:
# 	rm -f $(OBJ) $(EXEC)

CC = g++
CFLAGS = -c -Wall
LDFLAGS = 

SRC_DIRS = src src/media src/command
INC_DIRS = include include/media include/command
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/program

SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
DEPS = $(foreach dir,$(INC_DIRS),$(wildcard $(dir)/*.h))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(dir $(lastword $(subst /, ,$(dir $@)))) $< -o $@

clean:
	rm -rf $(OBJ_DIR)/* $(TARGET)

.PHONY: all clean