n = int(input())
a, b, i = 0, 1, 2
while i < n:
  t = b
  b = (a + b) * i
  a = t
  i += 1
print(b)