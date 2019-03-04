/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * author:xiajun
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    int enter=0,sum=0;   
    result->val=(p1->val+p2->val)%10;   
    struct ListNode *prev=result;
    if(10 <= p1->val+p2->val) {
            enter=1;
    }    
    while (p1->next || p2->next) {
        if(p1->next) {
            p1=p1->next;
        } else {
            p1->val=0;
        }        
        if(p2->next) {
            p2=p2->next;
        } else {
            p2->val=0;
        }
        struct ListNode *nextNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        sum = p1->val+p2->val+enter;
        nextNode->val = sum%10;        
        prev->next = nextNode;
        prev = nextNode;
        enter = 10 <= sum ? 1 : 0;
    }
    if(1 == enter) {
       struct ListNode *nextNode = (struct ListNode *)malloc(sizeof(struct ListNode));
       nextNode->val=1;        
       prev->next = nextNode;
       prev=nextNode;        
    }
    prev->next = NULL;
    return result;
    
}