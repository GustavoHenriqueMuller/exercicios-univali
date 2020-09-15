#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

struct HuffmanNode {
    int frequency;
    char data;
    HuffmanNode* left;
    HuffmanNode* right;
};

struct HuffmanTree {
    HuffmanNode* root;
};

HuffmanNode* InitHuffmanNode(int frequency, char data, HuffmanNode* left = nullptr, HuffmanNode* right = nullptr) {
    HuffmanNode* newNode = new HuffmanNode;
    newNode->frequency = frequency;
    newNode->data = data;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

bool IsLeaf(HuffmanNode* node) {
    return (node->left == nullptr && node->right == nullptr);
}

void DrawNode(char value, int margin) {
    for(int i = 0; i < margin; i++)
        cout << "\t";
    cout << value << endl;
}

void DrawTree(HuffmanNode* node, int margin) {
    if (node == nullptr) {
        DrawNode('#', margin);
        return;
    }
    DrawTree(node->right, margin+1);
    (node->data == '\0') ? DrawNode('@', margin) : DrawNode(node->data, margin);
    DrawTree(node->left, margin+1);
}

void PrintHuffmanTree(HuffmanTree tree) {
    DrawTree(tree.root, 1);
    cout << endl << endl;
}

template <>
bool Contains(LinkedList<HuffmanNode*> &list, HuffmanNode* value) {
    ElementLL<HuffmanNode*>* temp = list.begin;
    if(temp == nullptr)
        return false;

    do {
        if(temp->value->data == value->data)
            return true;
        temp = temp->next;
    } while(temp != nullptr);

    return false;
}

void Sort(LinkedList<HuffmanNode*> &list) {
    int size = GetSize(list);

    // Bubble Sort
    for(int j = 0; j < size; j++) {
        for(int i = 0; i < size - 1; i++) {
            ElementLL<HuffmanNode*>* a = GetElementAt(list, i, true);
            ElementLL<HuffmanNode*>* b = GetElementAt(list, i+1, true);
            if(a->value->frequency > b->value->frequency) {
                if(a == list.begin) {
                    list.begin = b;
                } else {
                    ElementLL<HuffmanNode*>* previousA = GetElementAt(list, i-1, true);
                    previousA->next = b;
                }
                if(b == list.end)
                    list.end = a;
                a->next = b->next;
                b->next = a;
            }
        }
    }
}

int GetAmountOfOccurrences(string targetText, char targetChar) {
    int counter = 0;
    for(unsigned int i = 0; i < targetText.size(); i++) {
        if(targetText.at(i) == targetChar)
            counter++;
    }
    return counter;
}

void InsertChar(LinkedList<HuffmanNode*> &list, char targetChar, string targetText) {
    HuffmanNode* node = InitHuffmanNode(0, targetChar);
    if(!Contains(list, node)) {
        int counter = GetAmountOfOccurrences(targetText, targetChar);
        node->frequency = counter;
        AddEnd(list, node);
    }
}

void Print(LinkedList<HuffmanNode*> list) {
    ElementLL<HuffmanNode*>* element = list.begin;
    int i = 1;
    do {
        cout << "[" << i << "] - " << element->value->data << "     " << element->value->frequency << endl;
        element = element->next;
        i++;
    } while(element != nullptr);
}

int GetPositionFor(LinkedList<HuffmanNode*> list, HuffmanNode* value) {
    ElementLL<HuffmanNode*>* temp = list.begin;
    if(temp == nullptr)
        return -1;

    int i = 0;
    do {
        if(value->frequency >= temp->value->frequency) {
            temp = temp->next;
            i++;
        } else {
            return i;
        }
    } while(temp != nullptr);

    return i;
}

HuffmanNode* FormTree(LinkedList<HuffmanNode*> &list) {
    while(GetSize(list) > 1) {
        ElementLL<HuffmanNode*>* a = GetElementAt(list, 0, true);
        ElementLL<HuffmanNode*>* b = GetElementAt(list, 1, true);
        ElementLL<HuffmanNode*>* c = new ElementLL<HuffmanNode*>;
        c->value = InitHuffmanNode(a->value->frequency + b->value->frequency,
                                   '\0', a->value, b->value);

        int position = GetPositionFor(list, c->value);
        if(position != -1)
            AddAt(list, c->value, position);

        list.begin = GetElementAt(list, 2, true);
    }
    return list.begin->value;
}

void CreateHuffmanTree(HuffmanTree &tree, string targetText) {
    // Casting to char*
    char* targetArray = (char*)targetText.c_str();

    // Initializing the LList and the Huffman Tree
    LinkedList<HuffmanNode*> list;
    InitList(list);

    // Inserting characters on the list
    for(unsigned int i = 0; i < targetText.size(); i++)
        InsertChar(list, targetArray[i], targetText);

    // Using a bubble sort function
    Sort(list);

    // Printing list
    Print(list);
    cout << "SIZE: " << GetSize(list) << endl << endl << endl;

    // Transforming the list into a tree;
    tree.root = FormTree(list);
}

string GetTrack(HuffmanNode* node, char value, string final) {
    if(node == nullptr)
        return "#";
    if(node->data == value)
        return final;

    string temp = GetTrack(node->left, value, final.append("0"));
    if(temp.at(temp.size()-1) == '#') {
        return GetTrack(node->right, value, final.erase(final.size()-1).append("1"));
    } else
        return temp;
}

string GenerateBitText(HuffmanTree tree, string targetText) {
    string finalText = "";
    for(unsigned int i = 0; i < targetText.size(); i++) {
        string track = GetTrack(tree.root, targetText.at(i), "");
        finalText.append(track);
    }
    return finalText;
}

string GenerateNormalText(HuffmanTree tree, string bitText) {
    HuffmanNode* nav = tree.root;
    string text = "";
    for(unsigned int i = 0; i < bitText.size(); i++) {
        (bitText.at(i) == '0') ? nav = nav->left : nav = nav->right;
        if(IsLeaf(nav)) {
            text.push_back(nav->data);
            nav = tree.root;
        }
    }
    return text;
}


#endif // HUFFMAN_H
