#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class BinaryTree
{
private:
    char data;
    BinaryTree* lchild;
    BinaryTree* rchild;
public:
    BinaryTree();
    ~BinaryTree();
    
    BinaryTree* Create_BinaryTree();

    void PreorderTraversal(BinaryTree* T);
    void PreorderTraversal2(BinaryTree* T);
    void InorderTraversal(BinaryTree* T);
    void InorderTraversal2(BinaryTree* T);
    void PostorderTraversal(BinaryTree* T);
    void PostorderTraversal2(BinaryTree* T);
    void LevelOrderTraversal(BinaryTree* T);

    int getBinaryTreeHeight(BinaryTree* T);
};

BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{
}

BinaryTree* BinaryTree::Create_BinaryTree(){
    BinaryTree* T = new BinaryTree;
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        T = NULL;
    }else{
        T->data = ch;
        T->lchild = Create_BinaryTree();
        T->rchild = Create_BinaryTree();
    }
    return T;
}

void BinaryTree::PreorderTraversal(BinaryTree* T){
    if(T == NULL)
    {
        return;
    }
    printf("%c ", T->data);
    T->PreorderTraversal(T->lchild);
    T->PreorderTraversal(T->rchild);
}

void BinaryTree::InorderTraversal(BinaryTree* T){
    if (T == NULL)
    {
        return;
    }
    T->InorderTraversal(T->lchild);
    printf("%c ", T->data);
    T->InorderTraversal(T->rchild);
}

void BinaryTree::PostorderTraversal(BinaryTree* T){
    if (T == NULL)
    {
        return;
    }
    T->PostorderTraversal(T->lchild);
    T->PostorderTraversal(T->rchild);
    printf("%c ", T->data);
}

int main(int argc, char const *argv[])
{
    cout<<"请初始化二叉树:"<<endl;
    BinaryTree* T;
    T = T->Create_BinaryTree();

    cout<<"前序遍历（递归）："<<endl;
    T->PreorderTraversal(T);
    cout<<endl;

    return 0;
}
