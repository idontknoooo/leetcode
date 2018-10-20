#include <iostream>

using namespace std;


struct ListNode { 
  int val;
  ListNode* nxt;
  ListNode() : val(0), nxt(nullptr) {}
  ListNode(int _val) : val(_val), nxt(nullptr) {}
};

struct LinkedList {
  ListNode* root;
  ListNode* tail;
  int len;
  LinkedList() {
    len = 0;
    root = new ListNode(-1);
    tail = root;
  }
  LinkedList(int _val) {
    len = 0;
    root = new ListNode(_val);
    tail = root;
  }
  int list_length() {return len;}
  void list_print() {
    if(root) {
      ListNode* tmp = root->nxt;
      while(tmp) {
        cout << tmp->val << " ";
        tmp = tmp->nxt;
      }
      cout << endl;
    }
  }
  void add(int val) {
    tail->nxt = new ListNode(val);
    tail = tail->nxt;
    ++len;
  }
  void remove() {
    ListNode* tmp = root;
    while(tmp && tmp->nxt) {
      if(tmp->nxt == tail) {
        --len;
        break;
      }
      tmp = tmp->nxt;
    }
    tail = tmp;
    tmp->nxt = nullptr;
  }
};
int main() {

  LinkedList* root = new LinkedList(-1);
  root->add(1);
  root->add(3);
  root->add(3);
  root->list_print();
  cout << root->list_length() << endl;
  root->remove();
  root->list_print();
  cout << root->list_length() << endl;

  root->remove();
  cout << "A" << endl;
  root->list_print();
  cout << root->list_length() << endl << endl;
  root->remove();
  cout << "B" << endl;
  root->list_print();
  cout << root->list_length() << endl << endl;
  root->remove();
  cout << "C" << endl;
  root->list_print();
  cout << root->list_length() << endl << endl;
  return 0;
}
