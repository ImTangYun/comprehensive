#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void Print(ListNode* L)
{
    if (L == NULL) return;
    ListNode* p = L;
    while (p != NULL) {
        printf("%d  ", p->val);
        p = p->next;
    }
    printf("\n");
}

void create_list_by_array(ListNode** L, int* a, int length)
{
    if (length <= 0) {
        *L = NULL;
        return;
    }
    *L = new ListNode(a[0]);
    ListNode* p1 = *L;
    ListNode* p2 = NULL;
    for (int i = 1; i < length; ++i) {
        p2 = new ListNode(a[i]);
        p1->next = p2;
        p1 = p1->next;
    }
}

void Isertion(ListNode* head, ListNode* node)
{
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (p2 != NULL) {
        if (p2->val >= node->val) {
            break;
        }
        p1 = p2;
        p2 = p2->next;
    }
    if (p2 == NULL) {
        p1->next = node;
        node->next = NULL;
    } else {
        p1 = p2->next;
        p2->next = node;
        int tmp = node->val;
        node->val = p2->val;
        p2->val = tmp;
        node->next = p1;
    }
}

ListNode* Insertion_sort(ListNode* head)
{
    if (!head || !(head->next)) {
        return head;
    }
    ListNode* ret = head;
    ListNode* p = head->next;
    ret->next = NULL;
    while (p != NULL) {
        ListNode* p1 = p->next;
        p->next = NULL;
        Isertion(ret, p);
        p = p1;
    }
    return ret;
}

int main()
{
    ListNode *L1, *L2, *L3;
    int c[] = {1,3, 3, 3, 3};
    create_list_by_array(&L3, c, 5);
    Print(L3);
    ListNode* node = new ListNode(3);
    Isertion(L3, node);
    Print(L3);
    int d[] = {5,4,3,2,1};
    create_list_by_array(&L1, d, 5);
    ListNode* ret = Insertion_sort(L1);
    Print(ret);
    return 0;
}
