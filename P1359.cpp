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

\tinline void operator () (const unsigned& size = 0) {
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

memory<int> f;

int main() {
\tint n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
\t\t\tint x;
            cin >> x;
            if (!f[j] || f[j] > f[i] + x)
                f[j] = f[i] + x;
        }
    cout << f[n];
    return 0;
}