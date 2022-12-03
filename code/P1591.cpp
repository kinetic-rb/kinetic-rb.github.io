t = Integer(gets)
for j in 1..t
    n, a = gets.split.map(&:to_i)
    aum, cnt = 1, 0
    for i in 2..n
        aum *= i
    end
    while aum != 0
        if aum % 10 == a
            cnt += 1
        end
        aum /= 10;
    end
    print cnt, "\n"
end