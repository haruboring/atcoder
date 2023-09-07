package main

import "fmt"

func main() {
	var X int
	var Y int
	fmt.Scan(&X)
	fmt.Scan(&Y)

	if X > Y{
		fmt.Println(X + X - 1)
	} else if X < Y {
		fmt.Println(Y + Y - 1)
	} else {
		fmt.Println(X + Y)
	}
}
