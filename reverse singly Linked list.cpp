
/* solution by : Supriya2301 */


#include<bits/stdc++.h>
using namespace std;

// creating user defined node
class Node
{
    public: 
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
//function to display linked list
void printLinkedList(Node* head)
{
     Node* temp = head;
      while(temp != NULL)
      {
          cout<<temp->data<<" ";
          temp = temp->next;
      }
  cout<<endl;
}


// function for reversing linked list using three pointer.
Node* reverseLinkedList(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* nextPtr;

    while(curr != NULL)
    {
        //changing link
        nextPtr = curr->next;
        curr->next = prev;
   
      // incrementing pointers one step ahead each time after changing the link
        prev = curr;
        curr = nextPtr;
    }

 return prev;
}

int main()
{
    // creating nodes and assigning values
    Node* head = NULL;
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;

    head = first;  //assigning head to first node

   // calling functions
    printLinkedList(head);

    Node* prev = reverseLinkedList(head);

    printLinkedList(prev);

}

