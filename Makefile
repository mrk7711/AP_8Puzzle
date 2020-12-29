CXX = g++
CXXFLAGS = -std=c++20 -Wall  -O3 -c 
LXXFLAGS = -std=c++20  -ltbb
OBJECTS =  main.o   puzzle.o   bfs.o   dfs.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)  
main.o:  main.cpp  	puzzle.h   bfs.h   dfs.h
	$(CXX) $(CXXFLAGS) main.cpp   
puzzle.o:  puzzle.cpp  	
	$(CXX) $(CXXFLAGS) puzzle.cpp   
bfs.o:  bfs.cpp  	
	$(CXX) $(CXXFLAGS) bfs.cpp   
dfs.o:  dfs.cpp  	
	$(CXX) $(CXXFLAGS) dfs.cpp   
clean:
	rm -fv $(TARGET) $(OBJECTS)




