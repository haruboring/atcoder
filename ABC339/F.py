N = int(input().strip())
A = [int(input().strip()) for _ in range(N)]


set_A = set(A)
map_A = {}
for i in range(N):
    map_A[A[i]] = 0
for i in range(N):
    map_A[A[i]] += 1

cnt = {}
for i in range(N):
    cnt[A[i] * A[i]] = 0

for i in range(N):
    for j in range(N):
        seki = A[i] * A[j]
        if seki in set_A:
            cnt[seki] += 1
ans = 0
for seki, c in cnt.items():
    ans += c * map_A[seki]
print(ans)
