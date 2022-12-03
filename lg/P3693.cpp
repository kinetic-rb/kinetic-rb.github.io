#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, R, C, X, Y, T, H;
int PX1, PX2, PY1, PY2;

struct Vec3 {
\tint x, y, z;
\tVec3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
\tVec3 operator + (const Vec3& q)const {
\t\treturn Vec3(x + q.x, y + q.y, z + q.z);
\t}
\tbool operator != (const Vec3& q)const {
\t\treturn x != q.x or y != q.y or z != q.z;
\t}
};

struct Door {
\tint x, y, p, s, h;
\tDoor(int x = 0, int y = 0, int p = 0, int s = 0, int h = 0) : x(x), y(y), p(p), s(s), h(h) {}
\tbool operator < (const Door& q)const {
\t\tif (s != q.s)
\t\t\treturn s < q.s;
\t\tif (h != q.h)
\t\t\treturn h > q.h;
\t\tif (p != q.p)
\t\t\treturn p < q.p;
\t\tif (x != q.x)
\t\t\treturn x < q.x;
\t\treturn y < q.y;
\t}
} DR;

inline bool inRange(int x, int y, int z) {
\treturn y >= x and y <= z;
}

int IceBlock;
vector<Vec3> _2D4, _2D8, _3D6;

struct IceHouse {
\tshort V[20][20][30];
\tIceHouse() {
\t\tmemset(V, 0, sizeof(V));
\t}
\tinline bool check(Vec3 q) {
\t\treturn inRange(0, q.x, N - 1) and inRange(0, q.y, N - 1) and inRange(0, q.z, M);
\t}
\tinline short g(Vec3 x) {
\t\tif (not check(x))
\t\t\treturn -1;
\t\treturn V[x.x][x.y][x.z];
\t}
\tinline void f(Vec3 x) {
\t\tV[x.x][x.y][x.z] = min(V[x.x][x.y][x.z] + 1, 4);
\t}
\tinline void c(Vec3 x, short v) {
\t\tV[x.x][x.y][x.z] = v;
\t}
} House;

