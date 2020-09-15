#include <iostream>

using namespace std;

template <class T, int size>
struct StaticList {
    T values[size];
    int currentSize = 0;

    // Checa se a lista está vazia.
    bool Empty() {
        return currentSize == 0;
    }

    // Limita um valor entre um mínimo e máximo.
    void Clamp(int &value, int min, int max) {
        if(value < min) {
            value = min;
        }
        if(value > max) {
            value = max;
        }
    }

    // Insere no final.
    void Append(T data) {
        if(currentSize < size) {
            values[currentSize] = data;
            currentSize++;
        }
    }

    // Insere em uma posição, fazendo um deslocamento.
    void Insert(T data, int index) {
        // Limita o índice.
        Clamp(index, 0, currentSize);

        if(currentSize < size) {
            // Move todos os elementos à direita.
            for(int i = currentSize; i > index; i--) {
                values[i] = values[i-1];
            }

            // Atribui o elemento na posição.
            values[index] = data;
            currentSize++;
        }
    }

    // Mostra todos os elementos da lista estática.
    void Print() {
        cout << "Size: " << size << " | {";
        for(int i = 0; i < currentSize; i++) {
            cout << values[i];

            if(i < currentSize - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }

    // Deleta uma posição;
    void Delete(int index) {
        // Limita o índice.
        Clamp(index, 0, currentSize);

        if(!Empty()) {
            // Dá swap nos elementos de uma posição para a outra.
            for(int i = index; i < currentSize; i++) {
                values[i] = values[i+1];
            }

            currentSize--;
        }
    }

    // Checa se um valor existe na lista.
    bool Has(T value) {
        for(int i = 0; i < currentSize; i++) {
            if(values[i] == value) {
                return true;
            }
        }

        return false;
    }

    // Pega o valor de uma posição.
    T GetValue(int index) {
        // Limita o índice.
        Clamp(index, 0, currentSize);
        return values[index];
    }

    // Pega o elemento de uma posição como um ponteiro.
    T* GetElement(int index) {
        // Limita o índice.
        Clamp(index, 0, currentSize);
        return values[index];
    }
};

int main() {
    return 0;
}
