#include <iostream>

using namespace std;

struct Cell{
    std::string data;
};

template<int SIZE>
struct HashTable{
    Cell* table[SIZE];

    // Private Functions
    private:
    int Hash(std::string data){
        return data.size() % SIZE;
    }

    // Criar uma nova célula contendo o dado
    Cell* CreateNewCell(std::string data){
        Cell* newCell = new Cell;
        newCell->data = data;

        return newCell;
    }

    // Public Functions
    public:
    void Init(){
        for(int i = 0; i < SIZE; i++){
            table[i] = nullptr;
        }
    }

    // Inserir um elemento novo
    void Insert(std::string data){
        Cell* newCell = CreateNewCell(data);
        int index = Hash(data);

        for(index; table[index] != nullptr; index++, index %= SIZE);

        table[index] = newCell;
    }

    // Remover
    std::string Remove(std::string data){
        int index = Hash(data);

        for(index; table[index]->data != data; index++, index %= SIZE){
            if(table[index] == nullptr){
                throw "REMOVE ERROR: Elemento não está na lista.";
            }
        }

        delete table[index];
        table[index] = nullptr;

        return data;
    }

    // Pegar o elemento de índice index
    std::string Get(int index){
        if(table[index] != nullptr){
            return table[index]->data;
        } else {
            throw "GET ERROR: Posição de get está vazia.";
        }
    }

    // Pegar o índice de um elemento
    int Search(std::string data){
        int index = Hash(data);

        for(index; (table[index] != nullptr) && (table[index]->data != data); index++, index %= SIZE);

        if(table[index] != nullptr){
            return index;
        } else {
            return -1;
        }
    }

    // Imprimir a tabela hash
    void Print(){
        std::cout << "{ ";

        for(int i = 0; i < SIZE; i++){
            if(table[i] == nullptr){
                std::cout << "-";
            } else {
                std::cout << table[i]->data;
            }

            if(i < SIZE - 1){
                std::cout << ", ";
            }
        }

        std::cout << " }" << std::endl;
    }
};

int main() {
    HashTable<10> myHash;
    myHash.Init();

    return 0;
}
