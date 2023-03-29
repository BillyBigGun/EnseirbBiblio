CXX = g++
CXXFLAGS = -c -Wall
INCLUDES = -I include -I include/commands -I include/media
SRC = main.cpp media.cpp CD.cpp DVD.cpp magazine.cpp VHS.cpp digitalRessources.cpp book.cpp commandManager.cpp mediatheque.cpp user.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = program

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(INCLUDES) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(INCLUDES) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
