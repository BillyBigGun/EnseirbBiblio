CXX = g++
CXXFLAGS = -c -Wall
SRC = main.cpp media.cpp CD.cpp DVD.cpp magazine.cpp VHS.cpp digitalRessources.cpp book.cpp commandManager.cpp mediatheque.cpp user.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = program

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
