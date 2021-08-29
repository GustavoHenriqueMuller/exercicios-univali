#include <circList.h>

int main() {
    circList <int> myList;

    // Teste das operações
    std::cout << "Append (insercao no final) e Shove (insercao no inicio): " << std::endl;
    myList.Append(4);
    myList.Append(8);
    myList.Append(12);
    myList.Shove(500);
    myList.Print(); std::cout << std::endl;

    std::cout << "Insert (insercao em um indice): " << std::endl;
    myList.Insert(123, 2);
    myList.Print(); std::cout << std::endl;

    std::cout << "Delete (deleta o valor em um indice): " << std::endl;
    myList.Delete(4);
    myList.Print(); std::cout << std::endl;

    std::cout << "Tamanho da lista: " << myList.Length() << std::endl;
    std::cout << "Elemento na posicao 3: " << myList.At(3) << std::endl << std::endl;

    return 0;
}
