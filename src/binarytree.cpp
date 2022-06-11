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

void BinaryTree::PreorderTraversal2(BinaryTree* T){
    stack<BinaryTree*> stack;
    BinaryTree* binary_tree_curr = T;
    while (binary_tree_curr || !stack.empty())
    {
        printf("%c ", binary_tree_curr->data);
        stack.push(binary_tree_curr);
        binary_tree_curr = binary_tree_curr->lchild;
        while (!binary_tree_curr && !stack.empty())
        {
            binary_tree_curr = stack.top();
            stack.pop();
            binary_tree_curr = binary_tree_curr->rchild;
        }   
    }
}

void BinaryTree::InorderTraversal2(BinaryTree* T){
            stack<BinaryTree*> stack;                                   //初始化栈 
            BinaryTree* binary_tree_curr = T;                           //保存当前结点 
            while(binary_tree_curr || !stack.empty()){
                if(binary_tree_curr->lchild){                           //左孩子非空
                    stack.push(binary_tree_curr);                       //当前结点入栈 
                    binary_tree_curr = binary_tree_curr->lchild;        //遍历左子树 
                }else{
                    //左孩子为空，则打印当前结点遍历右子树 
                    cout<<binary_tree_curr->data<<" ";                  
                    binary_tree_curr = binary_tree_curr->rchild;
                    //如果为空，且栈不空，则将栈顶节点出栈，并输出该节点，  
                    //同时将它的右孩子设为当前节点，继续判断，直到当前节点不为空   
                    while(!binary_tree_curr && !stack.empty()){
                        binary_tree_curr = stack.top();
                        cout<<binary_tree_curr->data<<" ";
                        stack.pop();
                        binary_tree_curr = binary_tree_curr->rchild;
                    }
                }
            }
        }

//非递归后序遍历
void BinaryTree::PostorderTraversal2(BinaryTree* T){
    stack<BinaryTree*> stack;
    BinaryTree* binary_tree_curr = T;                   //当前结点 
    BinaryTree* binary_tree_pre = NULL;                // 上一个结点 
    //先将树的根节点入栈
    stack.push(binary_tree_curr);
    //直到栈空时，结束循环  
    while(!stack.empty()){
        binary_tree_curr = stack.top();              //当前节点置为栈顶节点  
        //如果当前节点没有左右孩子，或者有左孩子或有孩子，但已经被访问输出，  
        //则直接输出该节点，将其出栈，将其设为上一个访问的节点  
        if((binary_tree_curr->lchild == NULL && binary_tree_curr->rchild == NULL) ||
            (binary_tree_curr != NULL && binary_tree_curr->lchild == binary_tree_pre || 
                                        binary_tree_curr->rchild == binary_tree_pre)){
            cout<<binary_tree_curr->data<<" ";
            stack.pop();
            binary_tree_pre = binary_tree_curr; 
        }else{
            //如果不满足上面两种情况,则将其右孩子左孩子依次入栈  
            if(binary_tree_curr->rchild != NULL){
                stack.push(binary_tree_curr->rchild);
            }
            if(binary_tree_curr->lchild != NULL){
                stack.push(binary_tree_curr->lchild);
            } 
        }
    }
}

void BinaryTree::LevelOrderTraversal(BinaryTree* T){
    queue<BinaryTree*> queue;
    BinaryTree* cur = T;
    queue.push(cur);
    while (!queue.empty())
    {
        cur = queue.front();
        queue.pop();
        cout << cur->data << " ";
        if (cur->lchild != NULL)
        {
            queue.push(cur->lchild);
        }
        if (cur->rchild != NULL)
        {
            queue.push(cur->rchild);
        }
        
    }
    
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
