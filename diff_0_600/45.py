A, B, C = map(int, input().split())
K = int(input())

cnt = 0
while B <= A:
    B *= 2
    cnt += 1

while C <= B:
    C *= 2
    cnt += 1

if cnt <= K:
    print("Yes")
else:
    print("No")
