/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode * p1;
    struct ListNode * p2;
    struct ListNode * p3;

    if (head == NULL){
        return head;
    }

    p1 = head;
    p2 = head->next;

    while(1){
        if (p2==NULL){
            head = p1;
            break;
        }

        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    return head;
}