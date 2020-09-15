#ifndef CIRCLIST_H
#define CIRCLIST_H

#include <iostream>

template<class T>
T clamped(T &value, T lowerBoundary, T upperBoundary){
    if(value < lowerBoundary){
        value = lowerBoundary;
    } else if(value > upperBoundary){
        value = upperBoundary;
    }
    return value;
}

template<class T>
struct circListItem{
    T value;
    circListItem <T>* prev;
    circListItem <T>* next;
};

template<class T>
struct circList{
    private:
    circListItem <T>* start = nullptr;
    circListItem <T>* end = start;

    // Adiciona um item à um contâiner
    circListItem <T>* AddToItem(T paramValue, circListItem <T>* paramPrev, circListItem <T>* paramNext){
        circListItem <T>* newItem = new circListItem <T>;
        newItem->value = paramValue;
        newItem->prev = paramPrev;
        newItem->next = paramNext;
        return newItem;
    }

    public:
    // Insere no final
    void Append(T paramValue){
        if(this->start == nullptr){
            circListItem <T>* newItem = this->AddToItem(paramValue, nullptr, nullptr);
            this->start = newItem;
            this->end = newItem;
            newItem->next = newItem;
            newItem->prev = newItem;
        } else {
            circListItem <T>* newItem = this->AddToItem(paramValue, this->end, nullptr);
            this->end->next = newItem;
            this->end = newItem;

            // Faz o círculo "fechar"
            this->end->next = this->start;
            this->start->prev = this->end;
        }
    }

    // Insere no início
    void Shove(T paramValue){
        if(this->start == nullptr){
            this->Append(paramValue);
        } else {
            circListItem <T>* newItem = this->AddToItem(paramValue, nullptr, this->start);
            this->start->prev = newItem;
            this->start = newItem;

            // Faz o círculo "fechar"
            this->start->prev = this->end;
            this->end->next = this->start;
        }
    }

    // Insere em um índice
    void Insert(T paramValue, int index){
        if(this->start == nullptr){
            this->Append(paramValue);
        } else {
            index = clamped(index, 0, this->Length() - 1);

            // Inserir no início
            if(index == 0){
                this->Shove(paramValue);
            // Inserir no final
            } else if(index == this->Length() - 1){
                this->Append(paramValue);
            // Inserir em outra posição
            } else {
                int cont;

                // Pega a referencia do elemento que será o elemento anterior (índice "index")
                circListItem <T>* prevItem = this->start;

                cont = 0;
                while(cont < index - 1){
                    prevItem = prevItem->next;
                    cont++;
                }

                // Pega a referencia do elemento que será o elemento posterior (índice "index")
                circListItem <T>* nextItem = this->start;

                cont = 0;
                while(cont < index){
                    nextItem = nextItem->next;
                    cont++;
                }

                // Cria o novo item
                circListItem <T>* newItem = this->AddToItem(paramValue, prevItem, nextItem);
                prevItem->next = newItem;
                nextItem->prev = newItem;
            }
        }
    }

    // Deleta um item
    void Delete(int index){
        if(this->start == nullptr){
            return;
        } else {
            index = clamped(index, 0, this->Length() - 1);
            circListItem <T>* navigator = this->start;
            int cont = 0;
            while(cont < index){
                navigator = navigator->next;
                cont++;
            }

            circListItem <T>* prevItem = navigator->prev;
            circListItem <T>* nextItem = navigator->next;

            prevItem->next = nextItem;
            nextItem->prev = prevItem;

            // Trata exceções
            if(index == 0){
                this->start = nextItem;
            }

            if(index == this->Length() - 1){
                this->end = prevItem;
            }

            delete navigator;
        }
    }

    // Imprime a lista na tela
    void Print(){
        if(this->start != nullptr){
            circListItem <T>* navigator = this->start;
            do {
                std::cout << navigator->value << " ";
                navigator = navigator->next;
            } while(navigator != this->start);
            std::cout << std::endl;
        } else {
            std::cout << "<empty>" << std::endl;
        }
    }

    // Obtem um valor na lista
    T At(int index){
        circListItem <T>* navigator = this->start;
        int cont = 0;
        while(cont < index){
            navigator = navigator->next;
            cont++;
        }
        return navigator->value;
    }

    // Obtem o tamanho da lista
    int Length(){
        circListItem <T>* navigator = this->start;
        int size = 0;
        do {
            navigator = navigator->next;
            size++;
        } while(navigator != this->start);
        return size;
    }
};

#endif // CIRCLIST_H
