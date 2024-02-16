from math import gcd

X, Y = map(int, input().split())

sswap = False
if X == 0:
    sswap = True
    X, Y = Y, X

x_reversed = False
if X < 0:
    x_reversed = True
    X = -X

y_reversed = False
if Y < 0:
    y_reversed = True
    Y = -Y

if gcd(X + 2, Y) == 1:
    print(-1)
    exit()

s = (X + 2) // gcd(X + 2, Y) * Y
s //= Y
t = Y / X * s - 2 / X

if sswap:
    s, t = t, s
if x_reversed:
    s = -s
if y_reversed:
    t = -t

print(int(s), int(t))
