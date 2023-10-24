#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* newListNode() {
    struct ListNode* output = malloc(sizeof(struct ListNode));
    output->val = 666;
    output->next = NULL;
    return output;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode output;
    struct ListNode* referencer = &output;
    
    int carry = 0;
    int curNum = 0;
    int add = 0;

    while(l1!=NULL) {
        if (l2!=NULL) {
            add = l2->val;
            l2 = l2->next;
        } else {
            add = 0;
        }
        curNum = l1->val + add + carry;
        carry = curNum/10;
        if (carry>=1) {
            curNum = curNum - (carry*10);
        }

        referencer->val = curNum;
        referencer->next = newListNode();
        referencer = referencer->next;
        

        //printf("%d, %d|", curNum, carry);

        l1 = l1->next;
    }

    printf("%d %d %d", output.val, output.next->val, output.next->next->val);

    return &output;
}

int main()
{
    struct ListNode* l1 = newListNode();
    l1->val = 2;
    l1->next = newListNode();
    l1->next->val = 4;
    l1->next->next = newListNode();
    l1->next->next->val = 3;
    l1->next->next->next = NULL;
    
    struct ListNode* l2 = newListNode();
    l2->val = 5;
    l2->next = newListNode();
    l2->next->val = 6;
    l2->next->next = newListNode();
    l2->next->next->val = 4;
    l2->next->next->next = NULL;
    
    struct ListNode* sum = addTwoNumbers(l1,l2);
}
