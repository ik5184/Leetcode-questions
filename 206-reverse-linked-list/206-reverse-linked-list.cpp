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
    private:
    void solve(ListNode* &head,ListNode* prev,ListNode* current){
        if(current==NULL){
            head=prev;
            return;
        }
        ListNode* forward=current->next;
        solve(head,current,forward);
        current->next=prev;
        
    }
    // void()
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* prev=NULL;
        ListNode* current=head;
        solve(head,prev,current);
        return head;
        
        
    }
};