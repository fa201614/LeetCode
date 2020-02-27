/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*struct ListNode *reverse_list(struct ListNode *list) {
    struct ListNode *tail = list;
    struct ListNode *p = list;
    struct ListNode *fast;
    while (tail->next != NULL) tail = tail->next;
    while (p != tail) {
        fast = p->next;
        p->next = tail->next;
        tail->next = p;
        p = fast;
    }
    return tail;
}

bool process(struct ListNode *list, const int length) {
    if (list == NULL) return false;
    bool re = true;
    struct ListNode *slow = list;
    struct ListNode *fast = list;
    if ((length & 1) == 0) fast = fast->next; //提前走一步　为了找到tail
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *mid = slow;
    slow = slow->next;//中后的第一个位置
    struct ListNode *new_head = reverse_list(slow);
    slow = new_head;
    fast = list;
    while (slow != NULL) {
        if (slow->val != fast->val) {
            re = false;
            break;
        }
        slow = slow->next;
        fast = fast->next;
    }
    //恢复ｌｉｓｔ
    new_head = reverse_list(new_head);
    mid->next = new_head;
    return re;
}

bool isPalindrome(struct ListNode* head){
    struct ListNode *p = head;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    if (length <= 1) return true;
    return process(head, length); 
}*/

int get_length(struct ListNode *head) {
    int n = 0;
    while (head) n += 1, head = head->next;
    return n;
}

struct ListNode* reverse(struct ListNode *head, int n) {
    struct ListNode ret, *p = head, *q;
    while (n--) p = p->next;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome(struct ListNode* head) {
    int len = get_length(head);
    struct ListNode *p = head, *q = reverse(head, (len + 1) / 2);
    while (q) {
        if (p->val - q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}
