//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
                // reverse the LL
     struct Node*reverse( struct Node* head){
         
           struct Node* curr= head;
           struct Node* prev= nullptr;
           while(curr!=nullptr){
                struct Node* forward= curr->next;
                
                curr->next= prev;
                
                prev= curr;
                
                curr= forward;
           }

return prev;
}
     
     
     void addToTail(struct Node* &sumTail, int val){
         
         struct Node*temp = new struct Node(val);
         sumTail->next=temp;
         sumTail= sumTail->next;
     }
     
   struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    if (first == nullptr)
        return second;
    if (second == nullptr)
        return first;

    struct Node* list1 = reverse(first);
    struct Node* list2 = reverse(second);

    struct Node* sum = new struct Node(-1); // dummy node created
    struct Node* sumTail = sum;
    int carry = 0;
    while (list1 != nullptr || list2 != nullptr || carry > 0)
    {
        int digit1 = (list1 != nullptr) ? list1->data : 0;
        int digit2 = (list2 != nullptr) ? list2->data : 0;
        int digit = digit1 + digit2 + carry;
        
        carry = digit / 10;
        addToTail(sumTail, digit % 10);

        if (list1 != nullptr)
            list1 = list1->next;
        if (list2 != nullptr)
            list2 = list2->next;
    }
    
    return reverse(sum->next); // Reverse the sum list before returning
}
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends