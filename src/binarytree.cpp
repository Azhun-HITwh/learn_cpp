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
            stack<BinaryTree*> stack;                                   //???????????? 
            BinaryTree* binary_tree_curr = T;                           //?????????????????? 
            while(binary_tree_curr || !stack.empty()){
                if(binary_tree_curr->lchild){                           //???????????????
                    stack.push(binary_tree_curr);                       //?????????????????? 
                    binary_tree_curr = binary_tree_curr->lchild;        //??????????????? 
                }else{
                    //?????????????????????????????????????????????????????? 
                    cout<<binary_tree_curr->data<<" ";                  
                    binary_tree_curr = binary_tree_curr->rchild;
                    //??????????????????????????????????????????????????????????????????????????????  
                    //???????????????????????????????????????????????????????????????????????????????????????   
                    while(!binary_tree_curr && !stack.empty()){
                        binary_tree_curr = stack.top();
                        cout<<binary_tree_curr->data<<" ";
                        stack.pop();
                        binary_tree_curr = binary_tree_curr->rchild;
                    }
                }
            }
        }

//?????????????????????
void BinaryTree::PostorderTraversal2(BinaryTree* T){
    stack<BinaryTree*> stack;
    BinaryTree* binary_tree_curr = T;                   //???????????? 
    BinaryTree* binary_tree_pre = NULL;                // ??????????????? 
    //???????????????????????????
    stack.push(binary_tree_curr);
    //??????????????????????????????  
    while(!stack.empty()){
        binary_tree_curr = stack.top();              //??????????????????????????????  
        //???????????????????????????????????????????????????????????????????????????????????????????????????  
        //??????????????????????????????????????????????????????????????????????????????  
        if((binary_tree_curr->lchild == NULL && binary_tree_curr->rchild == NULL) ||
            (binary_tree_curr != NULL && binary_tree_curr->lchild == binary_tree_pre || 
                                        binary_tree_curr->rchild == binary_tree_pre)){
            cout<<binary_tree_curr->data<<" ";
            stack.pop();
            binary_tree_pre = binary_tree_curr; 
        }else{
            //?????????????????????????????????,???????????????????????????????????????  
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
    cout<<"?????????????????????:"<<endl;
    BinaryTree* T;
    T = T->Create_BinaryTree();

    cout<<"???????????????????????????"<<endl;
    T->PreorderTraversal(T);
    cout<<endl;

    return 0;
}
