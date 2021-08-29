#include <iostream>

template<class T>
struct LineElement{
    T data;
    LineElement <T>* next;
};

template<class T>
struct Line{
    LineElement <T>* start = nullptr;

    private:
    LineElement <T>* CreateElement(T paramData, LineElement <T>* paramNext){
        LineElement <T>* newElement = new LineElement <T>;
        newElement->data = paramData;
        newElement->next = paramNext;
        return newElement;
    }

    LineElement <T>* GetPointerToEnd(){
        LineElement <T>* navigator = start;
        while(navigator->next != nullptr){
            navigator = navigator->next;
        }
        return navigator;
    }

    bool IsEmpty(){
        return start == nullptr;
    }

    public:
    void Queue(T value){
        LineElement <T>* newElement = CreateElement(value, nullptr);

        if(IsEmpty()){
            start = newElement;
        } else {
            LineElement <T>* end = GetPointerToEnd();
            end->next = newElement;
        }
    }

    T Dequeue(){
        if(!IsEmpty()){
            T valueCopy = start->data;
            LineElement <T>* oldStart = start;
            start = start->next;
            delete oldStart;

            return valueCopy;
        }
    }

    void Print(){
        if(!IsEmpty()){
            std::cout << "{";
            for(LineElement <T>* navigator = start; navigator != nullptr; navigator = navigator->next){
                std::cout << navigator->data;

                if(!(navigator->next == nullptr)){
                    std::cout << ", ";
                }
            }
            std::cout << "}" << std::endl;
        } else {
            std::cout << "{empty}" << std::endl;
        }
    }
};

int main() {
    Line <int> myLine;
    myLine.Print();
    myLine.Queue(4);
    myLine.Queue(8);
    myLine.Queue(12);
    myLine.Queue(16);
    myLine.Print();

    myLine.Dequeue();
    myLine.Print();
    return 0;
}
