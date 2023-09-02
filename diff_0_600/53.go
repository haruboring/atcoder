package main

import (
	"fmt"
	"sort"
)

func main() {
	var S string
	fmt.Scan(&S)

	strings := []string{}
	for i := 0; i < len(S); i++ {
		var tmp string
		for j := 0; j < len(S); j++ {
			tmp += string(S[(i + j) % len(S)])
		}
		strings = append(strings, tmp)
	}

	sort.Strings(strings)
	fmt.Println(strings[0])
	fmt.Println(strings[len(strings) - 1])
}