g++ -c -o build/Logger.o Logger/Logger.cpp
g++ -c -o build/Operation.o Model/Operation.cpp
g++ -c -o build/Constants.o Gals/Constants.cpp
g++ -c -o build/Lexico.o Gals/Lexico.cpp
g++ -c -o build/Sintatico.o Gals/Sintatico.cpp
g++ -c -o build/Semantico.o Gals/Semantico.cpp
g++ -c -o build/Main.o Main.cpp
cd build
g++ -o cp2.exe *.o
cd ..
