// By rbtree (https://rbtree.dev)
#define ABE for (int i = 0; (!q[0].empty() || !q[1].empty()) && !z; i++) {  /*\u7ffb\u8f6c\u6b21\u6570\uff0c\u961f\u5217\u4ea4\u6362\u7f16\u53f7\u53ef\u901a\u8fc7i%2\u5b9e\u73b0*/
#define ABD if ((x <= 1 && (d % 2)) || (x >= n && !(d % 2)) || y < 1 || y > m || b[x][y][d % 2] || c[x][y] == '#') {
#define ABC cout << ((b[x2][y2][1]) || (b[x2][y2][0]) ? v[x2][y2] : -1);  /*\u5224\u65ad\u7ec8\u70b9\u662f\u5426\u5230\u8fbe*/
#define ABB Record(x1, y1, 0);                                              /*\u8d77\u70b9\u5165\u961f*/
#define ABA z = 1;                 /*\u6807\u8bb0\u53ef\u4ee5\u9000\u51faBFS\uff0c\u53ef\u4ee5\u4f18\u5316\u4e00\u70b9\u5e38\u6570*/
#define AB9 int v[kMaxN][kMaxN];         /*\u8bb0\u5f55\u5230\u8fbe\u6bcf\u4e2a\u70b9\u8981\u7ffb\u8f6c\u7684\u6b21\u6570*/
#define AB8 void Record(int x, int y, int d) {  /*\u70b9\u7684\u5750\u6807\uff0c\u7ffb\u8f6c\u7684\u6b21\u6570*/
#define AB7 if (x <= 1 || b[x][y][d % 2]) {  /*\u5760\u5165\u6df1\u6e0a\u6216\u5df2\u7ecf\u5230\u8fbe*/
#define AB6 if (i % 2) {                      /*\u5904\u7406\u4e0b\u5c42\u72b6\u6001*/
#define AB5 for (int j = 0; j < 2; j++) {  /*\u5904\u7406\u540c\u5c42\u72b6\u6001*/
#define AB4 if (c[x - 1][y] == '#') {  /*\u4e0a\u9762\u4e0d\u662f\u7a7a\u7684*/
#define AB3 v[x][y] = d;               /*\u8bb0\u5f55\u7ffb\u8f6c\u6b21\u6570*/
#define AB2 if (c[x + 1][y] == '#') {  /*\u4e0b\u9762\u4e0d\u662f\u7a7a\u7684*/
#define AB1 Record(u.x - 1, u.y, u.d + 1);  /*\u7ffb\u8f6c\u91cd\u529b*/
#define AB0 Record(u.x + 1, u.y, u.d + 1);  /*\u7ffb\u8f6c\u91cd\u529b*/
#define AAF if (c[x][y] == 'D') {    /*\u5982\u679c\u641c\u5230\u7ec8\u70b9*/
#define AAE b[x2][y2][d % 2] = 1;  /*\u6807\u8bb0\u7ec8\u70b9\u5230\u8fbe*/
#define AAD v[x2][y2] = d;         /*\u8bb0\u5f55\u7ffb\u8f6c\u6b21\u6570*/
#define AAC bool b[kMaxN][kMaxN][2], z;  /*\u6807\u8bb0\u6570\u7ec4*/
#define AAB queue<Node> q[2];            /*\u4e24\u4e2a\u961f\u5217*/
#define AAA /*freopen("gravity.out", "w", stdout);*/
#define AA9 if (c[i][j] == 'D') {  /*\u8bb0\u5f55\u7ec8\u70b9*/
#define AA8 if (c[i][j] == 'C') {  /*\u8bb0\u5f55\u8d77\u70b9*/
#define AA7 /*freopen("gravity.in", "r", stdin);*/
#define AA6 q[d % 2].push({x, y, d});  /*\u5165\u961f*/
#define AA5 b[x][y][d % 2] = 1;        /*\u6807\u8bb0*/
#define AA4 if (d % 2) {  /*\u5f53\u524d\u91cd\u529b\u671d\u4e0a*/
#define AA3 std::ios::sync_with_stdio(false);
#define AA2 x++;  /*\u5f80\u4e0b\u843d*/
#define AA1 x--;  /*\u50cf\u4e0a\u843d*/
#define AA0 c[kMaxN][kMaxN];
#define A9F ___0xffff___
#define A9E 2].front();
#define A9D 2].empty())
#define A9C 0x63357a67
#define A9B 0x6336cc23
#define A9A Record(u.x
#define A99 kD[j][0],
#define A98 namespace
#define A97 b[x][y][d
#define A96 kD[j][1],
#define A95 2].pop();
#define A94 kD[2][2]
#define A93 c[i][j];
#define A92 return;
#define A91 Work();
#define A90 return
#define A8F Work()
#define A8E struct
#define A8D printf
#define A8C break;
#define A8B const
#define A8A -1}};
#define A89 kMaxN
#define A88 (!q[i
#define A87 using
#define A86 while
#define A85 u.d);
#define A84 0xa8
#define A83 0xaa
#define A82 0xb1
#define A81 0xb4
#define A80 0xb5
#define A7F 0xb7
#define A7E 0xb9
#define A7D 0xbc
#define A7C 0xc1
#define A7B 0xc2
#define A7A 0xc3
#define A79 0xc6
#define A78 0xc7
#define A77 0xc8
#define A76 0xca
#define A75 0xcb
#define A74 0xcc
#define A73 0xce
#define A72 0xcf
#define A71 0xd0
#define A70 0xd1
#define A6F 0xd2
#define A6E 0xd3
#define A6D 0xd4
#define A6C 0xd5
#define A6B 0xd7
#define A6A 0xda
#define A69 0xde
#define A68 0xdf
#define A67 0xe7
#define A66 0xeb
#define A65 0xf7
#define A64 0xf8
#define A63 0xfa
#define A62 0xfd
#define A61 501;
#define A60 Node
#define A5F 0x2f
#define A5E char
#define A5D else
#define A5C i++)
#define A5B "%s"
#define A5A "\n"
#define A59 j++)
#define A58 (int
#define A57 0x20
#define A56 0x23
#define A55 0x2d
#define A54 main
#define A53 0x2e
#define A52 0x3a
#define A51 0x61
#define A50 0x62
#define A4F 0x63
#define A4E 0x64
#define A4D 0x65
#define A4C std;
#define A4B 0x66
#define A4A time
#define A49 0x68
#define A48 0x6d
#define A47 0xe8
#define A46 0x6f
#define A45 void
#define A44 0x70
#define A43 0x73
#define A42 0x74
#define A41 0x78
#define A40 0xa7
#define A3F {{0,
#define A3E q[i
#define A3D y1,
#define A3C 0xa
#define A3B (1)
#define A3A {0,
#define A39 y2;
#define A38 0x0
#define A37 cin
#define A36 u.y
#define A35 int
#define A34 for
#define A33 x1,
#define A32 2])
#define A31 1},
#define A30 x2,
#define A2F <=
#define A2E >>
#define A2D (x
#define A2C ()
#define A2B m,
#define A2A &&
#define A29 i,
#define A28 m;
#define A27 1;
#define A26 x,
#define A25 j;
#define A24 n,
#define A23 n;
#define A22 >=
#define A21 x1
#define A20 x2
#define A1F d,
#define A1E y,
#define A1D y1
#define A1C 0;
#define A1B y2
#define A1A d;
#define A19 if
#define A18 ||
#define A17 };
#define A16 +
#define A15 d
#define A14 0
#define A13 ,
#define A12 i
#define A11 e
#define A10 >
#define AF )
#define AE u
#define AD (
#define AC ]
#define AB j
#define AA =
#define A9 a
#define A8 b
#define A7 %
#define A6 n
#define A5 {
#define A4 <
#define A3 ;
#define A2 c
#define A1 }
#define A0 [
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#define ABF A87 A98 A4C A8B A35 A89 AA A61 A8B A35
#define AC0 A94 AA A3F A31 A3A A8A A8E A60 A5 A35
#define AC1 A26 A1E A1A A17 A35 A24 A2B A33 A3D A30
#define AC2 A39 A5E AA0 AB9 AAC AAB AB8 ABD A92 A1
#define AC3 AA4 A86 A3B A5 AAF AAE AAD ABA A92 A1
#define AC4 AB7 A92 A1 AB4 A8C A1 AA1 A1 A1 A5D
#define AC5 A5 A86 A3B A5 AAF AAE AAD ABA A92 A1
#define AC6 A19 A2D A22 A6 A18 A97 A7 A32 A5 A92
#define AC7 A1 AB2 A8C A1 AA2 A1 A1 AA5 AB3 AA6
#define AC8 A1 A45 A8F A5 ABB ABE A86 A88 A7 A9D
#define AC9 A5 A60 AE AA A3E A7 A9E A3E A7 A95
#define ACA AB5 A9A A16 A99 A36 A16 A96 A85 A1 AB6
#define ACB AB0 A1 A5D A5 AB1 A1 A1 A1 A1 A35
#define ACC A9F A2C A5 AA3 AA7 AAA A37 A2E A6 A2E
#define ACD A28 A34 A58 A12 AA A27 A12 A2F A23 A5C
#define ACE A5 A34 A58 AB AA A27 AB A2F A28 A59
#define ACF A5 A37 A2E A93 AA8 A21 AA A29 A1D AA
#define AD0 A25 A1 AA9 A20 AA A29 A1B AA A25 A1
#define AD1 A1 A1 A91 ABC A90 A1C A1 A35 A54 AD
#define AD2 AF A5 A19 AD A4A AD A14 AF A10 A9C
#define AD3 A2A A4A AD A14 AF A4 A9B AF A5 A9F
#define AD4 AD AF A3 A1 A5D A5 A5E A9 A0 AC
#define AD5 AA A5 AD A5E AF A56 A13 AD A5E AF
#define AD6 A57 A13 AD A5E AF A81 A13 AD A5E AF
#define AD7 A63 A13 AD A5E AF A7B A13 AD A5E AF
#define AD8 A66 A13 AD A5E AF A76 A13 AD A5E AF
#define AD9 A82 A13 AD A5E AF A71 A13 AD A5E AF
#define ADA A40 A13 AD A5E AF A7E A13 AD A5E AF
#define ADB A62 A13 AD A5E AF A79 A13 AD A5E AF
#define ADC A6A A13 AD A5E AF A6F A13 AD A5E AF
#define ADD A70 A13 AD A5E AF A73 A13 AD A5E AF
#define ADE A69 A13 AD A5E AF A7F A13 AD A5E AF
#define ADF A84 A13 AD A5E AF A6D A13 AD A5E AF
#define AE0 A75 A13 AD A5E AF A71 A13 AD A5E AF
#define AE1 A71 A13 AD A5E AF A57 A13 AD A5E AF
#define AE2 A56 A13 AD A5E AF A38 A1 A3 A5E A8
#define AE3 A0 AC AA A5 AD A5E AF A56 A13 AD
#define AE4 A5E AF A57 A13 AD A5E AF A77 A13 AD
#define AE5 A5E AF A67 A13 AD A5E AF A71 A13 AD
#define AE6 A5E AF A47 A13 AD A5E AF A7D A13 AD
#define AE7 A5E AF A74 A13 AD A5E AF A71 A13 AD
#define AE8 A5E AF A64 A13 AD A5E AF A76 A13 AD
#define AE9 A5E AF A7E A13 AD A5E AF A6E A13 AD
#define AEA A5E AF A7A A13 AD A5E AF A78 A13 AD
#define AEB A5E AF A66 A13 AD A5E AF A7C A13 AD
#define AEC A5E AF A83 A13 AD A5E AF A72 A13 AD
#define AED A5E AF A80 A13 AD A5E AF A6B A13 AD
#define AEE A5E AF A65 A13 AD A5E AF A6C A13 AD
#define AEF A5E AF A68 A13 AD A5E AF A57 A13 AD
#define AF0 A5E AF A56 A13 AD A5E AF A38 A1 A3
#define AF1 A5E A2 A0 AC AA A5 AD A5E AF A55
#define AF2 A13 AD A5E AF A55 A13 AD A5E AF A57
#define AF3 A13 AD A5E AF A49 A13 AD A5E AF A42
#define AF4 A13 AD A5E AF A42 A13 AD A5E AF A44
#define AF5 A13 AD A5E AF A43 A13 AD A5E AF A52
#define AF6 A13 AD A5E AF A5F A13 AD A5E AF A5F
#define AF7 A13 AD A5E AF A4F A13 AD A5E AF A46
#define AF8 A13 AD A5E AF A4E A13 AD A5E AF A4D
#define AF9 A13 AD A5E AF A4B A13 AD A5E AF A46
#define AFA A13 AD A5E AF A41 A13 AD A5E AF A53
#define AFB A13 AD A5E AF A42 A13 AD A5E AF A51
#define AFC A13 AD A5E AF A46 A13 AD A5E AF A50
#define AFD A13 AD A5E AF A51 A13 AD A5E AF A46
#define AFE A13 AD A5E AF A53 A13 AD A5E AF A4F
#define AFF A13 AD A5E AF A46 A13 AD A5E AF A48
#define A100 A13 AD A5E AF A57 A13 AD A5E AF A55
#define A101 A13 AD A5E AF A55 A13 AD A5E AF A3C
#define A102 A13 AD A5E AF A38 A1 A3 A5E A15 A0
#define A103 AC AA A5B A3 A5E A11 A0 AC AA A5A
#define A104 A3 A8D AD A1F A9 AF A3 A8D AD A11
#define A105 AF A3 A8D AD A1F A8 AF A3 A8D AD
#define A106 A11 AF A3 A8D AD A1F A2 AF A3 A1
#define A107 A90 A1C A1 
#define A108 ABF AC0 AC1 AC2 AC3 AC4 AC5 AC6 AC7 AC8
#define A109 AC9 ACA ACB ACC ACD ACE ACF AD0 AD1 AD2
#define A10A AD3 AD4 AD5 AD6 AD7 AD8 AD9 ADA ADB ADC
#define A10B ADD ADE ADF AE0 AE1 AE2 AE3 AE4 AE5 AE6
#define A10C AE7 AE8 AE9 AEA AEB AEC AED AEE AEF AF0
#define A10D AF1 AF2 AF3 AF4 AF5 AF6 AF7 AF8 AF9 AFA
#define A10E AFB AFC AFD AFE AFF A100 A101 A102 A103 A104
#define A10F A105 A106 A107 
#define A110 A108 A109 A10A A10B A10C A10D A10E A10F 
#define A111(__FOX__) __FOX__
A111(A110)