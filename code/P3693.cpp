#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, R, C, X, Y, T, H;
int PX1, PX2, PY1, PY2;

struct Vec3 {
  int x, y, z;
  Vec3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
  Vec3 operator + (const Vec3& q)const {
    return Vec3(x + q.x, y + q.y, z + q.z);
  }
  bool operator != (const Vec3& q)const {
    return x != q.x or y != q.y or z != q.z;
  }
};

struct Door {
  int x, y, p, s, h;
  Door(int x = 0, int y = 0, int p = 0, int s = 0, int h = 0) : x(x), y(y), p(p), s(s), h(h) {}
  bool operator < (const Door& q)const {
    if (s != q.s)
      return s < q.s;
    if (h != q.h)
      return h > q.h;
    if (p != q.p)
      return p < q.p;
    if (x != q.x)
      return x < q.x;
    return y < q.y;
  }
} DR;

inline bool inRange(int x, int y, int z) {
  return y >= x and y <= z;
}

int IceBlock;
vector<Vec3> _2D4, _2D8, _3D6;

struct IceHouse {
  short V[20][20][30];
  IceHouse() {
    memset(V, 0, sizeof(V));
  }
  inline bool check(Vec3 q) {
    return inRange(0, q.x, N - 1) and inRange(0, q.y, N - 1) and inRange(0, q.z, M);
  }
  inline short g(Vec3 x) {
    if (not check(x))
      return -1;
    return V[x.x][x.y][x.z];
  }
  inline void f(Vec3 x) {
    V[x.x][x.y][x.z] = min(V[x.x][x.y][x.z] + 1, 4);
  }
  inline void c(Vec3 x, short v) {
    V[x.x][x.y][x.z] = v;
  }
} House;

