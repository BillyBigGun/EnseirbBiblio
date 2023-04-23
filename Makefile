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
