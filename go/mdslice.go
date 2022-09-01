package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	m := make([][]int, n)
	for i := 0; i < n; i++ {
		m[i] = make([]int, n)
		for j := 0; j < n; j++ {
			m[i][j] = i + j
		}
	}

	printM(n, m)
	fmt.Println()

	modify(n, m)

	printM(n, m)
}

func printM(n int, m [][]int) {
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Print(m[i][j], " ")
		}
		fmt.Println()
	}
}

func modify(n int, m [][]int) {
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			m[i][j] = i*n + j
		}
	}
}
