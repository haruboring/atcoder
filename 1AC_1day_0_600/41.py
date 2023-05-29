def main():
    S = input()
    T = input()
    if S == T:
        print("Yes")
        return

    cnt = 0
    for i in range(len(S)):
        if S[i] != T[i]:
            cnt += 1

    for i in range(len(S)):
        if cnt == 2 and S[i] != T[i] and i + 1 < len(S) and S[i] == T[i + 1] and S[i + 1] == T[i]:
            print("Yes")
            return

    print("No")


if __name__ == "__main__":
    main()
