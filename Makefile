CXX = g++
CXXFLAGS = -std=c++20 -Wall -c
LXXFLAGS = -std=c++20 
OBJECTS =  main.o   puzzle.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)  
main.o:  main.cpp  	puzzle.h
	$(CXX) $(CXXFLAGS) main.cpp   
puzzle.o:  puzzle.cpp  	
	$(CXX) $(CXXFLAGS) puzzle.cpp   
clean:
	rm -fv $(TARGET) $(OBJECTS)




