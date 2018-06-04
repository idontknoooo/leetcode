// My solution 15ms beat 62%
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; i++) factorial[i] = factorial[i - 1] * i;
        k--; // if k = 1, 0 / factorial[i - 1] = 0
        for (int i = n; i >= 1; i--){
            int j = k / factorial[i - 1];
            k %= factorial[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};

// 14ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        int c = 0;
        ListNode *p = head;
        while (p) {
            p = p->next;
            c++;
        }
        int n = k % c;
        if (n == 0) return head;
        ListNode *first = head;
        ListNode *second = head;
        while(--n && first) {
            first = first->next;
        }
        ListNode *last = first;
        while (first->next) {
            last = second;
            first = first->next;
            second = second->next;
        }
        first->next = head;
        last->next = NULL;
        return second;
    }
};