inline void IceBarrage(int R, int C, int D, int S) {
\tVec3 v = _2D8[D], c = Vec3(R, C, 0);
\tint s = 0;
\tfor (S++; S--; c = c + v) {
\t\tif (not House.check(c) or House.g(c) == 5)
\t\t\tbreak;
\t\tif (House.g(c) != 4)
\t\t\t++s;
\t\tHouse.f(c);
\t}
\tprintf("CIRNO FREEZED %d BLOCK(S)
", s);
}

inline void MakeIceBlock() {
\tint s = 0;
\tfor (int i = 0; i < N; i++)
\t\tfor (int j = 0; j < N; j++)
\t\t\tif (House.g(Vec3(i, j, 0)) == 4) {
\t\t\t\tHouse.c(Vec3(i, j, 0), 0);
\t\t\t\t++s;
\t\t\t}
\tIceBlock += s;
\tprintf("CIRNO MADE %d ICE BLOCK(S),NOW SHE HAS %d ICE BLOCK(S)
", s, IceBlock);
}

inline bool AttachmentCheck(Vec3 v) {
\tif (not v.z)
\t\treturn true;
\tfor (auto& x : _3D6)
\t\tif (House.g(v + x) == 5)
\t\t\treturn true;
\treturn false;
}

inline void PutIceBlock(int r, int c, int h) {
\tVec3 v(r, c, h);
\tif (not IceBlock) {
\t\tprintf("CIRNO HAS NO ICE_BLOCK
");
\t\treturn;
\t}
\tif (House.g(v) == 5 or not AttachmentCheck(v)) {
\t\tprintf("BAKA CIRNO,CAN'T PUT HERE
");
\t\treturn;
\t}
\tHouse.c(v, 5); --IceBlock;
\tif (v.x < R or v.x > R + X - 1 or v.y < C or v.y > C + Y - 1)
\t\tputs("CIRNO MISSED THE PLACE");
\telse if (v.x >= R + 1 and v.x <= R + X - 2 and v.y >= C + 1 and v.y <= C + Y - 2)
\t\tputs("CIRNO PUT AN ICE_BLOCK INSIDE THE HOUSE");
\telse
\t\tprintf("CIRNO SUCCESSFULLY PUT AN ICE_BLOCK,NOW SHE HAS %d ICE_BLOCK(S)
", IceBlock);
}

int BrokenIce;
bool AttachmentIf;
bool hav[20][20][30];
vector<Vec3> List;

void dfsRemove(Vec3 v) {
\thav[v.x][v.y][v.z] = true;
\tList.push_back(v);
\tif (not v.z)
\t\tAttachmentIf = true;
\tfor (auto& x : _3D6) {
\t\tVec3 p = v + x;
\t\tif (House.g(p) == 5 and not hav[p.x][p.y][p.z])
\t\t\tdfsRemove(p);
\t}
}

inline void RemoveFloatIce(Vec3 v) {
\tif (House.g(v) != 5)\treturn;
\tAttachmentIf = false;
\tdfsRemove(v);
\tfor (auto y : List)
\t\thav[y.x][y.y][y.z] = false;
\tif (not AttachmentIf) {
\t\tBrokenIce += List.size();
\t\tfor (auto& y : List)
\t\t\tHouse.c(y, 0);
\t}
\tList.clear();
}

inline bool isFloatIce(Vec3 v) {
\tif (House.g(v) != 5)\treturn false;
\tAttachmentIf = false;
\tdfsRemove(v);
\tfor (auto& y : List)
\t\thav[y.x][y.y][y.z] = false;
\tList.clear();
\treturn not AttachmentIf;
}

inline void RemoveIceBlock(int r, int c, int h) {
\tVec3 v(r, c, h);
\tif (House.g(v) != 5) {
\t\tprintf("BAKA CIRNO,THERE IS NO ICE_BLOCK
");
\t\treturn;
\t}
\tHouse.c(v, 0);
\tBrokenIce = 0;
\tfor (auto& x : _3D6)
\t\tRemoveFloatIce(v + x);
\tif (BrokenIce)
\t\tprintf("CIRNO REMOVED AN ICE_BLOCK,AND %d BLOCK(S) ARE BROKEN
", BrokenIce);
\telse
\t\tputs("CIRNO REMOVED AN ICE_BLOCK");
\t++IceBlock;
}

vector<Vec3> Surround, Roof;

inline bool checkWall(Vec3 x) {
\treturn x.x == R or x.x == R + X - 1 or x.y == C or x.y == C + Y - 1;
}

inline bool checkInside(Vec3 x) {
\treturn inRange(R + 1, x.x, R + X - 2) and inRange(C + 1, x.y, C + Y - 2) and inRange(0, x.z, H - 1);
}

inline bool checkOutside(Vec3 x) {
\treturn not (inRange(R, x.x, R + X - 1) and inRange(C, x.y, C + Y - 1) and inRange(0, x.z, H));
}

inline bool checkPillar(Vec3 x) {
\treturn (x.x == R or x.x == R + X - 1) and (x.y == C or x.y == C + Y - 1);
}

inline bool checkPerfect(Vec3 x) {
\treturn x.x == PX1 or x.x == PX2 or x.y == PY1 or x.y == PY2;
}

inline void MakeRoof() {
\tfor (int i = 0; i < N; i++)
\t\tfor (int j = 0; j < N; j++) {
\t\t\tif (inRange(R, i, R + X - 1) and inRange(C, j, C + Y - 1) and (not inRange(R + 1, i, R + X - 2) or not inRange(C + 1, j, C + Y - 2)))
\t\t\t\tSurround.push_back(Vec3(i, j, 0));
\t\t\tif (i >= R and i <= R + X - 1 and j >= C and j <= C + Y - 1)
\t\t\t\tRoof.push_back(Vec3(i, j, 0));
\t\t}
\tfor (auto& x : Surround) {
\t\tfor (int h = 0; h <= M; h++)
\t\t\tif (House.g(x + Vec3(0, 0, h)) == 5)
\t\t\t\tH = max(H, h + 1);
\t}
\tint nd = 0;
\tfor (auto& x : Roof)
\t\tnd += House.g(x + Vec3(0, 0, H)) != 5;
\tif (nd > IceBlock) {
\t\tputs("SORRY CIRNO,NOT ENOUGH ICE_BLOCK(S) TO MAKE ROOF");
\t\treturn;
\t}
\tif (H < 1 or X == 2 or Y == 2 or (X == 3 and Y == 3 and H == 1)) {
\t\tputs("SORRY CIRNO,HOUSE IS TOO SMALL");
\t\treturn;
\t}
\tfor (auto& x : Roof)
\t\tHouse.c(x + Vec3(0, 0, H), 5);
\tIceBlock -= nd;
\tint ins = 0, ous = 0;
\tbool fixWall = false, removeBlock = false;
\tfor (int i = 0; i < N; i++)
\t\tfor (int j = 0; j < N; j++)
\t\t\tfor (int k = 0; k <= M; k++)
\t\t\t\tif (House.g(Vec3(i, j, k)) == 5) {
\t\t\t\t\tif (checkInside(Vec3(i, j, k)))
\t\t\t\t\t\tins++;
\t\t\t\t\telse if (checkOutside(Vec3(i, j, k)))
\t\t\t\t\t\tous++;
\t\t\t\t\telse
\t\t\t\t\t\tcontinue;
\t\t\t\t\tIceBlock++;
\t\t\t\t\tremoveBlock = true;
\t\t\t\t\tHouse.c(Vec3(i, j, k), 0);
\t\t\t\t\tfor (auto& x : _3D6) {
\t\t\t\t\t\tVec3 p = Vec3(i, j, k) + x;
\t\t\t\t\t\tif (not checkWall(p))
\t\t\t\t\t\t\tcontinue;
\t\t\t\t\t\tif (isFloatIce(p)) {
\t\t\t\t\t\t\tIceBlock++;
\t\t\t\t\t\t\tHouse.c(p, 0);
\t\t\t\t\t\t}
\t\t\t\t\t}
\t\t\t\t}
\tprintf("%d ICE_BLOCK(S) INSIDE THE HOUSE NEED TO BE REMOVED
", ins);
\tprintf("%d ICE_BLOCK(S) OUTSIDE THE HOUSE NEED TO BE REMOVED
", ous);
\tif (isFloatIce(Vec3(R + 1, C + 1, H))) {
\t\tprintf("SORRY CIRNO,HOUSE IS BROKEN WHEN REMOVING BLOCKS
");
\t\treturn;
\t}
\tfor (auto& x : Surround)
\t\tif (not checkPillar(x))
\t\t\tfor (int h = 2; h < H; h++) {
\t\t\t\tif (House.g(x + Vec3(0, 0, h)) == 5)
\t\t\t\t\tcontinue;
\t\t\t\tif (not IceBlock) {
\t\t\t\t\tprintf("SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL
");
\t\t\t\t\treturn;
\t\t\t\t}
\t\t\t\tHouse.c(x + Vec3(0, 0, h), 5);
\t\t\t\tIceBlock--;
\t\t\t\tfixWall = true;
\t\t\t}
\tnd = 0;
\tfor (auto x : Surround)
\t\tif (not checkPillar(x))
\t\t\tfor (int h = 0; h < 2; h++)
\t\t\t\tnd += House.g(x + Vec3(0, 0, h)) != 5;
\tvector<Door> D; D.clear();
\tfor (auto& x : Surround)
\t\tif (not checkPillar(x)) {
\t\t\tint q = ((House.g(x) != 5) + (House.g(x + Vec3(0, 0, 1)) != 5));
\t\t\tif (not q)
\t\t\t\tcontinue;
\t\t\tDoor curr(x.x, x.y, checkPerfect(x), nd - q, q);
\t\t\tfor (auto& y : _2D4) if (checkPillar(x + y))
\t\t\t\tfor (int h = 0; h < 2; h++)
\t\t\t\t\tif (House.g(x + Vec3(0, 0, h)) != 5)
\t\t\t\t\t\tcurr.s += (House.g(x + y + Vec3(0, 0, h)) != 5);
\t\t\tD.push_back(curr);
\t\t}
\tsort(D.begin(), D.end());
\tif (not D.size() or IceBlock < D.begin()->s) {
\t\tprintf("SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL
");
\t\treturn;
\t}
\tDR = *D.begin();
\tif (IceBlock > DR.s and DR.h == 1)
\t\tfor (auto& d : D)
\t\t\tif (d.h == 2) {
\t\t\t\tDR = d;
\t\t\t\tbreak;
\t\t\t}
\tVec3 _DR = Vec3(DR.x, DR.y, 0);
\tfor (auto& y : _2D4)
\t\tif (checkPillar(_DR + y))
\t\t\tfor (int h = 0; h < H; h++)
\t\t\t\tif (House.g(_DR + y + Vec3(0, 0, h)) != 5 and House.g(_DR + Vec3(0, 0, h)) != 5) {
\t\t\t\t\t--IceBlock; fixWall = true;
\t\t\t\t\tHouse.c(_DR + y + Vec3(0, 0, h), 5);
\t\t\t\t}
\tfor (auto& x : Surround)
\t\tif (not checkPillar(x) and x != _DR)
\t\t\tfor (int h = 0; h < 2; h++) {
\t\t\t\tif (House.g(x + Vec3(0, 0, h)) == 5)
\t\t\t\t\tcontinue;
\t\t\t\tHouse.c(x + Vec3(0, 0, h), 5);
\t\t\t\tIceBlock--;
\t\t\t\tfixWall = true;
\t\t\t}
\tprintf("GOOD JOB CIRNO,SUCCESSFULLY BUILT THE HOUSE
");
\tbool AllPerfect = true;
\tif (DR.h == 2)\tprintf("DOOR IS OK
");
\telse\tprintf("HOUSE HAS NO DOOR
"), AllPerfect = false;
\tif (House.g(_DR) == 5)
\t\t++IceBlock; House.c(_DR, 0);
\tif (House.g(_DR + Vec3(0, 0, 1)) == 5)
\t\t++IceBlock; House.c(_DR + Vec3(0, 0, 1), 0);
\tif (fixWall) {
\t\tprintf("WALL NEED TO BE FIXED
");
\t\tAllPerfect = false;
\t} else
\t\tprintf("WALL IS OK
");
\tnd = 0;
\tfor (auto& x : Surround)
\t\tif (checkPillar(x))
\t\t\tfor (int h = 0; h < H; h++) {
\t\t\t\tif (House.g(x + Vec3(0, 0, h)) == 5)
\t\t\t\t\tcontinue;
\t\t\t\tHouse.c(x + Vec3(0, 0, h), 5);
\t\t\t\tnd++;
\t\t\t}
\tif (nd) {
\t\tputs("CORNER NEED TO BE FIXED");
\t\tAllPerfect = false;
\t} else
\t\tputs("CORNER IS OK");
\tIceBlock = max(IceBlock - nd, 0);
\tprintf("CIRNO FINALLY HAS %d ICE_BLOCK(S)
", IceBlock);
\tAllPerfect and_eq not removeBlock;
\tAllPerfect and_eq DR.p;
\tif (AllPerfect)
\t\tputs("CIRNO IS PERFECT!");
}

int main() {
    ios_base::sync_with_stdio(false);
\t_2D4 = vector<Vec3>{ Vec3(-1, 0, 0), Vec3(1, 0, 0), Vec3(0, -1, 0), Vec3(0, 1, 0) };
\t_2D8 = vector<Vec3>{ Vec3(-1, 0, 0), Vec3(-1, -1, 0), Vec3(0, -1, 0), Vec3(1, -1, 0), Vec3(1, 0, 0), Vec3(1, 1, 0), Vec3(0, 1, 0), Vec3(-1, 1, 0) };
\t_3D6 = vector<Vec3>{ Vec3(1, 0, 0), Vec3(-1, 0, 0), Vec3(0, 1, 0), Vec3(0, -1, 0), Vec3(0, 0, 1), Vec3(0, 0, -1) };
\tcin >> N >> M >> R >> C >> X >> Y >> T;
\tPX1 = R + (X >> 1);
\tPX2 = R + (X - 1 >> 1);
\tPY1 = C + (Y >> 1);
\tPY2 = C + (Y - 1 >> 1);
\twhile (T--) {
\t\tstring op;
\t\tcin >> op;
\t\tif (op == "ICE_BARRAGE") {
\t\t\tint r, c, d, s;
\t\t\tcin >> r >> c >> d >> s;
\t\t\tIceBarrage(r, c, d, s);
\t\t} else if (op == "MAKE_ICE_BLOCK") {
\t\t\tMakeIceBlock();
\t\t} else if (op == "PUT_ICE_BLOCK") {
\t\t\tint r, c, h;
\t\t\tcin >> r >> c >> h;
\t\t\tPutIceBlock(r, c, h);
\t\t} else if (op == "REMOVE_ICE_BLOCK") {
\t\t\tint r, c, h;
\t\t\tcin >> r >> c >> h;
\t\t\tRemoveIceBlock(r, c, h);
\t\t} else
\t\t\tMakeRoof();
\t}
\treturn 0;
}