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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* p1 = dummy;
        
        while(head!=NULL){
            if(head->next!=NULL and head->val == head->next->val){
                while(head->next!=NULL and head->val == head->next->val){
                    head = head->next;
                }
                
                p1->next = head->next;
            }
            else{
                p1 = p1->next;
            }
            
            head = head->next;
        }
        
        return dummy->next;
    }
};