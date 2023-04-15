# all:
# 	g++ -I include -I include/commands -I include/media src/*.cpp src/media/*.cpp src/commands/*.cpp -o output

CXX = g++
CXXFLAGS = -c -Wall
INCLUDES = -I include -I include/commands -I include/media
#FILE_SRC = main.cpp media/media.cpp media/CD.cpp media/DVD.cpp media/magazine.cpp media/VHS.cpp media/digitalRessources.cpp media/book.cpp mediatheque.cpp user.cpp commands/command.cpp commands/commandManager.cpp commands/addCommand.cpp commands/byeCommand.cpp commands/clearCommand.cpp commands/deleteCommand.cpp commands/listCommand.cpp commands/loadCommand.cpp commands/resetCommand.cpp commands/saveCommand.cpp commands/searchCommand.cpp commands/showCommand.cpp
SRCDIRS = src src/media src/commands
SRC = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:src/%.cpp=%.o))
EXEC = program

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(INCLUDES) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)


########################################
# CC = g++
# CFLAGS = -c -Wall
# LDFLAGS = 

# SRC_DIRS = src src/media src/commands
# INC_DIRS = include include/media include/commands
# OBJ_DIR = obj
# BIN_DIR = obj

# TARGET = $(BIN_DIR)/program

# SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
# OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
# DEPS = $(foreach dir,$(INC_DIRS),$(wildcard $(dir)/*.h))

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CC) $(LDFLAGS) $^ -o $@

# $(OBJ_DIR)/%.o: $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
# 	mkdir -p $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -I $(dir $(lastword $(subst /, ,$(dir $@)))) $< -o $@

# god:
# 	g++ -c -Wall -I $(INC_DIRS) $(SRCS) -o $(OBJS)

# clean:
# 	rm -rf $(OBJ_DIR)/* $(TARGET)

# .PHONY: all clean



# #########################################
# # Pre-compiler and Compiler flags
# CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb
# PRE_FLAGS := -MMD -MP

# # Project directory structure
# BIN := bin
# SRC := src
# LIB := lib
# INC := include
# MAINFILE := $(SRC)/main.cpp

# # Build directories and output
# TARGET := $(BIN)/main
# BUILD := build

# # Library search directories and flags
# EXT_LIB :=
# LDFLAGS :=
# LDPATHS := $(addprefix -L,$(LIB) $(EXT_LIB))

# # Include directories
# INC_DIRS := $(INC) $(shell find $(SRC) -type d) 
# INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# # Construct build output and dependency filenames
# SRCS := $(shell find $(SRC) -name *.cpp)
# OBJS := $(subst $(SRC)/,$(BUILD)/,$(addsuffix .o,$(basename $(SRCS))))
# DEPS := $(OBJS:.o=.d)

# # Run task
# run: build
# 	@echo "🚀 Executing..."
# 	./$(TARGET) $(ARGS)

# # Build task
# build: clean all

# # Main task
# all: $(TARGET)

# # Task producing target from built files
# $(TARGET): $(OBJS)
# 	@echo "🚧 Building..."
# 	mkdir -p $(dir $@)
# 	$(CXX) $(OBJS) -o $@ $(LDPATHS) $(LDFLAGS)

# # Compile all cpp files
# $(BUILD)/%.o: $(SRC)/%.cpp
# 	mkdir -p $(dir $@)
# 	$(CXX) $(CXX_FLAGS) $(PRE_FLAGS) $(INC_FLAGS) -c -o $@ $< $(LDPATHS) $(LDFLAGS)

# # Clean task
# .PHONY: clean
# clean:
# 	@echo "🧹 Clearing..."
# 	rm -rf build

# # Include all dependencies
# -include $(DEPS)