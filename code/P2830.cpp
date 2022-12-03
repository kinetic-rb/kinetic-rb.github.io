import sys, re
try:
    for line in sys.stdin:
        _a, _b = [_i.strip() for _i in line.split()]
        _b = str(_b)
        if _a == "int":
            _obj = re.match(r'(.*?)\[(.*)\]', _b, re.M | re.I)
            exec(_obj.group(1) + '= [0] * ' + _obj.group(2))
        elif _a == "cout":
            exec("print(" + _b + ")")
        else:
            exec(_a + '=' + _b)
except IndexError:
    print(-1)