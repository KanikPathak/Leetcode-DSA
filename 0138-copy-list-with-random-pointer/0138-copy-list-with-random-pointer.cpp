/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      
     if(head==nullptr)
       return NULL;
      
      
      // pehle toh copy banado list ki
      // ek element ke bad hi us copy ko place karo jaise 1 2 3 4 hai toh 1 1 2 2 3 3 4 4  aise copy
      
      Node* curr= head;
      while(curr!=nullptr){
        
        
        Node* copyNode = new Node(curr->val);

        copyNode->next = curr->next;
        
        curr->next= copyNode;
        
        curr= copyNode->next;
      }
      
      // abhi list aisi hai 1 1 2 2 3 3 4 4 
      // ab iske copied nodes ke next ko random pointer se badal do
      curr=head;
      while(curr!=nullptr){
        
        if(curr->random != nullptr)
          curr->next->random = curr->random->next;
        
        curr = curr->next->next;
        
      }
      
      // ab sirf copied walo ko consider kro or bakein hta do
      
      curr=head;
      Node* ansHead= head->next ;        // pehle copied ko daldo pehle hi fir bakio ke lie traverse krdo
       Node* ansTail = ansHead;
      while( curr != nullptr ){
        
        curr->next = curr->next->next; // curr points to the next orignal node
        
        // abi agar copied exist krta hai agla toh use daldo ans mei
        
        if(ansTail->next != NULL){ // toh ek bcha hai aage or ek hai to copied b hoga last walo ko loop ke bad handle kr lenge
          ansTail->next= ansTail->next->next;
        }
        // update pointers
        curr = curr->next;
        ansTail= ansTail->next;
        
      }
      
       return ansHead; 
    }
};