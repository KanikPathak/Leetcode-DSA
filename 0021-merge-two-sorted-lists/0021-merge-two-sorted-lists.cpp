/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
         return list2;

        if(list2 == nullptr)
         return list1;


     ListNode* ansHead= nullptr;
     ListNode* ansTail= nullptr;
    while(list1!=nullptr && list2 != nullptr){
        
        if(list1->val > list2->val){
            //insert at head
            if(ansHead== nullptr){
                ansHead= list2;
                ansTail=list2;
            }
            else{
                ansTail->next= list2;
                ansTail=ansTail->next;              
            }
            list2=list2->next;
        }
        else{
             //insert at head
            
            if(ansHead== nullptr){
                ansHead = list1;
                ansTail = list1;

            }
            else{
                ansTail->next = list1;
                ansTail=ansTail->next;
                               
            }
        list1=list1->next;
        }
    }

while(list1!=nullptr){
    ListNode* temp= new ListNode(list1->val);
        ansTail->next = temp;
        ansTail= temp;                
        list1=list1->next;
}

while(list2!=nullptr){
    ListNode* temp= new ListNode(list2->val);
        ansTail->next = temp;
        ansTail= temp;                
        list2=list2->next;
}


return ansHead;

    }
};