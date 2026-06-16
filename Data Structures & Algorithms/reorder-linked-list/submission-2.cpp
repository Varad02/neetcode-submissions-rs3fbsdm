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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        while (head){
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* mid = findMid(head);
        ListNode* list2 = reverseList(mid);

        ListNode* list1 = head;
        while (list2){
            ListNode* tmp1 = list1->next;
            ListNode* tmp2 = list2->next;
            list1->next = list2;
            list2->next = tmp1;
            list1 = tmp1;
            list2 = tmp2;
        }
        if (list1) list1->next = nullptr;
    }
};
