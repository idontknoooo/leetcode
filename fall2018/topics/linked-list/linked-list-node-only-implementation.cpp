#include <iostream>
using namespace std;
class ListNode {
private:
  int value;
  ListNode* nxt;
public: 
  ListNode() : value(0), nxt(nullptr){};
  ListNode(int _value) : value(_value), nxt(nullptr) {};
  ListNode* get_next() {return this->nxt;}
  void set_next(ListNode* next_node) {this->nxt = next_node;}
  int get_value() {return value;}  
  void set_value(int val) {this->value = val;}
};


void print_list(ListNode* tmp) {
  while(tmp) {
    cout << tmp->get_value() << " ";
    tmp = tmp->get_next();
  }
  cout << endl;
}
int list_length(ListNode* tmp) {
  int ans = 0;
  while(tmp) {
    tmp = tmp->get_next();
    ++ans;
  }
  return ans;
}
int main() {

  ListNode* root = new ListNode(-1);
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(4);
  node1->set_next(node2);
  root->set_next(node1); 
  print_list(root);
  cout << root->get_value() << " " << root->get_next()->get_value() << " " << root->get_next()->get_next()->get_value() << endl;
  cout << list_length(root);
  return 0;
}
