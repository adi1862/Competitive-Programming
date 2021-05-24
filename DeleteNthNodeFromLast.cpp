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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // advance one pointer to n-1
        ListNode* temp = head;
        
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        if(!temp)return head->next;
        
        ListNode* slow = head;
        while(temp->next != nullptr){
            slow=slow->next;
            temp=temp->next;
        }
            slow->next=slow->next->next;
        return head;
        
    }
};
