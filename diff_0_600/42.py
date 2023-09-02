def main():
    S = int(input())
    A: list[int] = []
    B: list[int] = []
    G: list[list[int]] = [[] for _ in range(S)]
    for i in range(S - 1):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)
        G[a - 1].append(b - 1)
        G[b - 1].append(a - 1)

    reef_cnt: int = 0
    for i in range(S):
        if len(G[i]) == 1:
            reef_cnt += 1
        elif len(G[i]) == S - 1:
            continue

        else:
            print("No")
            return

    print("Yes")


if __name__ == "__main__":
    main()
