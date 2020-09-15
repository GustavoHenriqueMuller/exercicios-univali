#ifndef AVL_H
#define AVL_H

#include <iostream>

using namespace std;

template <class Type>
struct AVLNode {
    int bFactor;
    int key;
    Type value;
    AVLNode* left;
    AVLNode* right;
};

template <class Type>
struct AVL {
    AVLNode<Type>* root;
};




//  #######################################
//  Main Functions

template <class Type>
AVLNode<Type>* InitAVLNode(int key, Type value, AVLNode<Type>* left = nullptr, AVLNode<Type>* right = nullptr, int bFactor = 0) {
    AVLNode<Type>* newNode = new AVLNode<Type>;
    newNode->bFactor = bFactor;
    newNode->key = key;
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

template <class Type>
AVLNode<Type>* InitAVLNode(int key, AVLNode<Type>* left = nullptr, AVLNode<Type>* right = nullptr, int bFactor = 0) {
    AVLNode<Type>* newNode = new AVLNode<Type>;
    newNode->bFactor = bFactor;
    newNode->key = key;
    newNode->value = key;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

template <class Type>
AVLNode<Type>* InitAVLNode(Type value, AVLNode<Type>* left = nullptr, AVLNode<Type>* right = nullptr, int bFactor = 0) {
    AVLNode<Type>* newNode = new AVLNode<Type>;
    newNode->bFactor = bFactor;
    newNode->key = value;
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

template <class Type>
void InitAVL(AVL<Type> &tree) {
    tree.root = nullptr;
}

template <class Type>
void InitAVL(AVL<Type> &tree, Type value) {
    tree.root = InitAVLNode(value);
}

template <class Type>
void LeftRotation( AVLNode<Type>* targetNode, AVLNode<Type>* previous) {
    if(previous->value > targetNode->value) {
        previous->left = targetNode->right;
        targetNode->right = previous->left->left;
        previous->left->left = targetNode;
    } else {
        previous->right = targetNode->right;
        targetNode->right = previous->right->left;
        previous->right->left = targetNode;
    }
}

template <class Type>
void RightRotation(AVLNode<Type>* targetNode, AVLNode<Type>* previous) {
    if(previous->value > targetNode->value) {
        previous->left = targetNode->left;
        targetNode->left = previous->left->right;
        previous->left->right = targetNode;
    } else {
        previous->right = targetNode->left;
        targetNode->left = previous->right->right;
        previous->right->right = targetNode;
    }
}

template <class Type>
void LeftRightRotation(AVLNode<Type>* targetNode, AVLNode<Type>* previous) {
    if(previous->value > targetNode->value) {
        previous->left = targetNode->left->right;

        AVLNode<Type>* left = previous->left->left;
        AVLNode<Type>* right = previous->left->right;
        AVLNode<Type>* newLeft = targetNode->left;
        AVLNode<Type>* newRight = targetNode;

        targetNode->left->right = left;
        targetNode->left = right;

        previous->left->left = newLeft;
        previous->left->right = newRight;
    } else {
        previous->right = targetNode->left->right;

        AVLNode<Type>* left = previous->right->left;
        AVLNode<Type>* right = previous->right->right;
        AVLNode<Type>* newLeft = targetNode->left;
        AVLNode<Type>* newRight = targetNode;

        targetNode->left->right = left;
        targetNode->left = right;

        previous->right->left = newLeft;
        previous->right->right = newRight;
    }
}

template <class Type>
void RightLeftRotation(AVLNode<Type>* targetNode, AVLNode<Type>* previous) {
    if(previous->value > targetNode->value) {
        previous->left = targetNode->right->left;

        AVLNode<Type>* left = previous->left->right;
        AVLNode<Type>* right = previous->left->left;
        AVLNode<Type>* newLeft = targetNode->right;
        AVLNode<Type>* newRight = targetNode;

        targetNode->right->left = left;
        targetNode->right = right;

        previous->left->left = newLeft;
        previous->left->right = newRight;
    } else {
        previous->right = targetNode->right->left;

        AVLNode<Type>* left = previous->right->right;
        AVLNode<Type>* right = previous->right->left;
        AVLNode<Type>* newLeft = targetNode->right;
        AVLNode<Type>* newRight = targetNode;

        targetNode->right->left = left;
        targetNode->right = right;

        previous->right->left = newRight;
        previous->right->right = newLeft;
    }
}

template <class Type>
void LeftRotation(AVL<Type> &tree, AVLNode<Type>* targetNode) {
//    cout << "VALUE" << endl;
    tree.root = targetNode->left;
    targetNode->left = tree.root->right;
    tree.root->right = targetNode;
}

template <class Type>
void RightRotation(AVL<Type> &tree, AVLNode<Type>* targetNode) {
//    cout << "VALUE" << endl;
    tree.root = targetNode->right;
    targetNode->right = tree.root->left;
    tree.root->left = targetNode;
}

template <class Type>
void LeftRightRotation(AVL<Type> &tree, AVLNode<Type>* targetNode) {
//    cout << "VALUE" << endl;
    tree.root = targetNode->left->right;

    AVLNode<Type>* left = tree.root->left;
    AVLNode<Type>* right = tree.root->right;
    AVLNode<Type>* newLeft = targetNode->left;
    AVLNode<Type>* newRight = targetNode;

    targetNode->left->right = left;
    targetNode->left = right;

    tree.root->left = newLeft;
    tree.root->right = newRight;
}

template <class Type>
void RightLeftRotation(AVL<Type> &tree, AVLNode<Type>* targetNode) {
    tree.root = targetNode->right->left;

    AVLNode<Type>* left = tree.root->right;
    AVLNode<Type>* right = tree.root->left;
    AVLNode<Type>* newLeft = targetNode->right;
    AVLNode<Type>* newRight = targetNode;

    targetNode->right->left = left;
    targetNode->right = right;

    tree.root->left = newRight;
    tree.root->right = newLeft;
}

template <class Type>
void Balance(AVL<Type> &tree) {
    AVLNode<Type>* targetNode = HasViolation(tree);

    if(targetNode == nullptr)
        return;
    if(targetNode->left != nullptr && IsViolated(targetNode->left))
        while(targetNode->left != nullptr && IsViolated(targetNode->left))
            targetNode = targetNode->left;
    else if(targetNode->right != nullptr && IsViolated(targetNode->right))
        while(targetNode->right != nullptr && IsViolated(targetNode->right))
            targetNode = targetNode->right;

    if(IsRoot(tree, targetNode)) {
        if(targetNode->bFactor > 0) {   // Left
            if(targetNode->left->bFactor > 0)
                LeftRotation(tree, targetNode);                 // Left-Left
            else
                LeftRightRotation(tree, targetNode);            // Left-Right
        } else { // Right
            if(targetNode->right->bFactor > 0)
                RightLeftRotation(tree, targetNode);            // Right-Left
            else
                RightRotation(tree, targetNode);                // Right-Right
        }
    } else {
        AVLNode<Type>* previous = GetPreviousNodeFromTree(tree, targetNode->value);
        if(targetNode->bFactor > 0) {   // Left
            if(targetNode->left->bFactor > 0)
                RightRotation(targetNode, previous);            // Left-Left
            else
                LeftRightRotation(targetNode, previous);        // Left-Right
        } else { // Right
            if(targetNode->right->bFactor > 0)
                RightLeftRotation(targetNode, previous);        // Right-Left
            else
                LeftRotation(targetNode, previous);             // Right-Right
        }
    }
}

template <class Type>
void InsertNode(AVLNode<Type>* node, Type value) {
    if(value > node->value) {
        if(node->right != nullptr)
            InsertNode(node->right, value);
        else
            node->right = InitAVLNode(value);
    } else if(value < node->value) {
        if(node->left != nullptr)
            InsertNode(node->left, value);
        else
            node->left = InitAVLNode(value);
    }
}

template <class Type>
void Insert(AVL<Type> &tree, Type value) {
    if(IsValid(tree)) {
        InsertNode(tree.root, value);
        UpdateBFactor(tree.root);
        Balance(tree);
        UpdateBFactor(tree.root);
    } else
        tree.root = InitAVLNode(value);
}

template <class Type>
void DestroyTree(AVL<Type> &tree) {
    DestroyNode(tree.root);
}

template <class Type>
void DestroyNode(AVLNode<Type>* node) {
    if(node != nullptr) {
        DestroyNode(node->left);
        DestroyNode(node->right);
        delete node;
    }
}

template <class Type>
int GetHeight(AVL<Type> tree, Type value) {
   if(IsValid(tree))
        return CalculateHeigth(tree.root, value);
   return -1;
}

template <class Type>
int CalculateHeigth(AVLNode<Type>* node, Type value) {
    if(value > node->value) {
        if(node->right != nullptr) {
            int temp = CalculateHeigth(node->right, value);
            return (temp == -1) ? -1 : temp+1;
        } else {
            return -1;
        }
    } else if(value < node->value) {
        if(node->left != nullptr) {
            int temp = CalculateHeigth(node->left, value);
            return (temp == -1) ? -1 : temp + 1;
        } else {
            return -1;
        }
    }
    return 1;
}

template <class Type>
bool HasValue(AVL<Type> tree, Type value) {
   if(IsValid(tree))
        return CheckIfHasValue(tree.root, value);
    return false;
}

template <class Type>
bool CheckIfHasValue(AVLNode<Type>* node, Type value) {
    if(value > node->value) {
        if(node->right != nullptr)
            return CheckIfHasValue(node->right, value);
        return false;
    } else if(value < node->value) {
        if(node->left != nullptr)
            return CheckIfHasValue(node->left, value);
        return false;
    }
    return true;
}

template <class Type>
int GetAmountOfLevels(AVLNode<Type>* node) {
    if(node == nullptr)
        return 0;
    if(IsLeaf(node))
        return 1;
    if(node->left != nullptr && node->right != nullptr) {
        int left = GetAmountOfLevels(node->left) + 1;
        int right = GetAmountOfLevels(node->right) + 1;
        return (left > right) ? left : right;
    }
    if(node->left == nullptr)
        return (GetAmountOfLevels(node->right) + 1);
    else
        return GetAmountOfLevels(node->left) + 1;
}

template <class Type>
void UpdateBFactor(AVLNode<Type>* node) {
    if(node == nullptr || IsLeaf(node))
        return;

    if(node->left != nullptr && node->right != nullptr)
        node->bFactor = (GetAmountOfLevels(node->left)) - (GetAmountOfLevels(node->right));
    else if(node->left == nullptr)
        node->bFactor = 0 - GetAmountOfLevels(node->right);
    else
        node->bFactor = GetAmountOfLevels(node->left);

    UpdateBFactor(node->right);
    UpdateBFactor(node->left);
}

template <class Type>
AVLNode<Type>* HasViolation(AVL<Type> &tree) {
    if(IsValid(tree))
        return CheckIfHasViolation(tree.root);
    return nullptr;
}

template <class Type>
AVLNode<Type>* CheckIfHasViolation(AVLNode<Type>* node) {
    if(node == nullptr || IsLeaf(node))
        return nullptr;

    if(IsViolated(node))
        return node;

    if(node->left != nullptr && node->right != nullptr) {
        AVLNode<Type>* left = CheckIfHasViolation(node->left);
        AVLNode<Type>* right = CheckIfHasViolation(node->right);
        if(left == nullptr && right == nullptr)
            return nullptr;
        else
            return (left == nullptr) ? right : left;
    } else if(node->left == nullptr)
        return CheckIfHasViolation(node->right);
    else
        return CheckIfHasViolation(node->left);
}

template <class Type>
AVLNode<Type>* GetNodeFromTree(AVL<Type> tree, Type value) {
    if(IsValid(tree))
        return GetNode(tree.root, value);
    return nullptr;
}

template <class Type>
AVLNode<Type>* GetNode(AVLNode<Type>* node, Type value) {
    if(value > node->value) {
        if(node->right != nullptr)
            return GetNode(node->right, value);
        else
            return nullptr;
    } else if(value < node->value) {
        if(node->left != nullptr)
            return GetNode(node->left, value);
        else
            return nullptr;
    }
    return node;
}

template <class Type>
AVLNode<Type>* GetPreviousNodeFromTree(AVL<Type> tree, Type value) {
   if(IsValid(tree))
        return GetPreviousNode(tree.root, value);
    return nullptr;
}

template <class Type>
AVLNode<Type>* GetPreviousNode(AVLNode<Type>* node, Type value) {
    if(value > node->value) {
        if(node->right != nullptr) {
            if(node->right->value == value)
                return node;
            return GetPreviousNode(node->right, value);
        }
    } else if(value < node->value) {
        if(node->left != nullptr) {
            if(node->left->value == value)
                return node;
            return GetPreviousNode(node->left, value);
        }
    }
    return node;
}

template <class Type>
AVLNode<Type>* GetSubstituteForNode(AVLNode<Type>* node) {
    if(node->left != nullptr)
        return GetBiggerLeft(node->left);
    else if(node->right != nullptr)
        return GetSmallerRight(node->right);
    return node;
}

template <class Type>
AVLNode<Type>* GetBiggerLeft(AVLNode<Type>* node) {
    if(node->right != nullptr)
        return GetBiggerLeft(node->right);
    return node;
}

template <class Type>
AVLNode<Type>* GetSmallerRight(AVLNode<Type>* node) {
    if(node->left != nullptr)
        return GetSmallerRight(node->left);
    return node;
}

// Implementação priorizando o maior à esquerda
template <class Type>
void Remove(AVL<Type> &tree, Type value) {
    if(!IsValid(tree))
        return;

    AVLNode<Type>* targetNode = GetNodeFromTree(tree, value);

    if(!targetNode)
        return;

    if(IsLeaf(targetNode)) {
        if(IsRoot(tree, targetNode)) {
            delete targetNode;
            tree.root = nullptr;
        } else {
            AVLNode<Type>* previousNode = GetPreviousNodeFromTree(tree, value);
            if(previousNode->left != nullptr && previousNode->left->value == value)
                previousNode->left = nullptr;
            else
                previousNode->right = nullptr;
            delete targetNode;
        }
    } else {
        AVLNode<Type>* substitute = GetSubstituteForNode(targetNode);
        AVLNode<Type>* erase = targetNode;

        AVLNode<Type>* previousNode = GetPreviousNodeFromTree(tree, value);
        AVLNode<Type>* previousSubstitute = GetPreviousNodeFromTree(tree, substitute->value);

        if(substitute->value < value) {
            substitute->right = targetNode->right;
            AVLNode<Type>* saveSubstitute = substitute->left;
            substitute->left = targetNode->left;

            if(IsRoot(tree, targetNode) && previousNode->value == tree.root->value)
                tree.root = substitute;
            else if(previousNode->value > targetNode->value)
                previousNode->left = substitute;
            else
                previousNode->right = substitute;

            if(previousSubstitute->value == targetNode->value)
                substitute->left = saveSubstitute;
            else if(previousSubstitute->value > substitute->value)
                previousSubstitute->left = saveSubstitute;
            else
                previousSubstitute->right = saveSubstitute;

        } else {
            substitute->left = targetNode->left;
            AVLNode<Type>* saveSubstitute = substitute->right;
            substitute->right = targetNode->right;

            if(IsRoot(tree, targetNode) && previousNode->value == tree.root->value)
                tree.root = substitute;
            else if(previousNode->value > targetNode->value)
                previousNode->left = substitute;
            else
                previousNode->right = substitute;

            if(previousSubstitute->value == targetNode->value)
                substitute->right = saveSubstitute;
            else if(previousSubstitute->value > substitute->value)
                previousSubstitute->left = saveSubstitute;
            else
                previousSubstitute->right = saveSubstitute;
        }

        delete erase;
    }
    UpdateBFactor(tree.root);
    Balance(tree);
    UpdateBFactor(tree.root);
}

template <class Type>
bool IsLeaf(AVLNode<Type>* node) {
    return (node->left == nullptr && node->right == nullptr);
}

template <class Type>
bool IsRoot(AVL<Type> tree, AVLNode<Type>* node) {
    return (node->key == tree.root->key);
}

template <class Type>
bool IsValid(AVL<Type> tree) {
    return !(tree.root == nullptr);
}

template <class Type>
bool IsViolated(AVLNode<Type>* node) {
    return (node->bFactor > 1) || (node->bFactor < -1);
}



//  #######################################
//  Print Functions

template <class Type>
void PrintAVL(AVL<Type> tree) {
    DrawTree(tree.root, 1);
    cout << endl << endl;
}

template <class Type>
void DrawNode(Type value, int margin) {
    for(int i = 0; i < margin; i++)
        cout << "\t";
    cout << value << endl;
}

template <class Type>
void DrawTree(AVLNode<Type>* node, int margin) {
    if (node == nullptr) {
        DrawNode("#", margin);
        return;
    }
    DrawTree(node->right, margin+1);
    DrawNode(node->value, margin);
    DrawTree(node->left, margin+1);
}

#endif // AVL_H
