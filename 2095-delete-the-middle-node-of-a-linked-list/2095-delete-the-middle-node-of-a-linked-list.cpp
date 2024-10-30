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
    int findSize(ListNode* head){
        int answer = 1;
        while(head->next != nullptr){
            answer ++;
            head = head->next;
        }
        return answer;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int idx = findSize(head) /2;
        //std::cout << findSize(head) << std::endl;
        //std::cout << idx << std::endl;
        if(idx == 0){
            return nullptr;
        }
        ListNode* cur = head;
        ListNode* prev;
        ListNode* after;
        for(int i = 0 ; i <= idx; i++){
            if(i == idx-1){
                prev = cur;
                //std::cout << cur->val<<std::endl;
            }
            else if(i == idx){
                after = cur->next;
                //std::cout << after->val << std::endl;
            }
            cur = cur->next;
            
        }
        //std::cout << "prev val : " << prev->val << std::endl;
        //std::cout << "after val : " << after->val << std::endl;
        prev->next = after;
        return head;
    }
};