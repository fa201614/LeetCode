/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//循环一遍，判断当前结点与下一节点的值是否相等，相等的话直接让当前结点的next指向下下节点。
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head, *q;
    while (p && p->next) {
        if (p->val - p->next->val) {
            p = p->next;
        } else {
            q = p->next;
            p->next = q->next;
            free(q);
        }
    }
    return head;
}
