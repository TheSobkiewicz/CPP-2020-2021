EXEC=main
ALLSRC=*.cpp
CXXFLAGS=-std=c++14 -Wall -g 
# mozna dodac powyzej  --pednatic

$(EXEC): $(ALLSRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

run:
	clear
	./$(EXEC)


clean:
	rm -f $(EXEC) *.o
