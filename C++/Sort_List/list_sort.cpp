/**
 *1.从链表中间切断
 *2.对上面得到的两个字链表重复以上过程
 *3.当链表不可再分的时候，有序归并
 *
 */

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
ListNode* merge(ListNode* L1, ListNode* L2)
{
    if (L1 == NULL) {
        return L2;
    }
    if (L2 == NULL) {
        return L1;
    }
    ListNode* head = NULL;
    ListNode* p1 = L1, *p2 = L2, *p, *pre;
    if (p1->val > p2->val) {
        head = p2;
        p2 = p2->next;
    } else {
        head = p1;
        p1 = p1->next;
    }
    pre = head;
    while (true) {
        if (p1 == NULL) {
            pre->next = p2;
            break;
        }
        if (p2 == NULL) {
            pre->next = p1;
            break;
        }
        if (p1->val > p2->val) {
            pre->next = p2;
            p2 = p2->next;
        } else {
            pre->next = p1;
            p1 = p1->next;
        }
        pre = pre->next;
    }
    return head;
}

void split(ListNode** L1, ListNode** L2, ListNode* L)
{
    if (L == NULL || L->next == NULL) {
        *L1 = L;
        *L2 = NULL;
        return;
    }
    int count = 0;
    ListNode* p1 = L;
    while (p1) {
        ++count;
        p1 = p1->next;
    }
    count = count / 2;
    *L1 = L->next;
    *L2 = L;
    p1 = L;
    for (int i = 1; i < count; ++i) {
        p1 = *L1;
        *L1 = (*L1)->next;
    }
    p1->next = NULL;
}

ListNode* merge_sort(ListNode* L)
{
    if (L == NULL || L->next == NULL) {
        return L;
    }
    ListNode* p1;
    ListNode* p2;
    split(&p1, &p2, L);
    ListNode* L1 = merge_sort(p1);
    ListNode* L2 = merge_sort(p2);
    ListNode* m = merge(L1, L2);
    return m;
}

int main()
{
    ListNode *L1, *L2, *L3;
    int a[] = {1, 1, 2};
    int b[] = {2};
    int c[] = {2, 5, 4, 7, 3, 3, 3, 2, 3, 1, 3}; // ,2,5,6,7,4,5,9};
    // int c[] = {2,3,2,2,2};
    // int c[] = {-84,142,41,-17,-71,170,186,183,-21,-76,76,10,29,81,112,-39,-6,-43,58,41,111,33,69,97,-38,82,-44,-7,99,135,42,150,149,-21,-30,164,153,92,180,-61,99,-81,147,109,34,98,14,178,105,5,43,46,40,-37,23,16,123,-53,34,192,-73,94,39,96,115,88,-31,-96,106,131,64,189,-91,-34,-56,-22,105,104,22,-31,-43,90,96,65,-85,184,85,90,118,152,-31,161,22,104,-85,160,120,-31,144,115};
    create_list_by_array(&L1, a, 3);
    create_list_by_array(&L2, b, 1);
    ListNode* ab = merge(L1, L2);
    Print(ab);
    create_list_by_array(&L3, c, 11);
    Print(L3);
    ListNode* ret = merge_sort(L3);
    Print(ret);
    return 0;
}
