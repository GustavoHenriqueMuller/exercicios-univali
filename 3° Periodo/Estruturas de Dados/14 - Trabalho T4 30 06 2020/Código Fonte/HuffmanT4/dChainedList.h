#ifndef DCHAINEDLIST_H
#define DCHAINEDLIST_H

#include <iostream>

using namespace std;

template<class T>
struct dChainedListItem {
    T value;
    dChainedListItem <T>* previous;
    dChainedListItem <T>* next;
};

template<class T>
struct dChainedList {
    private:
    dChainedListItem <T>* start = nullptr;
    dChainedListItem <T>* end = nullptr;

    // Adiciona um item à um contâiner
    dChainedListItem <T>* AddToItem(T paramValue, dChainedListItem <T>* paramPrevious, dChainedListItem <T>* paramNext){
        dChainedListItem <T>* newItem = new dChainedListItem <T>;
        newItem->value = paramValue;
        newItem->previous = paramPrevious;
        newItem->next = paramNext;
        return newItem;
    }

    public:
    // Insere no final
    void Append(T paramValue){
        if(Empty()){
            dChainedListItem <T>* newItem = this->AddToItem(paramValue, nullptr, nullptr);
            this->start = newItem;
            this->end = newItem;
        } else {
            dChainedListItem <T>* newItem = this->AddToItem(paramValue, this->end, nullptr);
            this->end->next = newItem;
            this->end = newItem;
        }
    }

    // Insere no início
    void Shove(T paramValue){
        if(Empty()){
            dChainedListItem <T>* newItem = this->AddToItem(paramValue, nullptr, nullptr);
            this->start = newItem;
            this->end = newItem;
        } else {
            dChainedListItem <T>* newItem = this->AddToItem(paramValue, nullptr, this->start);
            this->start->previous = newItem;
            this->start = newItem;
        }
    }

    // Insere em um índice
    void Insert(T paramValue, int index){
        if(Empty()){
            // Se estiver vazio, adiciona.
            this->Append(paramValue);
        } else {
            // Se for o início da lista, dá shove.
            if(index == 0){
                Shove(paramValue);
            } else if(index == Length()){
                Append(paramValue);
            } else {
                int cont;

                // Pega a referencia do elemento que está na posição i.
                dChainedListItem <T>* previousItem = this->start;

                cont = 0;
                while(cont < index - 1){
                    previousItem = previousItem->next;
                    cont++;
                }

                // Pega a referencia do elemento que será o elemento posterior (índice "index")
                dChainedListItem <T>* nextItem = this->start;

                cont = 0;
                while(cont < index){
                    nextItem = nextItem->next;
                    cont++;
                }

                // Cria o novo item
                dChainedListItem <T>* newItem = this->AddToItem(paramValue, previousItem, nextItem);
                previousItem->next = newItem;
                nextItem->previous = newItem;
            }
        }
    }

    // Deleta um item
    void Delete(int index){
        if(Empty()) {
            return;
        } else {
            // Deletar o início.
            if(index == 0) {
                // Se é uma lista única.
                if(Length() == 1) {
                    this->start = nullptr;
                    this->end = nullptr;

                    delete start;
                } else {
                    dChainedListItem <T>* oldStart = this->start;
                    this->start = this->start->next;

                    delete oldStart;
                }
            } else if(index == Length() - 1) {
                // Se é uma lista única.
                if(Length() == 1) {
                    this->start = nullptr;
                    this->end = nullptr;

                    delete start;
                } else {
                    // Deletar o último elemento.
                    dChainedListItem <T>* navigator = this->start;
                    int cont = 0;
                    while(cont < index) {
                        navigator = navigator->next;
                        cont++;
                    }

                    dChainedListItem <T>* previousItem = navigator->previous;
                    previousItem->next = nullptr;

                    delete navigator;
                }
            } else {
                // Deletar elemento do meio.
                dChainedListItem <T>* navigator = this->start;
                int cont = 0;
                while(cont < index) {
                    navigator = navigator->next;
                    cont++;
                }

                dChainedListItem <T>* previousItem = navigator->previous;
                dChainedListItem <T>* nextItem = navigator->next;

                previousItem->next = nextItem;
                nextItem->previous = previousItem;

                delete navigator;
            }
        }
    }

    // Deleta a lista inteira.
    void Clear() {
        while(Length() > 0) {
            Delete(0);
        }
    }

    // Imprime a lista na tela
    void Print() {
        if(Empty()) {
            cout << "<empty>" << endl;
        } else {
            dChainedListItem <T>* navigator = this->start;

            cout << "[";
            while(navigator != nullptr) {
                cout << navigator->value;

                if(!(navigator->next == nullptr)) {
                    cout << ", ";
                }
                navigator = navigator->next;
            }
            cout << "]" << endl;
        }
    }

    // Obtem um valor na lista
    T GetValue(int index){
        dChainedListItem <T>* navigator = this->start;
        int cont = 0;
        while(cont < index){
            navigator = navigator->next;
            cont++;
        }
        return navigator->value;
    }

    // Obtem um valor de ponteiro na lista
    T* GetElement(int index){
        dChainedListItem <T>* navigator = this->start;
        int cont = 0;
        while(cont < index){
            navigator = navigator->next;
            cont++;
        }
        return &navigator->value;
    }

    // Obtem o tamanho da lista
    int Length(){
        dChainedListItem <T>* navigator = this->start;
        int size = 0;
        while(navigator != nullptr){
            navigator = navigator->next;
            size++;
        }
        return size;
    }

    // Checa se está vazia ou não.
    bool Empty(){
        return this->start == nullptr;
    }
};

#endif // DCHAINEDLIST_H
