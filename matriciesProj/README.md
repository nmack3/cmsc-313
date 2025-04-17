AUTHORING: NATHAN MACK - cmsc 313 - 4.16.25
PURPOSE OF SOFTWARE: These are two different pieces of code that both accomplish the same purpose of doing basic matrix operations in both c and cpp
FILES: 
the .cpp and .hpp code is for the cpp portion of the code
the .c and .h are for the c portion
additionally the c code is named _b i.e. mainb or matrixb to distinguish it further
there is no make file


BUILD INSTRUCTIONS: 
gcc for cpp files: g++ -std=c++11 -Wall -Wextra main.cpp Matrix.cpp -o matrix_cpp
run: ./matrix_cpp

gcc for c files: gcc -std=c99 -Wall -Wextra main.c matrix.c -o matrix_c
run: ./matrix_c

shouuld work fine

TESTING METHODOLOGY: I just included an example like the function we were supposed to complete, implementing more should work fine.

ADDITIONAL INFORMATION: i included screenshots of the run code in each version with the pdf submission
