#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
  bool is_word;
  vector<TrieNode*> children;
  TrieNode() {
    is_word = false;
    children = vector<TrieNode*>(26, nullptr);
  }
  ~TrieNode() {
    for(TrieNode* child : children)
      if(child) delete child;
  }
};
void insert(TrieNode* root, const string& word) {
  for(char letter : word) {
    if(!root->children[letter - 'a']) {
      root->children[letter - 'a'] = new TrieNode();
    }
    root = root->children[letter - 'a'];
  }  
  root->is_word = true;
}
bool search(TrieNode* root, const string& word) {
  for(char letter : word) {
    if(!root->children[letter - 'a'])
      return false;
    root = root->children[letter - 'a'];
  }
  return root->is_word;
}
bool startsWith(TrieNode* root, const string& prefix) {
  for(char letter : prefix) {
    if(!root->children[letter - 'a'])
      return false;
    root = root->children[letter - 'a'];
  }
  return true;

}
int main() {
  TrieNode* root = new TrieNode();
  //print_trieNode(root);
  insert(root, "apple");
  insert(root, "aka");
  TrieNode* a = root->children[0];
  TrieNode* ap = a->children[15];
  TrieNode* app = ap->children[15];
  TrieNode* appl = app->children[11];
  TrieNode* apple = appl->children[4];
  cout << a->is_word << endl;
  cout << ap->is_word << endl;
  cout << app->is_word << endl;
  cout << appl->is_word << endl;
  cout << apple->is_word << endl << endl;
  cout << search(root, "app") << endl;
  cout << startsWith(root, "app") << endl;
  cout << search(root, "apple") << endl;
  cout << startsWith(root, "apple") << endl;
  cout << search(root, "aka") << endl;
  cout << startsWith(root, "a") << endl;
  cout << search(root, "ak") << endl;
  return 0;
}
