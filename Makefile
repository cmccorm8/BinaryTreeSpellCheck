#####################################
# Makefile
#####################################
CXXFLAGS=-ggdb -Wall -Wno-sign-compare
CXX=g++ 

main: main.cpp timer.h BinaryNode.h BinaryTree.h BinaryTree.cpp 
	$(CXX) $(CXXFLAGS) main.cpp BinaryTree.cpp -o spellcheck

tidy :
	/bin/rm -f a.out core.*

clean : tidy
	/bin/rm -f spellcheck 
    