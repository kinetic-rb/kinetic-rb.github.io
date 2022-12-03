#include <iostream>

using namespace std;

inline void en(string postorder, string inorder) {
  if (postorder.empty())
    return;
  char Root = *postorder.begin();
  int k = inorder.find(Root);
  postorder.erase(postorder.begin());
  en(postorder.substr(0, k), inorder.substr(0, k));
  en(postorder.substr(k), inorder.substr(k + 1));
  cout << Root;

}

int main() {
  string post, in;
  cin >> in >> post;
  en(post, in);
  return 0;
}