#include <iostream>

using namespace std;

inline void en(string postorder, string inorder) {
\tif (postorder.empty())
\t\treturn;
\tchar Root = *postorder.begin();
\tint k = inorder.find(Root);
\tpostorder.erase(postorder.begin());
\ten(postorder.substr(0, k), inorder.substr(0, k));
\ten(postorder.substr(k), inorder.substr(k + 1));
\tcout << Root;

}

int main() {
\tstring post, in;
\tcin >> in >> post;
\ten(post, in);
\treturn 0;
}