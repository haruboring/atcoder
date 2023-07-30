package main

import "fmt"

func main() {
    var X int
    var Y int
    fmt.Scan(&X)
    fmt.Scan(&Y)

    if Y <= X {
        fmt.Println(0)
        return
    }

    fmt.Println((Y - X + 9) / 10)
}