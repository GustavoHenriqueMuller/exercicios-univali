#include <iostream>

using namespace std;

struct varT{
    int integer;
    bool boolean;
    char character;
    float floatingPoint;
    double doublePoint;
};
struct varTPointer{
    int* integer;
    bool* boolean;
    char* character;
    float* floatingPoint;
    double* doublePoint;
};

void printTypeSizes(){
    cout << "int: \t\t" << sizeof(int) << " bytes" << endl;
    cout << "bool: \t\t" << sizeof(bool) << " bytes" << endl;
    cout << "float: \t\t" << sizeof(float) << " bytes" << endl;
    cout << "double: \t\t" << sizeof(double) << " bytes" << endl;
    cout << "char: \t\t" << sizeof(char) << " bytes" << endl;

    cout << endl;
}
void printTypeSizesPointer(){
    cout << "int: \t\t" << sizeof(int*) << " bytes" << endl;
    cout << "bool: \t\t" << sizeof(bool*) << " bytes" << endl;
    cout << "float: \t\t" << sizeof(float*) << " bytes" << endl;
    cout << "double: \t\t" << sizeof(double*) << " bytes" << endl;
    cout << "char: \t\t" << sizeof(char*) << " bytes" << endl;

    cout << endl;
}
void printSizeOfTADS(){
    varT variousTypesInstance;
    varTPointer variousTypesPointerInstance;
    varT* variousTypesPointer;
    varTPointer* variousTypesPointerPointer;

    cout << "variousTypes (INSTANCE): \t\t" << sizeof(variousTypesInstance) << " bytes" << endl;
    cout << "variousTypesPointer (INSTANCE): \t\t" << sizeof(variousTypesPointerInstance) << " bytes" << endl;
    cout << "variousTypes (POINTER): \t\t" << sizeof(variousTypesPointer) << " bytes" << endl;
    cout << "variousTypesPointer (POINTER): \t\t" << sizeof(variousTypesPointerPointer) << " bytes" << endl;

    cout << endl;
}

int main() {
    printTypeSizes();
    printTypeSizesPointer();
    printSizeOfTADS();
    return 0;
}
