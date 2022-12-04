import requests
import time
from urllib.parse import unquote

headers = {
  "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36",
  "cookie": "_uid=413140; __client_id=e64642f755f61c11008fa3c75a642edc43b9b9f3"
}

for i in range(200, 0, -1):
  now = 0
  lst = []
  r = requests.get(headers = headers, url = "https://www.luogu.com.cn/record/list?user=413140&status=12&page=" + str(i))
  while r.status_code != 200:
    r = requests.get(headers = headers, url = "https://www.luogu.com.cn/record/list?user=413140&status=12&page=" + str(i))
  r = unquote(r.text)
  while r.find(",\"id\":", now) != -1:
    loc = r.find(",\"id\":", now) + 6
    now = loc + 8
    lst.insert(0, r[loc : loc + 8])
  for j in lst:
    x = requests.get(headers = headers, url = "https://www.luogu.com.cn/record/" + j)
    while x.status_code != 200:
      x = requests.get(headers = headers, url = "https://www.luogu.com.cn/record/" + j)
    x = unquote(x.text)
    l1 = x.find("\"problem\":{\"pid\":\"")
    l2 = x.find(",\"title\"")
    loc1 = x.find("\"sourceCode\":")
    loc2 = x.find("\"time\":", loc1);
    s = x[loc1 + 14 : loc2 - 2].replace("\\/", "/")
    s = s.replace("\\r\\n", "\n")
    s = s.replace("\\\\", "\\")
    s = s.replace("\\\"", "\"")
    s = s.replace("\\n", "\n")
    s = s.replace("'\n'", "'\\n'")
    s = s.replace("\"\n\"", "\"\\n\"")
    s = s.replace("\\t", "  ")
    s = s.replace("'  '", "'\t'")
    s = s.replace("\"  \"", "\"\t\"")
    file = open(x[l1 + 18 : l2 - 1] + ".cpp", "w")
    file.write(s)
    file.close()
