extern "C" int Seniorious(int);           // \u5728\u8fd9\u91cc\u9700\u8981\u58f0\u660e\u4e00\u6b21\u4ea4\u4e92\u5e93\u7ed9\u51fa\u7684\u51fd\u6570\u3002

extern "C" int Chtholly(int n, int OvO) { // \u5728\u8fd9\u91cc\u5b9e\u73b0\u4ea4\u4e92\u5e93\u8981\u6c42\u4f60\u5b9e\u73b0\u7684\u51fd\u6570\u3002
  int ans = 1;
  for (int l = 1, r = n, mid = (l + r) >> 1; l <= r; mid = (l + r) >> 1) if (Seniorious(mid) >= 0) {
    r = (ans = mid) - 1;
  } else {
    l = mid + 1;
  }
  return ans;
}
