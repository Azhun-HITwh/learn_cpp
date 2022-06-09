#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class BinaryTree
{
private:
    cahr data;
    BinaryTree* lchild;
    BinaryTree* rchild;
public:
    BinaryTree(/* args */);
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

BinaryTree::BinaryTree(/* args */)
{
}

BinaryTree::~BinaryTree()
{
}
