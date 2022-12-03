#include <iostream>

using namespace std;

template<typename Typex>
class memory {
\tunsigned _alocked;
\tTypex* elespace;
public:
\tusing iterator = Typex*;
\tmemory(const unsigned& size = 0) {
\t\telespace = new Typex[_alocked = size];
\t}

\tmemory(const unsigned& size, const Typex& val) {
\t\telespace = new Typex[_alocked = size];
\t\tfor (unsigned i = 0; i < size; i++) {
\t\t\telespace[i] = val;
\t\t}
\t}

\tinline unsigned size() {
\t\treturn _alocked;
\t}

\tinline void resize(const unsigned& size) {
\t\tauto tmp = new Typex[_alocked];
\t\tfor (unsigned i = 0; i < _alocked; i++)
\t\t\ttmp[i] = elespace[i];
\t\tdelete[] elespace;
\t\telespace = new Typex[size];
\t\tfor (unsigned i = 0; i < _alocked; i++)
\t\t\telespace[i] = tmp[i];
\t\t_alocked = size;
\t}

\tinline void operator () (const unsigned& size) {
\t\tdelete[] elespace;
\t\telespace = new Typex[_alocked = size];
\t}

\tinline void operator () (const unsigned& size, const Typex& val) {
\t\tdelete[] elespace;
\t\telespace = new Typex[_alocked = size];
\t\tfor (unsigned i = 0; i < size; i++) {
\t\t\telespace[i] = val;
\t\t}
\t}

\tinline Typex& operator [] (const unsigned& x) {
\t\tif (x >= _alocked)
\t\t\tresize(x + 1);
\t\treturn elespace[x];
\t}

\tinline void push(const Typex& val) {
\t\tresize(_alocked + 1);
\t\telespace[_alocked - 1] = val;
\t}

\tinline void pop() {
\t\tresize(_alocked - 1);
\t}

\tinline Typex* begin() {
\t\treturn elespace;
\t}

\tinline Typex* end() {
\t\treturn elespace + _alocked;
\t}

\tinline bool empty() {
\t\treturn _alocked;
\t}

\t~memory() {
\t\tdelete[] elespace;
\t}
};

inline void en(string postorder, string inorder) {
\tif (postorder.empty())
\t\treturn;
\tchar Root = *(postorder.end() - 1);
\tint k = inorder.find(Root);
\tpostorder.erase(postorder.end() - 1);
\tcout << Root;
\ten(postorder.substr(0, k), inorder.substr(0, k));
\ten(postorder.substr(k), inorder.substr(k + 1));

}

int main() {
\tstring post, in;
\tcin >> in >> post;
\ten(post, in);
\treturn 0;
}

/*
\t\t\t _____     _____
inorder:    |__L__| V |__R__|
\t\t\t   _____   _____
postorder:  V |__L__| |__R__|
*/