#include <iostream>
#include <string>

template<class T>
struct stackElement {
    T value;
    stackElement <T>* next;
};

template<class T>
struct stack {
    private:
    stackElement <T>* top = nullptr;

    stackElement <T>* AddToElement(T paramValue, stackElement <T>* paramNext){
        stackElement <T>* newElement = new stackElement <T>;
        newElement->value = paramValue;
        newElement->next = paramNext;
        return newElement;
    }

    public:
    void Push(T paramValue){
        stackElement <T>* newElement = AddToElement(paramValue, top);
        top = newElement;
    }

    T Pop(){
        if(top != nullptr){
            T elementCopy = top->value;
            stackElement <T>* oldTop = top;
            top = top->next;
            delete oldTop;

            return elementCopy;
        } else {
            throw "Pop() function called on null list. \n";
        }
    }

    void Print(){
        std::cout << "{";
        for(stackElement <T>* nav = top; nav != nullptr; nav = nav->next){
            if(nav->next != nullptr){
                std::cout << nav->value << ", ";
            } else {
                std::cout << nav->value;
            }
        }
        std::cout << "}" << std::endl;
    }
};

int main() {
    stack <int> myStack;
    return 0;
}
