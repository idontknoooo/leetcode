#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
// Print vector
void print_vec(vector<int> vec) {
  for(int i = 0; i < vec.size(); ++i) 
    cout << vec[i] << " ";
  cout << endl;
}
// Swap two numbers in vector
void swap(vector<int> & vec, int pos1, int pos2) {
  int tmp = vec[pos1];
  vec[pos1] = vec[pos2];
  vec[pos2] = tmp;
}
// Internal
// Sift the last number top, which will make vec a heap after a push_back
void sift_up(vector<int>& vec, int len) {
  int cur_pos = len - 1;
  int parent_pos = (cur_pos-1)/2;
  while( parent_pos >= 0 && vec[parent_pos] < vec[cur_pos]) {
    swap(vec, parent_pos, cur_pos);
    cur_pos = parent_pos;
    parent_pos = (cur_pos-1)/2;
  }
}
// Sift the first number down, which will make vec a heap after a delete root
void sift_down(vector<int>& vec, int len) {
  int current = 0;
  int child1 = 2 * current + 1;
  int child2 = 2 * current + 2;
  while(child1 < len && vec[child1] > vec[current] || child2 < len && vec[child2] > vec[current]) {
    int child = child2;
    if(vec[child1] > vec[current]) {
      child = vec[child1] > vec[child2]? child1 : child2; 
      swap(vec, child, current);
    } else {
      swap(vec, child2, current);
    }
    current = child;
    child1 = 2 * current + 1;
    child2 = 2 * current + 2;
  }
}
// delete a random number and make it a heap again
vector<int> delete_random(vector<int>& vec, int len) {
  srand(time(NULL));
  int pick_pos = rand() % len;
  vector<int> ans;
  for(int i = 0; i < len; i++) {
    if(i == pick_pos) continue;
    ans.push_back(vec[i]);
    sift_up(ans, ans.size());
  }
  return ans;
}
// Basic
// Assume only have non-negative numbers
int find_max(vector<int> vec, int len) {
  if(vec.size()) 
    return vec[0];
  else 
    return -1;
}
// Insert a number and keep heap
vector<int> insert(vector<int>& vec, int len, int val) {
  vec.push_back(val);
  sift_up(vec, len+1);
  return vec;
}
// Extract root and keep heap
int extract_max(vector<int>& vec, int len) {
  int ans = -1;
  if(vec.size()) {
    ans = vec[0];
    swap(vec, 0, vec.size()-1);
    vec.pop_back();
    sift_down(vec, len-1);
  }
  return ans;
}
// Delete max number and keep heap and don't return val
vector<int> delete_max(vector<int>& vec, int len) {
  if(vec.size()) {
    swap(vec, 0, vec.size()-1);
    vec.pop_back();
    sift_down(vec, len);
  }
  return vec;
}
// Replace root to val
vector<int> replace(vector<int>& vec, int len, int val) {
  if(vec.size()) {
    vec[0] = val;
    sift_down(vec, len);
  }
  return vec;
}

// Creation
// Create empty heap
vector<int> create_heap() {
  return {};
}
// Make a vector to a heap
vector<int> heapify(vector<int> vec, int len) {
  vector<int> ans;
  for(int i = 0; i < len; i++) {
    ans.push_back(vec[i]);
    sift_up(ans, ans.size());
  }
  return ans;
}
// Merge two heap to a new heap
vector<int> merge(vector<int> vec1, int len1, vector<int> vec2, int len2) {
  vector<int> ans;
  for(auto ele : vec1) {
    ans.push_back(ele);
    sift_up(ans, ans.size());
  }
  for(auto ele : vec2) {
    ans.push_back(ele);
    sift_up(ans, ans.size());
  }
  return ans;
}

// Inspection
// Size of heap
int size(vector<int> vec) {
  return vec.size();
}
// Empty heap
bool is_empty_heap(vector<int> vec) {
  return !vec.size();
}
