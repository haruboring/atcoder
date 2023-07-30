package main

import "fmt"

func main() {
		var L, R int
		fmt.Scan(&L)
		fmt.Scan(&R)
    var S string
		fmt.Scan(&S)

		var ans string
		for i := 0; i < L - 1; i++ {
				ans += string(S[i])
		}
		for i := 0; i < R - L + 1; i++ {
				ans += string(S[R - 1 - i])
		}
		for i := R; i < len(S); i++ {
				ans += string(S[i])
		}
		fmt.Println(ans)
}