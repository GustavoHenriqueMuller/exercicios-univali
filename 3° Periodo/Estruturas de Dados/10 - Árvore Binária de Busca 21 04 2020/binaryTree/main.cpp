#include <iostream>

using namespace std;

template<class T>
struct TreeNode{
    int key;
    T data;
    TreeNode<T>* right;
    TreeNode<T>* left;
};

template<class T>
struct BinaryTree{
    TreeNode<T>* begin = nullptr;

    // Encapsula o dado em um node
    TreeNode<T>* EncapsulateData(int key, T data, TreeNode<T>* right = nullptr, TreeNode<T>* left = nullptr){
        TreeNode<T>* newNode = new TreeNode<T>;
        newNode->key = key;
        newNode->data = data;
        newNode->right = right;
        newNode->left = left;

        return newNode;
    }

    // Checa se a árvore está vazia ou não
    bool isEmpty(){
        return this->begin == nullptr;
    }

    // Insere na árvore binária
    void Insert(int key, T data){
        TreeNode<T>* newNode = EncapsulateData(key, data);

        if(this->isEmpty()){
            begin = newNode;
        } else {
            TreeNode<T>* nav = this->begin;
            while(true){
                if(newNode->key > nav->key){
                    // Pegar a direita
                    if(nav->right != nullptr){
                        nav = nav->right;
                    } else {
                        nav->right = newNode;
                        break;
                    }

                } else if(newNode->key < nav->key){
                    // Pegar a esquerda
                    if(nav->left != nullptr){
                        nav = nav->left;
                    } else {
                        nav->left = newNode;
                        break;
                    }

                } else {
                    throw "INSERT ERROR: Elemento ja esta na arvore.\n";
                }
            }
        }
    }

    // Remove um elemento da árvore binária
    void Remove(int key){
        TreeNode<T>* nav = this->begin;

        if(!this->isEmpty()){
            while(true){
                if(key > nav->key){
                    if(nav->right != nullptr){
                        nav = nav->right;
                    } else {
                        throw "REMOVE ERROR: Elemento nao existe.\n";
                    }
                } else if(key < nav->key){
                    if(nav->left != nullptr){
                        nav = nav->left;
                    } else {
                        throw "REMOVE ERROR: Elemento nao existe.\n";
                    }
                } else {
                    // Elemento encontrado
                    delete nav;
                    break;
                }
            }
        } else {
            throw "REMOVE ERROR: Arvore esta vazia.\n";
        }
    }

    // Busca um elemento da árvore por chave
    T Search(int key){
        TreeNode<T>* nav = this->begin;

        if(!this->isEmpty()){
            while(true){
                if(key > nav->key){
                    if(nav->right != nullptr){
                        nav = nav->right;
                    } else {
                        throw "SEARCH ERROR: Elemento nao existe.\n";
                    }
                } else if(key < nav->key){
                    if(nav->left != nullptr){
                        nav = nav->left;
                    } else {
                        throw "SEARCH ERROR: Elemento nao existe.\n";
                    }
                } else {
                    // Elemento encontrado
                    return nav->data;
                }
            }
        } else {
            throw "SEARCH ERROR: Arvore esta vazia.\n";
        }
    }

    // Calcula a distância entre a origem e um certo nó
    int GetHeightFromRoot(int key){
        TreeNode<T>* nav = this->begin;
        int height = 0;

        if(!this->isEmpty()){
            while(true){
                if(key > nav->key){
                    if(nav->right != nullptr){
                        nav = nav->right;
                        height++;
                    } else {
                        throw "GET HEIGHT ERROR: Elemento nao existe.\n";
                    }
                } else if(key < nav->key){
                    if(nav->left != nullptr){
                        nav = nav->left;
                        height++;
                    } else {
                        throw "GET HEIGHT ERROR: Elemento nao existe.\n";
                    }
                } else {
                    // Elemento encontrado
                    break;
                }
            }
        } else {
            throw "GET HEIGHT ERROR: Arvore esta vazia.\n";
        }

        return height;
    }

    // Imprime a árvore por prefixo
    void PrintPreFix(TreeNode<T>* &node){
        cout << node->key << endl;

        if(node->left != nullptr){
            PrintPreFix(node->left);
        }

        if(node->right != nullptr){
            PrintPreFix(node->right);
        }
    }

    // Imprime a árvore por postfix
    void PrintPostFix(TreeNode<T>* &node){
        if(node->left != nullptr){
            PrintPreFix(node->left);
        }

        if(node->right != nullptr){
            PrintPreFix(node->right);
        }

        cout << node->key << endl;
    }

    // Imprime a árvore por infix
    void PrintInFix(TreeNode<T>* &node){
        if(node->left != nullptr){
            PrintPreFix(node->left);
        }

        cout << node->key << endl;

        if(node->right != nullptr){
            PrintPreFix(node->right);
        }
    }

    // Destrói a árvore
    void DestroyTree(){
        if(!this->isEmpty()){
            begin->left = nullptr;
            begin->right = nullptr;
            begin = nullptr;
        } else {
            throw "DESTROY TREE ERROR: Arvore esta vazia.\n";
        }
    }
};

int main() {
    BinaryTree<string> myTree;
    myTree.Insert(10, "A");
    myTree.Insert(8, "B");
    myTree.Insert(12, "C");
    myTree.Insert(3, "D");
    myTree.Insert(9, "E");
    myTree.PrintPreFix(myTree.begin);
    return 0;
}
