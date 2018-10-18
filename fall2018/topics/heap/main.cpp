#include "heap.cpp"

using namespace std;

int main() {
  vector<int> vec = {2,3,4,5,16,7};
  print_vec(vec);
  vector<int> heap = heapify(vec, vec.size());
  vector<int> heap1 = heap;
  print_vec(heap);
  int cur_max = 0;
  while(heap.size()) {
    cur_max = extract_max(heap, heap.size());
    cout << cur_max << " ";
  }
  cout << endl;
  cout << size(heap) << endl;
  cout << is_empty_heap(heap) << endl;
  insert(heap, heap.size(), 1);
  insert(heap, heap.size(), 7);
  insert(heap, heap.size(), 2);
  insert(heap, heap.size(), 21);
  insert(heap, heap.size(), 11);
  print_vec(heap);
  replace(heap, heap.size(), 9);
  print_vec(heap);

  while(heap1.size()) {
    heap1 = delete_random(heap1, heap1.size());
    print_vec(heap1);
  }

  return 0;
}
