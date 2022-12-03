#include <iostream>
#include <algorithm>

using namespace std;

template<typename Typex>
class barry {
protected:
\tint _alocked = 0;
\tTypex* elespace;
public:
\tbarry(const int& size = 0) {
\t\telespace = new Typex[_alocked = size];
\t}

\tbarry(const int& size, const int& val) {
\t\telespace = new Typex[_alocked = size];
\t\tfor (int i = 0; i < size; i++) {
\t\t\telespace[i] = val;
\t\t}
\t}

\tinline int size() {
\t\treturn _alocked;
\t}

\tinline void resize(const int& size) {
\t\tauto tmp = new Typex[_alocked];
\t\tfor (int i = 0; i < _alocked; i++)
\t\t\ttmp[i] = elespace[i];
\t\tdelete[] elespace;
\t\telespace = new Typex[size];
\t\tfor (int i = 0; i < _alocked; i++)
\t\t\telespace[i] = tmp[i];
\t\t_alocked = size;
\t}

\tinline Typex& operator [] (const int& x) {
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

\t~barry() {
\t\tdelete[] elespace;
\t}
};

struct cor {
\tstring name;
\tint mark;
};

int main() {
\tint n;
\tcin >> n;
\tbarry<cor> s;
\tfor (int i = 0; i < n; i++) {
\t\tstring name;
\t\tint mark;
\t\tcin >> mark >> name;
\t\ts.push({ name, mark });
\t}
\tcout << max_element(s.begin(), s.end(), [](const cor& x, const cor& y) {
\t\treturn x.mark < y.mark;
\t})->name;
\treturn 0;
}