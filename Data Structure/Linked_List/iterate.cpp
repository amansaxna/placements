#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int node_data) {
            this->data = node_data;
            this->next = NULL;
        }
};

class SinglyLinkedList {
    public:
        Node *head;
        //Node *tail;

        SinglyLinkedList() {
            this->head = NULL;
            //this->tail = NULL;
        }

        void insert_node(int node_data);

        void insert_node_tail(int node_data);

        void insert_node_head(int node_data);

        void insert_node_pos(int node_data, int position);

        void delete_pos(int position);

        void printLinkedList();

        void reverse_printLinkedList(Node* head);

};

void SinglyLinkedList::insert_node(int node_data) 
{
    Node* temp = this->head;
    Node* new_node = new Node(node_data);
    //if linked list is empty 
    if(this->head == NULL)
    {
        this->head = new_node;
        return;
    }
    while( temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node ; 
}

void SinglyLinkedList::insert_node_tail(int node_data)
{
    Node* iter = this->head;
    Node* node = new Node(node_data);
    while(iter->next != NULL)
    {
        iter = iter->next;
    }
    iter->next = node;
}

void SinglyLinkedList::insert_node_head(int node_data)
{
    Node* temp = this->head;
    Node* new_node = new Node(node_data);
    this->head = new_node;
    this->head->next = temp;
}

void SinglyLinkedList::insert_node_pos(int node_data, int position)
{
    Node* new_node = new Node(node_data);
    Node* iter = this->head;
    int pos = 0;
    while( iter->next != NULL || pos != ( position-1 ) )
    {
        iter = iter->next;
        pos++;
    }
    Node* temp = iter->next;
    iter->next = new_node;
    new_node->next = temp;
}

void SinglyLinkedList::delete_pos(int position)
{
    int pos = position;
    if(this->head == NULL)  return;
    Node* iter1 = this->head;
    Node* iter2 = iter1->next;
    while( iter2->next != NULL && pos != position )
    {
        iter2 = iter2->next;
        iter1 = iter1->next;
    }
    iter1->next = iter2->next;

}
void SinglyLinkedList::printLinkedList() 
{
    Node* temp = this->head;
    while( temp != NULL)
    {
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<"\n";
}

void SinglyLinkedList::reverse_printLinkedList(Node* head)
{
    if(head != NULL)
    {
        reverse_printLinkedList(head->next);
        cout<<head->data;
    }
    return;
} 

int main()
{
    int size;
    SinglyLinkedList* llist = new SinglyLinkedList();


    cout<< "How many numbers you want to insert?";
    cin>> size;
    cout<<"Enter "<< size << "numbers :";
    for( int i =0; i<size; i++)
    {
        int data;
        cin>>data;
        llist->insert_node(data);
    }
    llist->printLinkedList();

    //llist->insert_node_pos(0,0);
    llist->printLinkedList();
    llist->insert_node_head(99);
    llist->insert_node_tail(-1);
    llist->printLinkedList();
    llist->delete_pos(2);
    llist->printLinkedList();
    llist->reverse_printLinkedList(llist->head);
    return 0;
}
