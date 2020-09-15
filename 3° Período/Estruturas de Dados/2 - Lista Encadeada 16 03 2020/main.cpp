#include <iostream>

using namespace std;

template<class T>
void clamp(T &value, T upperBoundary, T lowerBoundary){
    if(value < lowerBoundary){
        value = lowerBoundary;
    }
    if(value > upperBoundary){
        value = upperBoundary;
    }
}

template<class T>
struct ChainedListItem {
    T value;
    ChainedListItem* next;
};

template<class T>
struct ChainedList {
    private:
    ChainedListItem <T>* start = nullptr;

    // Adiciona um valor à um contâiner
    ChainedListItem <T>* AddToItem(T paramValue, ChainedListItem <T>* paramNext){
        ChainedListItem <T>* newItem = new ChainedListItem <T>;
        newItem->value = paramValue;
        newItem->next = paramNext;
        return newItem;
    }

    // Pega o ponteiro que aponta para a última posição
    ChainedListItem <T>* GetPointerToEnd(){
        ChainedListItem <T>* navigator = start;
        // Percorre todos os valores e checa se não é nulo
        while(navigator->next != nullptr){
            navigator = navigator->next;
        }
        return navigator;
    }

    public:
    // Insere no final
    void Append(T paramValue){
        ChainedListItem <T>* newItem = AddToItem(paramValue, nullptr);
        ChainedListItem <T>* lastPosition = nullptr;
        if(start != nullptr) {
            lastPosition = GetPointerToEnd();
            lastPosition->next = newItem;
        } else {
            start = newItem;
        }
    }

    // Imprime o vetor
    void Print(){
        if(this->start != nullptr){
            ChainedListItem <T>* navigator = start;
            while(navigator != nullptr){
                cout << navigator->value << " ";
                navigator = navigator->next;
            }
            cout << endl;
        } else {
            cout << "<empty>" << endl;
        }
    }

    // Pega um determinado elemento
    T At(int index){
        clamp(index, this->GetSize(), 0);
        ChainedListItem <T>* item = start;
        int cont = 0;
        while(cont < index){
            item = item->next;
            cont ++;
        }
        return item->value;
    }

    // Pega o tamanho da lista
    int GetSize(){
        int sizeCount = 0;
        ChainedListItem <T>* navigator = start;
        while(navigator != nullptr){
            navigator = navigator->next;
            sizeCount++;
        }
        return sizeCount;
    }

    // Inserir no começo
    void Shove(T paramValue){
        ChainedListItem <T>* newItem = AddToItem(paramValue, start);
        start = newItem;
    }

    // Inserir em qualquer posição
    void Insert(T paramValue, int index){
        if(index <= 0){
            this->Shove(paramValue);
        } else if(index >= this->GetSize()) {
            this->Append(paramValue);
        } else {
            // Pega a referência do item passado
            int cont = 0;
            ChainedListItem <T>* preNavigator = start;
            while(cont < index - 1){
                preNavigator = preNavigator->next;
                cont++;
            }

            // Pega a referência do próprio item
            cont = 0;
            ChainedListItem <T>* referenceAtIndex = start;
            while(cont < index){
                referenceAtIndex = referenceAtIndex->next;
                cont++;
            }

            // O novo item aponta para o próximo item
            ChainedListItem <T>* newItem = AddToItem(paramValue, referenceAtIndex);

            // O item passado do novo item aponta para o novo item
            preNavigator->next = newItem;
        }
    }

    // Deletar um elemento no índice
    void Delete(int index){
        if(index <= 0){
            start = start->next;
        } else {
            // Pega a referência do item passado
            int cont = 0;
            ChainedListItem <T>* preNavigator = start;
            while(cont < index - 1){
                preNavigator = preNavigator->next;
                cont++;
            }

            // Pega a referência do próximo item
            cont = 0;
            ChainedListItem <T>* postNavigator = start;
            while(cont < index + 1){
                postNavigator = postNavigator->next;
                cont++;
            }

            // Faz o item antigo apontar para o novo
            preNavigator->next = postNavigator;
        }
    }
};

int main() {
    ChainedList <int> myList;
    myList.Append(4);
    myList.Append(2);
    myList.Append(8);
    myList.Append(65);
    myList.Insert(32, 2);
    myList.Print();
    myList.Delete(2);
    myList.Print();

    return 0;
}
