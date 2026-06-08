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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head) return head;
        ListNode* node = head, *nextNode;
        while (node->next) {
            nextNode = node->next;
            ListNode* newNode = new ListNode(__gcd(node->val, nextNode->val));
            newNode->next = nextNode;
            node->next = newNode;
            node = nextNode;
        }
        return head;
    }
};