#include <bits/stdc++.h>
using namespace std;
int table[]={0,34,37,42,41,37,36,35,54,37,54,22,29,38,34,38,43,44,43,42,56,15,44,32,45,26,40,34,43,30,42,36,42,46,58,30,27,28,26,51,32,41,41,25,38,59,31,56,38,52,37,49,23,30,46,44,30,51,27,43,36,34,36,23,52,47,23,28,60,29,30,60,23,46,44,9,49,32,20,41,30,45,44,44,38,37,7,68,37,44,21,37,46,47,47,49,40,65,26,47,50,44,26,50,25,48,40,30,34,42,35,41,13,42,43,30,37,37,61,44,39,41,14,46,32,36,31,42,45,27,49,28,25,38,50,53,44,33,44,38,41,30,44,35,30,47,30,35,43,36,56,42,43,15,34,48,32,44,49,35,28,18,44,49,41,37,52,32,43,39,49,31,18,38,62,28,41,44,42,35,14,39,46,31,37,26,56,42,31,39,29,72,32,32,37,20,37,30,46,29,36,42,41,31,38,48,50,34,45,34,37,40,51,56,18,50,22,30,56,40,38,41,34,39,22,54,25,28,54,41,32,34,47,30,45,38,43,32,48,39,47,28,62,17,32,42,26,42,51,52,15,35,43,48,27,45,38,31,35,31,52,30,33,36,42,50,35,55,37,44,46,45,46,24,33,47,35,46,22,54,51,46,20,30,42,41,29,39,30,34,52,39,31,32,47,39,34,43,35,58,34,20,47,40,20,33,39,50,44,51,41,33,46,30,47,36,56,27,44,34,27,20,55,49,42,13,29,64,19,44,46,35,57,37,44,22,34,44,48,42,41,43,35,46,28,20,43,24,59,23,36,50,38,32,71,49,31,49,39,35,45,16,38,46,51,42,26,46,26,39,26,26,55,34,40,33,36,46,10,45,50,37,41,44,40,43,18,30,31,35,35,33,39,41,49,33,20,38,44,32,49,33,38,33,47,28,32,44,46,51,39,28,32,52,56,38,32,33,31,37,28,44,40,43,45,54,18,30,40,58,34,45,34,29,53,40,27,21,41,52,32,36,43,56,15,34,44,29,38,42,35,50,33,41,38,38,29,51,30,28,43,47,47,43,26,34,42,47,33,39,24,40,56,37,17,50,51,28,26,42,43,33,34,45,45,39,15,41,45,43,20,42,29,39,53,39,47,36,59,30,43,26,38,47,38,28,39,42,31,44,41,38,25,56,35,33,53,12,42,43,27,60,35,35,32,37,31,59,34,46,50,29,56,36,55,23,31,40,34,40,41,24,42,47,28,50,44,24,36,56,34,21,45,46,47,29,25,48,48,50,33,53,34,27,43,45,26,50,23,30,50,47,33,45,39,30,46,28,34,37,51,36,31,50,30,26,60,44,40,34,28,37,45,57,42,32,19,53,46,42,9,48,37,47,29,54,11,43,23,40,49,50,32,15,47,51,42,36,30,30,52,41,30,58,25,46,30,43,30,50,46,31,44,21,49,38,46,21,44,35,33,65,24,40,59,42,47,33,42,45,28,27,35,54,34,21,39,39,31,41,43,41,35,50,22,47,44,47,44,18,53,49,27,53,49,40,31,40,22,59,29,40,41,46,24,37,39,38,38,41,30,19,68,38,42,43,32,35,32,63,29,52,39,35,28,32,31,54,46,44,40,32,19,40,54,27,50,26,53,48,48,43,18,40,41,38,36,45,27,26,52,34,34,60,38,21,60,22,43,29,30,38,28,44,46,20,71,30,38,19,32,38,46,26,43,39,35,40,56,38,45,25,35,39,27,17,50,53,30,44,55,46,41,22,62,16,22,50,34,35,48,16,49,12,45,43,52,41,50,27,43,33,42,34,45,64,20,42,45,34,51,18,32,27,27,48,49,50,27,34,42,41,10,56,52,29,39,39,50,45,33,35,43,16,47,42,48,39,42,38,52,39,22,45,33,29,50,47,40,36,27,48,39,21,43,46,37,21,50,27,32,34,10,48,46,23,37,50,44,26,46,41,39,36,33,26,48,46,35,49,33,31,32,36,31,45,32,50,43,31,37,37,39,53,23,43,55,21,50,28,21,33,52,31,43,42,34,57,24,43,39,26,36,34,51,33,39,37,56,28,38,30,44,44,41,27,64,31,40,51,25,61,43,24,48,32,38,20,47,43,45,34,38,36,39,45,25,40,32,35,31,51,28,48,36,42,43,51,21,56,25,48,32,31,31,47,43,37,45,28,33,37,50,21,45,37,54,23,27,47,45,27,44,41,51,29,39,32,45,8,37,50,25,62,44,44,20,60,33,24,37,38,45,46,44,40,43,32,53,46,44,30,48,19,47,31,35,41,44,36,32,34,51,48,40,42,34,41,33,45,47,36,34,17,42,50,48,42,29,47,38,33,61,35,22,34,46,42,39,48,11,46,55,28,38,46,31,30,57,26,31,40,34,45,36,52,39,34,23,48,54,39,34,46,56,32,26,27,51,30,36,30,49,40,38,30,36,47,26,38,39,47,24,30,47,24,57,38,28,47,43,25,48,40,43,49,35,30,40,42,38,53,33,39,37,47,37,29,48,28,31,49,48,24,43,57,31,29,24,42,43,34,35,29,51,43,10,58,50,37,35,51,37,28,43,25,49,24,32,35,39,27,58,45,31,40,34,51,26,47,39,47,50,25,34,47,33,40,35,40,39,36,32,32,36,35,53,25,33,38,40,40,47,40,58,33,20,16,56,31,25,37,53,24,37,43,42,26,49,43,40,20,46,30,41,58,25,32,45,54,19,50,40,26,57,21,53,33,35,48,46,18,21,48,43,22,37,21,40,48,47,44,35,42,36,41,48,29,25,49,36,19,43,54,42,40,20,39,38,58,26,55,45,26,21,51,36,37,39,46,41,36,37,56,28,41,32,40,48,42,32,42,21,31,60,14,41,27,53,43,45,36,38,42,51,53,30,37,24,53,47,35,36,48,38,44,25,56,28,29,48,46,26,49,31,39,51,45,33,50,46,11,68,33,30,48,43,29,35,25,32,42,59,20,46,31,38,43,35,40,48,26,46,41,17,42,46,34,20,55,29,43,39,60,33,34,47,31,36,34,51,63,19,32,48,44,28,54,30,37,33,20,44,45,46,36,28,57,44,32,26,24,41,48,51,40,50,20,29,22,36,50,32,38,59,35,41,50,37,15,44,46,23,47,40,46,63,28,39,50,20,28,45,39,42,33,33,45,27,52,40,37,35,49,38,29,39,45,33,50,31,36,37,30,53,39,24,34,26,41,18,46,38,26,54,40,44,41,40,20,37,57,31,49,25,49,28,33,63,49,20,47,51,31,41,30,58,33,45,27,25,28,51,29,55,39,30,19,37,27,38,40,56,35,55,27,54,47,31,20,28,48,37,31,31,46,41,29,37,49,43,27,44,22,48,44,55,32,51,41,40,41,42,48,40,17,52,33,37,31,38,42,31,42,36,42,26,36,38,42,43,39,35,51,37,33,51,11,44,28,57,23,49,46,33,40,44,26,42,33,20,39,44,42,43,44,22,49,53,42,50,20,38,30,56,32,33,48,64,28,36,37,26,40,26,39,43,35,42,48,35,51,8,56,12,43,35,33,38,52,56,41,42,42,47,23,10,37,53,45,40,36,51,39,22,25,41,47,56,32,35,37,44,36,39,35,58,38,29,57,39,45,20,21,30,47,42,34,26,46,49,44,39,35,42,27,26,30,44,35,47,48,35,29,39,43,33,42,37,48,45,21,28,49,28,52,38,44,31,28,48,47,33,35,37,46,33,46,41,46,40,41,34,36,49,35,38,28,42,47,31,42,52,47,31,42,23,25,53,50,23,55,47,28,43,36,45,23,41,39,45,52,24,31,54,16,53,36,36,43,21,35,39,37,33,35,41,26,53,26,27,8,58,48,36,41,38,42,37,21,43,41,36,45,35,34,50,23,59,12,51,30,28,45,45,35,46,40,24,24,39,51,41,32,61,15,36,43,50,44,25,51,57,36,30,32,47,58,32,40,49,40,60,16,34,35,43,33,30,82,22,42,39,25,47,29,47,25,44,35,36,52,40,25,49,41,46,36,29,56,22,51,39,19,51,45,41,27,48,35,40,38,40,60,43,50,21,44,36,31,52,42,47,10,27,45,60,37,29,46,33,30,40,29,39,64,35,59,23,28,32,54,33,42,43,61,24,44,33,34,54,45,35,42,41,54,33,37,46,35,39,35,40,46,24,29,40,44,37,39,34,40,34,18,28,55,49,26,47,31,41,31,47,31,30,56,44,52,26,43,33,50,34,41,55,7,38,56,18,56,26,34,56,30,18,31,50,14,45,48,41,25,44,42,42,26,44,40,31,30,36,36,49,22,41,43,24,41,46,51,38,38,52,33,44,23,39,30,36,16,52,53,47,45,43,39,32,43,36,31,36,40,58,23,60,22,51,41,29,40,34,29,50,51,33,36,52,44,48,35,26,33,40,35,46,27,34,47,20,58,36,28,52,29,19,51,42,40,57,16,57,19,50,35,45,39,33,43,43,23,35,42,45,38,33,21,48,43,58,17,40,20,52,46,30,35,35,58,62,30,44,17,59,36,41,22,25,55,35,30,43,51,32,37,26,45,48,41,46,33,51,38,50,37,24,42,39,28,42,48,17,51,29,29,32,50,58,24,39,42,70,35,43,45,32,30,18,53,39,64,18,31,34,28,48,39,33,43,46,36,52,23,58,39,43,41,23,58,20,38,30,37,43,35,45,39,38,32,44,39,28,23,35,41,44,55,17,52,18,59,20,57,27,63,38,34,40,29,42,29,21,45,50,32,45,20,44,57,30,38,46,50,18,39,45,35,38,35,42,34,44,46,31,44,35,42,44,23,34,35,50,37,40,27,33,32,58,39,46,31,58,39,39,42,31,40,46,46,31,29,37,39,40,34,28,25,44,57,18,48,43,22,44,32,55,30,38,45,38,34,33,47,42,36,34,27,44,20,43,58,24,40,38,39,16,23,58,46,30,50,38,35,50,40,45,31,24,36,52,37,42,32,42,58,24,22,51,40,49,35,52,42,45,29,19,47,48,36,22,28,32,51,55,43,38,27,32,30,23,47,39,33,56,26,23,16,51,35,54,34,25,52,41,38,28,38,30,47,43,44,31,45,25,72,30,41,35,29,34,31,36,41,56,32,52,18,43,61,32,42,26,50,36,36,41,38,29,63,19,45,34,27,49,48,36,59,46,31,17,36,44,28,35,47,29,34,41,37,24,49,28,69,38,43,39,44,26,40,50,34,29,32,59,38,28,49,38,36,40,9,47,43,50,26,40,47,38,26,39,43,35,60,27,41,27,28,38,39,42,33,43,34,37,21,53,28,32,52,34,38,39,43,29,32,36,43,53,26,70,25,34,39,24,48,50,25,27,48,53,33,26,46,25,30,43,37,24,49,31,51,23,29,45,44,40,37,30,29,35,41,44,25,41,27,42,27,50,56,42,34,52,44,28,32,34,42,35,48,39,32,34,45,30,44,29,56,27,34,36,41,31,45,36,36,25,50,42,30,29,26,28,57,39,42,27,28,44,35,43,40,43,28,51,34,41,45,30,33,41,47,50,16,63,26,30,50,39,32,46,44,34,35,37,36,48,46,46,32,51,29,52,23,49,35,42,32,40,44,35,39,18,53,41,52,22,19,57,30,46,30,43,47,26,46,34,45,38,46,31,35,61,38,35,13,55,44,47,44,14,55,26,37,48,45,42,37,15,47,31,41,52,31,60,20,36,24,39,50,42,34,44,24,42,55,38,56,27,47,35,42,27,45,27,39,41,49,27,56,32,54,30,35,41,64,7,47,34,51,21,42,46,16,48,47,36,37,26,52,51,32,34,35,33,41,41,18,37,39,37,35,53,24,28,32,23,49,53,24,44,34,39,36,44,24,46,45,39,29,32,40,48,33,18,48,53,44,37,35,31,38,55,28,44,40,33,20,43,45,41,42,32,55,38,38,48,49,42,45,21,49,21,33,44,30,43,46,29,49,46,40,34,34,22,39,24,43,38,42,25,41,47,34,34,44,40,41,43,41,39,21,39,32,35,35,50,35,40,36,28,36,28,51,36,31,42,51,41,47,24,42,36,62,31,25,20,47,21,61,49,30,41,41,17,57,34,49,31,55,37,45,36,48,24,38,37,43,18,44,54,33,40,36,55,46,31,45,46,33,37,10,34,32,41,40,61,22,52,51,48,42,43,50,15,31,44,43,48,43,30,25,40,40,39,28,61,43,32,58,40,20,36,52,35,49,39,42,34,41,45,29,35,45,17,41,61,35,14,55,22,53,46,48,33,25,44,34,31,31,40,51,33,35,37,60,29,36,43,42,41,39,37,39,36,27,37,27,46,56,19,44,49,20,32,44,36,48,31,61,17,38,34,35,20,57,50,33,47,43,27,50,30,40,39,37,43,32,28,56,30,29,43,23,43,44,49,50,7,52,21,34,25,46,29,38,37,31,48,66,22,25,59,32,50,24,44,42,26,35,20,55,38,37,43,39,51,41,42,44,33,29,39,43,33,36,40,45,30,56,35,37,23,38,57,24,43,44,38,54,29,44,28,59,36,33,33,44,50,22,52,32,28,35,22,49,42,25,42,37,44,20,25,32,50,21,56,39,45,35,42,41,28,45,54,44,40,31,44,29,67,36,30,38,34,45,47,29,36,26,24,38,33,42,48,32,31,35,41,42,43,53,32,37,33,40,37,41,49,51,28,48,31,29,32,35,55,29,36,38,38,54,24,43,37,32,58,34,35,34,58,31,53,53,33,49,27,45,45,35,26,47,29,34,40,42,36,48,48,33,41,44,40,31,33,57,40,25,48,37,37,27,49,56,25,43,31,28,48,33,19,58,24,45,40,49,46,24,45,44,54,32,37,45,45,44,19,40,44,29,38,42,33,51,36,56,34,35,39,31,34,47,46,36,27,47,17,47,36,48,30,42,44,38,44,41,35,36,42,26,30,23,56,47,48,36,45,36,50,39,36,32,39,40,30,21,30,41,49,50,41,48,13,46,31,55,29,65,32,43,22,40,41,50,30,44,34,36,23,24,30,43,43,38,44,47,33,48,37,48,25,39,21,50,53,48,46,28,31,31,29,35,51,43,39,32,41,39,42,35,46,37,43,31,36,26,40,40,41,26,53,34,53,19,23,38,57,14,53,42,23,48,57,30,26,41,42,37,36,34,31,32,38,42,42,39,52,47,51,32,35,30,42,35,26,45,36,38,23,37,54,45,32,40,38,38,33,35,41,42,40,35,29,42,44,57,19,53,37,41,33,25,45,56,32,29,34,65,39,37,23,54,35,40,39,67,16,53,42,14,33,52,10,59,9,35,43,43,44,44,27,39,25,51,50,28,42,44,47,38,42,31,45,38,42,36,36,36,38,48,39,29,50,45,26,53,17,51,24,45,46,31,41,21,46,23,51,18,48,24,43,44,41,34,45,16,59,43,17,54,44,43,43,28,59,9,47,43,32,45,30,52,37,41,46,33,35,29,46,38,37,55,5,35,65,42,50,24,39,42,20,57,26,33,54,48,33,43,38,37,45,30,51,38,42,27,37,34,59,36,52,20,28,23,50,38,48,43,28,44,41,33,51,44,22,31,49,40,16,42,36,34,61,28,21,28,34,43,49,46,36,35,29,64,31,27,48,31,34,26,37,34,39,51,41,46,29,22,45,56,29,22,32,43,46,34,48,50,42,28,61,15,42,28,43,32,47,35,66,23,52,22,59,30,42,37,33,43,34,33,41,46,36,40,27,31,45,41,54,49,37,31,53,37,19,44,28,56,40,40,24,40,30,34,58,31,31,49,33,42,29,46,5,54,57,41,26,33,60,29,37,34,36,28,46,31,46,38,24,45,45,52,10,49,41,31,37,40,49,33,56,33,41,38,35,33,44,48,30,46,36,17,68,38,44,40,27,41,54,29,37,41,35,41,41,43,49,22,42,35,41,48,34,32,30,40,33,40,36,51,52,50,45,47,46,45,37,41,30,31,43,17,55,30,53,24,39,52,30,46,25,38,34,48,35,31,41,39,20,68,39,35,34,42,22,51,28,41,34,53,27,28,43,49,43,51,39,10,46,53,29,38,52,37,35,31,29,19,50,40,20,38,43,49,45,38,41,34,42,33,48,46,50,33,20,52,44,44,23,46,33,49,35,43,42,56,53,20,40,20,41,46,24,56,51,15,46,29,32,45,44,31,42,40,27,29,50,27,58,43,43,54,44,19,36,46,43,37,30,22,44,52,29,44,26,39,44,39,51,39,34,54,39,24,44,40,44,18,43,45,50,27,63,20,56,27,39,29,35,47,34,54,38,33,30,20,29,41,34,34,41,29,48,35,34,28,37,44,43,42,26,43,34,44,34,33,41,43,30,43,45,44,39,43,45,24,51,44,45,38,28,48,37,28,50,27,40,39,18,27,54,25,44,41,28,39,52,41,39,22,29,40,56,44,36,44,36,39,40,26,36,38,55,43,53,50,29,51,39,29,33,32,26,38,50,29,59,35,32,55,36,28,33,49,28,44,49,41,31,44,26,47,34,47,22,37,14,51,47,41,34,40,35,49,40,27,22,32,32,25,54,41,39,30,60,19,31,39,40,49,33,28,33,34,48,33,40,44,33,39,47,42,43,37,21,41,63,35,27,44,54,30,50,55,30,40,29,42,20,48,35,51,36,26,36,57,31,50,32,38,24,50,41,32,39,58,13,44,54,56,32,47,35,42,40,35,36,51,7,50,27,29,33,42,27,42,33,31,49,25,50,42,42,33,38,53,19,33,50,40,47,29,38,46,28,50,31,41,42,48,46,29,40,41,30,34,48,45,41,37,54,20,41,48,35,35,24,30,41,43,34,48,33,41,27,32,42,45,43,32,69,46,25,28,29,41,39,26,45,25,56,28,41,33,61,40,26,41,52,17,34,33,58,36,40,26,51,30,33,47,16,44,54,12,42,45,50,33,51,34,50,34,49,38,44,31,57,19,53,27,46,46,12,37,35,27,50,53,32,33,41,29,32,26,41,51,22,62,28,43,43,40,19,67,23,41,45,47,52,42,46,35,42,45,52,34,22,47,37,26,42,30,49,22,33,46,31,40,41,19,52,41,46,41,46,42,35,34,38,42,50,31,42,47,32,44,25,47,25,43,34,70,44,33,26,40,42,39,34,18,30,44,44,30,36,43,33,40,19,27,46,36,32,38,54,44,28,34,38,48,29,47,61,27,54,34,22,39,40,39,48,45,41,22,31,39,36,40,44,34,42,63,32,20,47,55,20,47,36,47,60,24,44,10,48,37,36,40,37,28,25,46,38,35,44,25,42,27,51,37,41,40,53,36,34,44,45,38,34,63,34,41,32,28,27,52,49,45,23,34,23,25,42,39,41,48,37,21,39,47,48,45,25,56,29,48,37,35,50,39,30,48,27,56,27,40,33,35,32,29,30,41,43,33,51,26,59,22,41,30,60,24,33,35,59,35,43,42,50,27,42,43,30,26,45,39,30,46,45,20,54,16,37,34,61,41,38,39,43,27,55,23,59,34,46,30,46,29,54,29,40,47,17,39,63,35,24,47,26,45,50,45,49,38,38,21,31,36,44,39,30,47,41,45,35,51,13,34,35,50,16,44,29,25,44,25,26,49,42,29,33,42,44,45,35,31,49,36,35,32,36,42,50,40,25,43,37,50,34,39,36,44,48,36,30,59,39,29,40,40,33,36,31,57,31,27,33,57,30,29,46,54,39,23,45,30,33,40,36,40,29,39,43,42,45,37,53,37,40,32,33,50,32,23,59,32,26,35,31,61,39,28,42,50,34,40,59,37,34,47,37,32,68,5,39,44,46,28,35,37,21,53,25,42,31,37,37,41,43,52,52,14,45,41,60,10,64,46,37,15,28,26,50,41,48,50,38,38,21,54,39,16,40,36,44,51,41,36,49,27,46,35,32,40,31,43,47,38,44,40,38,31,45,41,12,64,33,34,22,64,34,28,49,38,45,37,62,31,35,26,37,42,32,29,37,35,42,24,53,40,27,25,48,41,47,29,42,21,56,28,52,26,28,36,55,32,56,26,47,26,42,29,36,43,59,7,45,29,49,43,35,43,36,48,38,34,35,25,64,24,48,26,47,41,44,31,48,43,31,36,46,25,35,54,36,52,44,36,31,36,32,36,52,27,51,53,35,42,23,46,41,37,24,52,70,29,21,61,50,39,32,36,33,33,24,42,41,17,31,45,36,30,34,40,53,41,47,47,33,35,30,39,40,49,28,34,54,31,27,47,47,53,39,35,19,55,20,50,44,33,44,38,48,27,45,36,60,12,38,50,39,38,30,50,25,48,48,39,45,48,46,47,26,43,40,25,45,32,38,39,42,35,31,36,32,46,35,31,33,29,37,37,46,35,34,32,45,25,49,38,53,51,28,47,39,34,62,22,34,41,32,60,27,43,29,32,47,41,29,55,10,34,44,50,24,45,53,33,30,37,21,38,42,43,54,32,35,46,46,19,36,48,57,29,43,41,29,40,51,38,30,39,53,41,50,26,25,42,22,39,35,35,31,50,38,44,35,32,62,37,25,35,37,41,42,37,39,48,48,32,23,45,39,37,53,31,49,15,37,43,36,45,40,34,34,44,19,28,36,43,38,43,37,31,51,46,27,44,28,51,45,40,49,44,34,50,21,53,57,30,52,22,36,26,47,36,38,26,25,31,42,52,24,61,33,56,41,28,52,24,50,26,34,43,37,27,35,55,31,39,52,15,31,32,27,41,40,36,29,37,54,27,41,18,68,49,44,45,36,35,29,39,33,51,29,50,34,26,43,51,33,33,36,52,28,52,37,17,56,40,24,61,31,20,49,34,46,27,50,37,32,38,43,33,32,53,22,48,24,54,31,34,43,25,55,28,48,39,36,35,55,30,28,41,46,38,21,47,34,43,39,61,46,33,33,47,29,33,34,29,38,43,38,40,34,57,23,43,40,32,33,27,56,40,35,39,24,37,42,43,39,54,23,41,51,47,36,46,51,52,24,18,33,68,43,34,32,22,49,44,24,48,34,24,29,45,25,45,62,26,36,27,58,28,43,33,39,46,32,24,43,36,39,31,33,47,25,39,31,39,54,30,43,52,18,43,33,39,48,36,39,19,60,37,60,26,59,17,58,23,56,19,40,42,36,18,50,42,42,37,27,60,32,39,36,42,35,39,23,50,43,50,18,28,45,50,41,41,29,47,47,32,32,32,34,37,35,46,33,50,32,27,51,39,33,48,39,27,49,33,18,51,41,37,48,22,48,42,31,39,33,34,58,39,38,38,36,40,46,36,40,42,37,41,41,29,46,46,19,45,38,43,23,57,33,27,37,40,36,49,23,44,28,48,39,32,35,43,22,56,44,28,35,48,26,38,40,48,36,53,25,45,52,47,33,31,41,37,35,34,63,11,49,42,54,46,28,31,38,45,28,43,71,18,33,27,35,52,40,57,41,41,41,32,24,22,38,32,28,47,44,27,24,53,43,33,47,34,37,59,34,36,28,55,42,26,58,41,33,37,37,37,34,48,22,26,74,24,49,39,30,46,27,46,35,33,35,33,38,53,35,38,39,46,21,45,38,26,45,38,54,28,51,22,40,41,43,39,48,39,34,17,33,40,27,50,36,42,37,37,44,35,31,38,54,36,50,28,36,40,41,31,47,27,29,52,35,33,32,47,36,45,46,32,38,48,22,34,42,32,24,36,44,30,31,49,38,38,28,50,26,38,49,42,52,25,45,44,15,54,14,44,35,64,37,29,25,38,43,26,42,42,48,42,45,53,14,34,53,12,45,47,44,36,54,41,38,42,33,40,28,26,51,39,36,41,32,63,53,38,48,34,45,29,32,33,40,35,42,33,46,53,46,45,35,39,49,38,21,41,30,41,37,33,29,43,33,47,30,37,38,44,37,13,50,48,22,48,24,57,46,21,44,28,47,34,40,32,13,50,22,58,36,49,26,48,28,23,56,35,38,55,41,36,36,27,48,37,62,29,53,34,48,25,43,37,42,30,49,4,57,22,55,25,54,31,47,12,31,60,48,37,10,47,41,23,51,28,26,47,29,52,39,41,36,41,21,60,26,48,44,42,42,37,43,28,37,41,46,40,45,29,36,51,44,5,39,38,29,51,21,43,50,41,25,28,37,42,40,32,48,34,50,46,26,41,34,45,41,36,26,51,43,36,37,42,44,43,44,53,29,49,35,44,37,48,38,38,30,26,43,26,54,25,32,54,44,38,37,49,25,23,58,41,12,50,46,35,30,36,35,51,38,45,30,24,38,42,40,35,31,29,44,42,33,47,33,35,58,16,52,35,48,27,49,28,68,35,36,22,43,43,26,40,45,35,41,33,48,32,53,54,19,36,48,36,46,25,39,47,50,39,29,49,36,46,18,33,23,67,45,21,55,33,42,48,50,23,41,38,31,39,25,49,38,26,59,33,55,32,41,40,40,36,34,33,50,46,48,42,32,33,50,37,45,33,26,60,55,29,43,44,23,40,22,41,46,46,47,48,21,53,39,39,31,29,38,38,44,35,40,35,42,39,44,32,28,40,36,56,29,55,46,26,37,43,42,52,40,39,27,37,37,31,40,37,32,33,39,48,33,21,44,33,33,36,41,39,28,37,41,40,44,59,39,36,33,49,28,36,51,32,47,13,43,33,39,35,26,31,45,30,47,42,17,51,35,20,52,65,34,26,36,32,41,16,55,42,48,27,40,30,46,59,26,43,42,39,34,39,49,14,48,48,25,45,43,37,39,41,38,40,28,34,32,44,48,28,42,26,44,32,36,16,34,44,53,44,41,38,50,45,32,51,18,23,40,32,45,28,44,53,23,51,22,35,30,47,20,45,36,44,56,39,46,40,31,34,34,44,31,29,44,46,28,20,54,32,31,48,21,47,50,28,25,47,51,29,42,23,30,47,39,29,55,43,24,37,46,37,52,32,57,31,34,42,42,54,27,33,37,25,42,53,41,36,48,29,21,40,52,30,43,44,16,43,42,45,30,25,47,36,48,34,28,37,61,24,42,38,33,30,41,38,36,49,35,35,47,55,43,21,30,46,38,34,32,34,74,25,42,29,34,37,49,32,61,37,46,52,13,50,26,24,56,11,46,50,47,43,40,45,31,39,37,34,29,45,48,40,33,15,42,33,20,48,44,42,33,42,47,37,50,28,41,47,18,46,25,59,36,25,52,29,47,24,54,29,35,57,34,39,32,30,61,28,40,37,40,25,36,36,48,40,39,47,34,28,48,42,22,35,41,45,38,21,36,40,37,62,32,41,30,59,5,41,39,40,55,22,38,41,31,36,40,55,36,42,36,26,52,30,38,47,43,41,26,25,51,38,38,36,55,26,36,49,32,48,41,23,41,27,42,35,40,33,65,35,40,41,31,21,45,39,51,39,42,39,43,32,49,24,37,42,45,28,25,46,55,23,47,44,9,56,26,46,36,34,51,45,41,37,36,40,47,37,28,36,37,51,34,35,42,35,42,45,45,36,39,7,82,35,30,39,25,52,29,34,43,30,47,35,30,48,50,30,37,41,20,58,45,28,52,31,41,22,35,48,53,33,24,42,30,77,22,43,44,27,44,34,26,56,43,33,43,31,30,52,24,32,46,37,32,37,42,34,52,23,43,68,28,18,37,29,51,14,64,42,34,40,40,19,40,41,40,50,42,18,48,49,19,34,52,48,39,35,41,40,42,33,46,42,39,23,41,50,38,46,36,29,29,55,34,45,37,26,43,30,49,31,49,18,34,42,48,38,38,48,22,46,35,44,37,25,39,38,36,49,54,29,37,40,40,42,31,36,41,53,34,48,49,39,42,36,53,38,52,44,32,38,32,51,34,27,38,39,37,24,31,26,36,64,39,52,28,38,55,47,28,32,49,32,30,58,37,27,36,40,43,43,33,34,43,31,43,22,51,34,28,48,32,55,17,64,41,32,52,32,23,49,45,30,39,36,43,24,46,36,41,34,57,39,44,52,25,26,56,33,32,54,30,26,52,32,38,32,34,48,38,42,18,51,32,25,26,47,21,68,38,31,36,37,43,33,26,59,32,37,42,36,37,40,37,47,46,41,41,23,40,51,20,33,22,46,29,60,32,51,38,33,46,31,41,28,42,54,34,49,41,48,27,25,45,48,40,31,41,34,47,37,45,28,38,35,47,40,34,31,47,40,36,34,33,44,44,41,27,35,46,19,36,28,40,38,44,44,41,44,28,56,26,49,38,39,41,35,49,46,18,50,17,39,14,55,40,31,33,23,54,47,21,42,60,36,39,42,41,23,25,50,31,61,17,51,26,55,21,28,52,31,35,49,50,46,49,31,46,21,40,55,45,36,24,44,51,42,30,20,52,23,43,34,58,41,41,39,20,51,40,22,34,40,36,48,41,25,48,47,50,32,44,35,52,23,24,30,41,26,48,39,43,35,37,47,42,39,35,35,55,25,50,47,27,45,40,51,28,48,49,36,37,41,53,19,55,24,45,34,49,28,26,35,51,37,47,48,26,43,26,49,12,55,40,47,26,59,46,33,31,36,38,43,10,56,47,21,33,49,42,40,39,37,51,31,49,33,43,34,35,46,25,50,11,46,56,26,50,41,28,42,56,44,7,52,40,38,47,34,31,53,19,32,54,31,11,36,49,50,36,32,36,20,56,40,61,41,33,40,43,34,32,29,62,34,39,33,37,38,55,34,30,51,46,30,43,41,30,29,53,24,44,37,38,38,52,40,40,50,30,22,46,30,40,35,36,46,40,37,54,29,31,32,31,36,43,39,44,50,17,47,42,48,21,40,20,38,39,38,48,30,44,31,36,50,22,19,51,22,48,52,25,50,46,15,51,47,43,39,41,31,35,48,42,45,34,22,54,35,36,33,34,36,40,16,49,36,31,35,34,45,66,33,39,24,44,29,50,23,33,51,31,45,33,39,43,38,45,25,39,44,37,27,25,61,18,41,31,49,54,43,49,35,30,37,48,31,34,48,19,51,38,30,45,37,40,36,37,49,28,46,33,59,20,55,26,41,19,34,41,43,34,30,53,56,36,31,50,58,35,42,46,27,38,44,21,37,39,39,40,51,18,38,54,25,21,47,43,39,25,46,36,41,54,32,31,38,17,53,43,49,47,39,31,35,38,45,27,30,39,56,48,31,41,28,32,46,39,29,46,42,34,42,55,28,38,41,19,33,26,54,27,34,50,44,34,45,34,35,53,22,39,41,42,43,44,27,37,32,56,27,43,32,26,47,42,34,44,38,19,67,46,43,33,12,48,38,34,27,49,31,38,35,38,25,40,49,41,41,44,40,20,34,40,53,43,35,44,34,52,48,36,27,50,34,48,23,32,27,46,30,36,51,21,51,70,50,30,37,35,30,43,43,52,24,54,35,34,43,39,38,28,50,46,42,41,34,23,44,29,35,32,52,49,32,21,48,51,42,33,47,34,43,25,43,29,23,33,43,44,51,51,33,34,52,33,27,54,30,45,26,51,31,27,58,33,36,9,33,54,37,44,35,53,23,44,36,20,50,43,42,33,37,50,54,37,34,45,49,30,40,35,38,35,43,46,18,53,28,26,58,47,25,26,54,26,42,43,45,39,43,30,31,49,45,46,37,44,48,37,24,44,31,41,31,49,28,41,35,39,52,20,40,27,51,18,51,35,31,43,45,42,35,30,46,49,35,39,38,57,0,44,45,39,46,49,21,18,53,41,37,62,30,48,38,26,41,30,40,18,45,37,38,60,25,35,45,33,51,44,42,34,30,36,47,37,29,38,49,31,29,33,35,33,56,60,31,28,43,41,37,34,43,30,32,50,23,40,39,51,31,53,25,43,35,49,46,24,25,54,31,48,60,15,40,26,41,24,25,57,52,32,20,38,41,56,46,20,31,40,59,18,53,43,56,34,37,45,40,37,38,33,58,36,38,44,29,36,18,49,52,33,32,54,35,42,41,32,46,34,44,37,48,29,26,31,49,47,15,44,49,30,40,34,30,44,37,34,25,29,31,50,46,51,29,38,36,49,33,47,48,28,47,35,54,29,41,40,37,27,43,14,32,49,49,26,51,29,42,40,35,52,38,36,43,28,41,17,55,32,26,64,36,42,23,41,52,44,51,35,33,11,32,55,25,31,49,43,37,42,20,57,27,35,37,52,37,27,43,34,42,30,35,33,41,28,47,46,37,41,44,21,43,19,55,38,26,41,47,33,36,36,41,35,46,39,35,32,31,41,42,37,48,44,50,18,47,29,56,35,39,42,31,51,54,36,34,38,35,41,48,43,25,35,47,38,32,33,37,50,23,54,43,31,44,47,47,42,37,18,47,36,21,52,53,35,51,43,39,31,43,30,42,35,37,41,45,25,33,33,34,45,34,31,49,47,49,29,51,39,26,53,16,41,32,32,47,37,42,32,54,18,35,55,42,21,42,48,38,48,35,45,23,53,16,46,46,10,47,36,37,33,48,27,35,55,36,34,47,24,59,53,21,28,50,32,50,47,28,53,46,24,26,27,56,37,35,58,19,55,34,16,56,36,33,26,44,69,19,47,28,36,46,38,28,45,42,42,34,20,49,26,53,39,40,25,34,50,14,37,29,36,29,60,21,51,21,41,29,47,37,51,39,22,47,32,49,40,41,34,61,23,32,46,41,32,52,47,36,43,42,54,20,35,38,54,14,44,27,48,29,48,43,23,52,20,40,41,44,33,27,60,55,41,23,61,36,36,25,41,55,49,51,35,47,42,38,35,53,45,9,47,36,36,37,44,37,22,30,34,55,46,24,43,37,35,31,31,52,46,31,46,35,37,41,39,30,32,46,46,44,27,52,27,56,31,24,27,25,49,39,28,49,46,40,41,38,28,37,37,26,38,37,48,42,39,42,38,28,38,21,60,27,62,41,52,38,42,30,64,17,35,43,39,52,35,26,41,25,29,45,44,38,45,40,39,46,36,37,24,40,44,32,48,28,60,34,30,32,48,32,37,46,33,31,52,29,33,33,37,37,31,45,42,25,52,21,50,47,42,54,37,44,44,24,41,30,38,45,32,43,33,42,19,35,43,45,39,38,20,45,52,46,26,30,56,23,52,20,36,36,31,48,29,47,36,20,20,41,59,60,18,56,28,50,36,49,37,34,35,46,20,32,47,44,37,23,43,50,41,37,37,39,32,44,38,42,48,37,41,27,32,45,43,54,33,42,31,48,47,35,41,46,33,50,46,40,18,43,35,34,45,31,43,26,41,32,37,44,62,22,22,39,51,59,49,23,38,31,41,35,50,35,42,34,31,37,44,44,37,43,50,39,46,40,31,39,43,32,45,34,36,50,45,24,41,13,50,36,49,29,43,62,20,23,25,31,49,43,54,33,29,51,37,28,48,38,51,34,20,47,44,38,14,55,40,33,38,41,44,44,36,28,49,36,17,59,40,35,38,28,40,41,30,40,43,34,23,35,44,33,33,33,36,34,52,26,28,48,37,49,35,45,41,26,37,28,37,47,27,21,49,34,55,36,33,44,41,34,56,30,27,49,35,23,58,22,48,46,39,39,25,32,36,35,42,44,48,37,46,33,45,36,42,36,31,38,38,48,41,29,48,38,35,25,56,36,26,46,52,30,27,38,56,34,41,34,52,24,35,24,51,25,37,52,37,34,44,25,43,40,39,25,31,52,43,34,32,48,28,55,35,31,65,39,30,46,28,51,45,35,40,47,26,41,31,37,43,47,37,57,9,47,32,61,32,42,40,40,39,23,34,57,34,24,37,48,47,44,35,33,40,38,43,31,36,43,33,63,30,21,29,49,32,35,38,43,45,21,45,45,33,36,35,41,38,30,48,46,28,40,34,34,46,37,30,46,45,51,16,43,42,37,36,28,56,40,42,42,49,42,26,59,29,46,42,45,32,39,40,29,67,20,19,61,32,65,9,30,55,22,51,25,53,42,33,28,39,38,25,37,55,27,36,39,38,56,24,27,49,34,21,43,35,36,48,43,38,41,55,19,23,36,45,44,29,41,42,35,41,33,41,20,51,52,42,44,37,32,36,59,36,41,44,29,38,48,18,55,45,23,47,45,42,36,46,19,59,41,22,43,33,47,36,27,49,20,46,14,42,40,45,37,50,37,49,33,44,33,33,31,31,37,41,57,45,21,37,50,42,50,16,45,56,37,18,52,55,25,31,35,36,29,53,36,30,54,43,52,47,22,44,34,33,32,33,53,37,12,60,36,23,25,45,23,36,36,37,39,33,60,38,65,19,46,25,29,32,42,46,30,35,35,49,30,34,30,50,50,19,30,47,52,35,47,48,31,47,34,30,49,47,24,62,33,28,40,30,51,27,46,51,37,39,48,25,54,28,51,36,41,38,38,27,55,23,54,34,54,39,36,39,36,37,37,28,36,59,38,34,39,37,38,43,47,39,37,26,26,42,32,35,37,31,45,36,37,25,40,22,24,52,36,29,52,33,51,36,44,19,49,61,32,45,56,29,48,30,28,35,35,57,42,35,29,40,46,38,30,46,33,43,35,57,8,34,62,20,42,45,34,51,47,31,39,38,32,47,22,42,24,40,44,44,23,36,46,48,49,8,42,50,17,41,45,41,54,32,56,30,29,20,49,41,50,30,33,39,36,39,35,31,50,25,61,27,47,28,38,29,46,33,33,37,51,27,48,46,45,51,17,38,42,50,41,38,43,40,43,22,53,38,30,44,25,53,22,42,42,30,53,20,37,31,37,28,47,34,53,46,18,32,52,35,62,31,19,45,45,49,49,23,45,39,41,51,31,52,36,37,32,31,35,53,40,42,63,16,30,26,35,38,40,53,31,25,24,58,32,37,28,50,43,36,52,32,58,38,25,47,46,17,55,25,43,41,33,44,52,34,31,47,34,48,43,14,35,50,36,43,46,20,34,32,46,31,45,30,38,26,44,55,29,30,29,38,44,39,40,24,53,30,32,53,46,33,34,31,47,48,34,48,31,48,30,33,45,44,39,43,44,47,34,38,39,46,15,41,39,32,57,35,43,41,46,36,22,49,33,42,30,44,28,33,49,52,23,48,18,62,26,35,41,39,52,20,44,45,42,50,15,44,32,42,52,33,35,19,30,51,42,59,45,16,31,36,46,44,31,25,37,59,35,43,41,23,38,29,42,52,41,34,33,53,54,21,32,28,46,43,37,43,30,49,40,19,37,69,5,49,56,32,32,38,41,30,33,27,38,30,28,48,42,38,33,23,49,39,20,49,38,36,21,37,43,36,53,46,25,49,37,17,54,46,37,24,21,41,50,53,44,43,36,54,30,30,36,29,59,36,48,27,43,33,28,31,39,50,37,39,38,38,10,40,52,44,41,19,47,29,36,41,35,30,43,31,48,40,53,55,17,39,35,30,46,30,48,50,17,44,46,25,61,28,32,21,41,31,40,47,41,48,38,39,40,42,37,33,20,37,49,8,60,42,43,33,50,34,43,22,34,51,44,32,37,50,38,43,36,35,38,39,44,51,46,37,33,48,29,28,49,40,51,20,50,35,56,35,45,34,38,19,20,52,31,32,42,50,29,30,36,28,45,54,40,24,35,37,64,37,39,33,46,41,48,32,38,50,36,35,37,43,31,49,27,21,51,28,34,49,37,48,6,39,48,27,56,31,37,39,37,59,42,21,33,35,40,31,57,48,15,45,63,34,42,44,35,25,37,55,30,17,47,42,47,30,46,42,37,30,37,28,49,34,49,51,24,38,40,34,47,29,40,53,35,34,36,43,41,49,25,40,42,54,27,59,39,33,29,41,50,33,30,41,29,44,33,50,35,36,39,46,51,25,39,37,28,32,51,43,29,55,27,33,45,40,46,34,24,57,41,55,31,30,34,42,53,21,36,28,36,42,31,52,55,37,23,18,53,51,24,23,59,45,33,7,51,58,35,49,46,38,37,54,22,41,30,51,64,28,40,46,25,29,39,22,45,25,30,41,36,58,20,33,49,17,45,36,45,46,44,24,50,36,42,35,34,59,34,32,37,26,44,24,59,25,36,31,40,52,39,37,30,34,55,23,37,37,39,46,38,28,45,41,29,39,31,54,32,27,60,35,52,42,31,44,30,42,53,31,34,37,35,33,37,39,47,48,36,38,52,39,51,40,42,32,21,58,20,37,23,52,34,43,30,35,50,32,34,29,28,38,39,47,48,45,33,40,39,44,30,35,29,59,41,34,50,35,54,22,39,57,29,34,48,40,26,50,40,53,28,46,28,47,38,30,21,29,60,37,46,42,23,69,33,6,59,44,35,23,44,24,47,41,33,43,45,47,37,64,20,37,37,39,30,34,30,35,56,34,20,42,51,35,33,50,36,58,32,37,58,38,43,54,21,33,48,34,31,44,29,41,44,35,39,47,29,42,37,28,56,41,37,30,49,26,66,21,39,32,39,37,52,14,33,28,53,53,33,27,50,51,27,40,32,49,29,30,44,37,43,22,41,56,53,29,31,42,45,33,46,27,31,37,40,49,29,28,44,43,48,45,48,42,30,37,30,42,37,34,44,44,41,38,36,39,40,53,23,41,35,45,30,35,39,21,44,44,26,42,42,29,27,46,45,48,22,52,43,38,30,29,35,49,38,43,52,24,60,30,43,21,58,34,25,42,45,39,36,54,23,56,35,19,47,36,28,42,24,49,42,48,23,48,46,34,44,37,45,32,27,30,34,35,44,34,42,38,42,58,20,44,12,41,35,36,37,40,25,50,35,25,50,26,62,30,55,25,46,39,41,25,48,35,53,50,34,32,54,34,54,38,42,33,24,29,32,42,50,33,36,59,34,38,36,26,35,45,43,38,35,46,26,46,34,48,39,28,46,14,34,48,53,25,41,34,34,49,28,25,52,33,38,51,45,29,44,39,41,36,30,46,34,50,38,25,61,22,44,33,50,28,18,43,40,47,56,35,32,25,38,17,49,35,47,64,16,38,43,44,38,42,55,39,34,40,32,38,44,47,44,10,49,36,54,25,29,35,40,31,37,35,53,32,35,60,50,25,35,51,20,61,29,30,36,43,35,26,45,28,49,19,51,43,37,33,40,39,32,42,34,54,40,42,36,40,36,41,44,46,35,25,38,45,46,27,45,43,38,42,31,38,44,40,39,47,41,18,62,36,48,41,31,40,46,37,37,63,14,50,23,63,29,33,42,59,33,32,41,38,26,45,30,53,28,32,40,51,28,50,28,17,41,38,55,40,47,39,42,32,46,41,26,29,27,41,36,37,39,38,47,51,23,54,38,35,65,36,26,44,39,33,33,51,46,31,34,26,51,42,32,34,39,30,40,28,55,25,51,26,38,23,45,50,31,34,29,60,44,14,36,58,31,40,27,48,20,46,20,54,42,49,25,44,56,50,35,32,36,32,58,35,25,47,24,58,34,7,44,53,48,45,39,42,18,49,43,36,40,48,27,41,29,36,40,41,38,43,34,39,16,35,33,31,60,34,34,37,20,50,30,42,40,31,40,46,38,31,42,40,34,41,52,39,57,37,52,24,51,22,46,38,45,48,34,24,42,33,33,43,54,29,43,51,22,41,51,43,45,27,39,30,47,33,36,29,45,23,56,49,46,38,37,29,63,32,43,31,34,36,31,40,46,37,25,42,34,49,31,6,60,34,49,54,28,32,55,15,39,29,52,35,40,27,49,30,42,50,23,37,40,54,28,41,35,31,41,46,42,41,33,44,62,29,33,30,37,47,59,42,31,37,32,41,36,18,57,31,24,42,30,54,41,35,31,56,47,22,52,44,31,34,18,50,38,28,52,48,50,26,45,24,41,44,29,34,50,29,47,52,38,49,28,12,57,43,58,38,31,37,50,31,56,40,35,43,38,32,46,33,46,36,32,44,46,35,25,34,53,22,47,44,46,19,42,30,36,45,39,30,41,42,39,29,39,41,32,35,44,49,11,44,60,38,41,39,53,31,31,39,28,34,38,52,40,35,47,45,21,65,32,32,28,46,30,43,52,52,33,46,44,26,52,27,62,45,25,30,37,57,23,42,27,32,48,33,46,30,19,36,37,47,44,31,28,45,48,17,50,40,31,34,52,36,21,50,56,29,29,47,21,36,40,40,49,52,32,32,44,37,40,33,39,16,46,28,58,16,47,36,30,26,43,46,41,33,40,47,23,58,40,28,41,40,40,26,51,37,35,43,35,36,48,21,49,40,43,27,28,39,41,40,54,45,19,57,26,31,38,42,41,19,48,45,51,22,34,47,36,43,37,45,21,24,51,43,38,37,30,44,29,36,30,35,35,45,43,32,43,32,65,41,39,38,39,38,41,27,30,53,26,51,20,60,31,57,42,43,41,34,36,36,63,29,35,27,39,38,38,37,37,51,45,20,25,40,41,37,46,49,20,40,51,31,33,32,39,35,56,32,43,44,33,40,21,48,26,36,50,31,53,21,40,28,41,34,42,47,45,30,43,28,47,51,23,62,17,40,39,43,39,47,40,36,41,37,40,35,34,36,43,26,41,50,22,50,38,35,49,51,32,46,23,30,34,46,35,36,27,50,33,42,35,51,47,29,50,38,40,31,41,32,38,45,28,58,31,55,34,26,33,36,36,25};
const int jl=2e5;//\u5757\u957f
const int mn=121547;//\u8868\u4e2d\u7684\u6700\u5c0f\u503c\uff0c\u7528\u4e8e\u4f18\u5316\u8868\u7684\u5927\u5c0f
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003};
bool check(int x)
{
\tif(x<2) return x;
\tfor(int i=0;prime[i]*prime[i]*prime[i]<=x;i++)
\t{
\t\tif(x%prime[i]==0&&x/prime[i]%prime[i]==0)
\t\t\treturn 0;
\t\twhile(x%prime[i]==0) x/=prime[i];
\t\t//cout<<prime[i]<<endl;
\t}\t
\tint s=ceil(sqrt(x));
\treturn s*s!=x;
}
int main()
{
    int t,k,i,sum;
    cin>>t;
    for(i=1;i<=10000;i++)
    \ttable[i]+=mn;
    for(i=1;i<=10000;i++)
    \ttable[i]+=table[i-1];
    while(t--)
    {
    \tcin>>k;
    \tfor(i=0;table[i+1]<k;i++);
    \tsum=table[i];
    \tfor(i=i*jl+1;sum<k;i++)
    \t\tsum+=check(i);
    \tcout<<i-1<<endl;
\t}
}