#include <bits/stdc++.h>
using namespace std;
class LLnode
{
public:
    int data;
    LLnode *next;

    LLnode(int nodeData)
    {
        cout<<"came to constructoe";
        this->data = nodeData;
        this->next = NULL;
        cout<<"cleft constructior";
    }
};
class linkedChain
{
public:
    LLnode *head;
    LLnode *tail;
    linkedChain()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    //function declaration
    void insertNode(int);
    void deleteNode(int);
    void printList();
};
//function defintion
void linkedChain::insertNode(int nodeData)
{
    cout<<"inside insert node";
    LLnode *newNode = new LLnode(nodeData);
    cout<<head->data;
    if (this->head == NULL)
    {
        cout<<"checling head";
        this->head = newNode;
        return;
    }
    cout<<"no head checking";
    LLnode *temp = head;
    while (temp->next != NULL) {
  
        // Update temp
        temp = temp->next;
    }
  
    // Insert at the last.
    temp->next = newNode;

}
void linkedChain::printList()
{
    while (head->next != NULL)
    {
        cout << head->data << " ";
    }
    cout << head->data << endl;
};
int main()
{
    linkedChain *node=new linkedChain();
    int lCount;
    cout << "enter size of list";
    cin >> lCount;
    for (int i = 0; i < lCount; i++)
    {
        int Ldata;
        cout << "elements " << i << endl;
        cin >> Ldata;
        node->insertNode(Ldata);
        cout<<"came after inserting";
    }
    cout << "elements of list are" << endl;
    node->printList();
    return 0;
}