inline void IceBarrage(int R, int C, int D, int S) {
  Vec3 v = _2D8[D], c = Vec3(R, C, 0);
  int s = 0;
  for (S++; S--; c = c + v) {
    if (not House.check(c) or House.g(c) == 5)
      break;
    if (House.g(c) != 4)
      ++s;
    House.f(c);
  }
  printf("CIRNO FREEZED %d BLOCK(S)
", s);
}

inline void MakeIceBlock() {
  int s = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (House.g(Vec3(i, j, 0)) == 4) {
        House.c(Vec3(i, j, 0), 0);
        ++s;
      }
  IceBlock += s;
  printf("CIRNO MADE %d ICE BLOCK(S),NOW SHE HAS %d ICE BLOCK(S)
", s, IceBlock);
}

inline bool AttachmentCheck(Vec3 v) {
  if (not v.z)
    return true;
  for (auto& x : _3D6)
    if (House.g(v + x) == 5)
      return true;
  return false;
}

inline void PutIceBlock(int r, int c, int h) {
  Vec3 v(r, c, h);
  if (not IceBlock) {
    printf("CIRNO HAS NO ICE_BLOCK
");
    return;
  }
  if (House.g(v) == 5 or not AttachmentCheck(v)) {
    printf("BAKA CIRNO,CAN'T PUT HERE
");
    return;
  }
  House.c(v, 5); --IceBlock;
  if (v.x < R or v.x > R + X - 1 or v.y < C or v.y > C + Y - 1)
    puts("CIRNO MISSED THE PLACE");
  else if (v.x >= R + 1 and v.x <= R + X - 2 and v.y >= C + 1 and v.y <= C + Y - 2)
    puts("CIRNO PUT AN ICE_BLOCK INSIDE THE HOUSE");
  else
    printf("CIRNO SUCCESSFULLY PUT AN ICE_BLOCK,NOW SHE HAS %d ICE_BLOCK(S)
", IceBlock);
}

int BrokenIce;
bool AttachmentIf;
bool hav[20][20][30];
vector<Vec3> List;

void dfsRemove(Vec3 v) {
  hav[v.x][v.y][v.z] = true;
  List.push_back(v);
  if (not v.z)
    AttachmentIf = true;
  for (auto& x : _3D6) {
    Vec3 p = v + x;
    if (House.g(p) == 5 and not hav[p.x][p.y][p.z])
      dfsRemove(p);
  }
}

inline void RemoveFloatIce(Vec3 v) {
  if (House.g(v) != 5)  return;
  AttachmentIf = false;
  dfsRemove(v);
  for (auto y : List)
    hav[y.x][y.y][y.z] = false;
  if (not AttachmentIf) {
    BrokenIce += List.size();
    for (auto& y : List)
      House.c(y, 0);
  }
  List.clear();
}

inline bool isFloatIce(Vec3 v) {
  if (House.g(v) != 5)  return false;
  AttachmentIf = false;
  dfsRemove(v);
  for (auto& y : List)
    hav[y.x][y.y][y.z] = false;
  List.clear();
  return not AttachmentIf;
}

inline void RemoveIceBlock(int r, int c, int h) {
  Vec3 v(r, c, h);
  if (House.g(v) != 5) {
    printf("BAKA CIRNO,THERE IS NO ICE_BLOCK
");
    return;
  }
  House.c(v, 0);
  BrokenIce = 0;
  for (auto& x : _3D6)
    RemoveFloatIce(v + x);
  if (BrokenIce)
    printf("CIRNO REMOVED AN ICE_BLOCK,AND %d BLOCK(S) ARE BROKEN
", BrokenIce);
  else
    puts("CIRNO REMOVED AN ICE_BLOCK");
  ++IceBlock;
}

vector<Vec3> Surround, Roof;

inline bool checkWall(Vec3 x) {
  return x.x == R or x.x == R + X - 1 or x.y == C or x.y == C + Y - 1;
}

inline bool checkInside(Vec3 x) {
  return inRange(R + 1, x.x, R + X - 2) and inRange(C + 1, x.y, C + Y - 2) and inRange(0, x.z, H - 1);
}

inline bool checkOutside(Vec3 x) {
  return not (inRange(R, x.x, R + X - 1) and inRange(C, x.y, C + Y - 1) and inRange(0, x.z, H));
}

inline bool checkPillar(Vec3 x) {
  return (x.x == R or x.x == R + X - 1) and (x.y == C or x.y == C + Y - 1);
}

inline bool checkPerfect(Vec3 x) {
  return x.x == PX1 or x.x == PX2 or x.y == PY1 or x.y == PY2;
}

inline void MakeRoof() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (inRange(R, i, R + X - 1) and inRange(C, j, C + Y - 1) and (not inRange(R + 1, i, R + X - 2) or not inRange(C + 1, j, C + Y - 2)))
        Surround.push_back(Vec3(i, j, 0));
      if (i >= R and i <= R + X - 1 and j >= C and j <= C + Y - 1)
        Roof.push_back(Vec3(i, j, 0));
    }
  for (auto& x : Surround) {
    for (int h = 0; h <= M; h++)
      if (House.g(x + Vec3(0, 0, h)) == 5)
        H = max(H, h + 1);
  }
  int nd = 0;
  for (auto& x : Roof)
    nd += House.g(x + Vec3(0, 0, H)) != 5;
  if (nd > IceBlock) {
    puts("SORRY CIRNO,NOT ENOUGH ICE_BLOCK(S) TO MAKE ROOF");
    return;
  }
  if (H < 1 or X == 2 or Y == 2 or (X == 3 and Y == 3 and H == 1)) {
    puts("SORRY CIRNO,HOUSE IS TOO SMALL");
    return;
  }
  for (auto& x : Roof)
    House.c(x + Vec3(0, 0, H), 5);
  IceBlock -= nd;
  int ins = 0, ous = 0;
  bool fixWall = false, removeBlock = false;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k <= M; k++)
        if (House.g(Vec3(i, j, k)) == 5) {
          if (checkInside(Vec3(i, j, k)))
            ins++;
          else if (checkOutside(Vec3(i, j, k)))
            ous++;
          else
            continue;
          IceBlock++;
          removeBlock = true;
          House.c(Vec3(i, j, k), 0);
          for (auto& x : _3D6) {
            Vec3 p = Vec3(i, j, k) + x;
            if (not checkWall(p))
              continue;
            if (isFloatIce(p)) {
              IceBlock++;
              House.c(p, 0);
            }
          }
        }
  printf("%d ICE_BLOCK(S) INSIDE THE HOUSE NEED TO BE REMOVED
", ins);
  printf("%d ICE_BLOCK(S) OUTSIDE THE HOUSE NEED TO BE REMOVED
", ous);
  if (isFloatIce(Vec3(R + 1, C + 1, H))) {
    printf("SORRY CIRNO,HOUSE IS BROKEN WHEN REMOVING BLOCKS
");
    return;
  }
  for (auto& x : Surround)
    if (not checkPillar(x))
      for (int h = 2; h < H; h++) {
        if (House.g(x + Vec3(0, 0, h)) == 5)
          continue;
        if (not IceBlock) {
          printf("SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL
");
          return;
        }
        House.c(x + Vec3(0, 0, h), 5);
        IceBlock--;
        fixWall = true;
      }
  nd = 0;
  for (auto x : Surround)
    if (not checkPillar(x))
      for (int h = 0; h < 2; h++)
        nd += House.g(x + Vec3(0, 0, h)) != 5;
  vector<Door> D; D.clear();
  for (auto& x : Surround)
    if (not checkPillar(x)) {
      int q = ((House.g(x) != 5) + (House.g(x + Vec3(0, 0, 1)) != 5));
      if (not q)
        continue;
      Door curr(x.x, x.y, checkPerfect(x), nd - q, q);
      for (auto& y : _2D4) if (checkPillar(x + y))
        for (int h = 0; h < 2; h++)
          if (House.g(x + Vec3(0, 0, h)) != 5)
            curr.s += (House.g(x + y + Vec3(0, 0, h)) != 5);
      D.push_back(curr);
    }
  sort(D.begin(), D.end());
  if (not D.size() or IceBlock < D.begin()->s) {
    printf("SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL
");
    return;
  }
  DR = *D.begin();
  if (IceBlock > DR.s and DR.h == 1)
    for (auto& d : D)
      if (d.h == 2) {
        DR = d;
        break;
      }
  Vec3 _DR = Vec3(DR.x, DR.y, 0);
  for (auto& y : _2D4)
    if (checkPillar(_DR + y))
      for (int h = 0; h < H; h++)
        if (House.g(_DR + y + Vec3(0, 0, h)) != 5 and House.g(_DR + Vec3(0, 0, h)) != 5) {
          --IceBlock; fixWall = true;
          House.c(_DR + y + Vec3(0, 0, h), 5);
        }
  for (auto& x : Surround)
    if (not checkPillar(x) and x != _DR)
      for (int h = 0; h < 2; h++) {
        if (House.g(x + Vec3(0, 0, h)) == 5)
          continue;
        House.c(x + Vec3(0, 0, h), 5);
        IceBlock--;
        fixWall = true;
      }
  printf("GOOD JOB CIRNO,SUCCESSFULLY BUILT THE HOUSE
");
  bool AllPerfect = true;
  if (DR.h == 2)  printf("DOOR IS OK
");
  else  printf("HOUSE HAS NO DOOR
"), AllPerfect = false;
  if (House.g(_DR) == 5)
    ++IceBlock; House.c(_DR, 0);
  if (House.g(_DR + Vec3(0, 0, 1)) == 5)
    ++IceBlock; House.c(_DR + Vec3(0, 0, 1), 0);
  if (fixWall) {
    printf("WALL NEED TO BE FIXED
");
    AllPerfect = false;
  } else
    printf("WALL IS OK
");
  nd = 0;
  for (auto& x : Surround)
    if (checkPillar(x))
      for (int h = 0; h < H; h++) {
        if (House.g(x + Vec3(0, 0, h)) == 5)
          continue;
        House.c(x + Vec3(0, 0, h), 5);
        nd++;
      }
  if (nd) {
    puts("CORNER NEED TO BE FIXED");
    AllPerfect = false;
  } else
    puts("CORNER IS OK");
  IceBlock = max(IceBlock - nd, 0);
  printf("CIRNO FINALLY HAS %d ICE_BLOCK(S)
", IceBlock);
  AllPerfect and_eq not removeBlock;
  AllPerfect and_eq DR.p;
  if (AllPerfect)
    puts("CIRNO IS PERFECT!");
}

int main() {
    ios_base::sync_with_stdio(false);
  _2D4 = vector<Vec3>{ Vec3(-1, 0, 0), Vec3(1, 0, 0), Vec3(0, -1, 0), Vec3(0, 1, 0) };
  _2D8 = vector<Vec3>{ Vec3(-1, 0, 0), Vec3(-1, -1, 0), Vec3(0, -1, 0), Vec3(1, -1, 0), Vec3(1, 0, 0), Vec3(1, 1, 0), Vec3(0, 1, 0), Vec3(-1, 1, 0) };
  _3D6 = vector<Vec3>{ Vec3(1, 0, 0), Vec3(-1, 0, 0), Vec3(0, 1, 0), Vec3(0, -1, 0), Vec3(0, 0, 1), Vec3(0, 0, -1) };
  cin >> N >> M >> R >> C >> X >> Y >> T;
  PX1 = R + (X >> 1);
  PX2 = R + (X - 1 >> 1);
  PY1 = C + (Y >> 1);
  PY2 = C + (Y - 1 >> 1);
  while (T--) {
    string op;
    cin >> op;
    if (op == "ICE_BARRAGE") {
      int r, c, d, s;
      cin >> r >> c >> d >> s;
      IceBarrage(r, c, d, s);
    } else if (op == "MAKE_ICE_BLOCK") {
      MakeIceBlock();
    } else if (op == "PUT_ICE_BLOCK") {
      int r, c, h;
      cin >> r >> c >> h;
      PutIceBlock(r, c, h);
    } else if (op == "REMOVE_ICE_BLOCK") {
      int r, c, h;
      cin >> r >> c >> h;
      RemoveIceBlock(r, c, h);
    } else
      MakeRoof();
  }
  return 0;
}