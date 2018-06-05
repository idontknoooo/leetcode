// 50ms
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*>m;
        auto p = head;
        while(p){
            m[p] = new RandomListNode(p->label);
            p = p->next;
        }
        p = head;
        while(p){
            m[p]->next = m[p->next];
            m[p]->random = m[p->random];
            p = p->next;
        }
        return m[head];
    }
};

// 42ms
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        RandomListNode* newHead, * l1, * l2;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }
        
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            if (l1->random) l1->next->random = l1->random->next;
        }
        
        newHead = head->next;
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next) l2->next = l2->next->next;
        }
        
        return newHead;
    }
};
