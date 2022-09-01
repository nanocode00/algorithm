package main

import "fmt"

var row, col int
var idx int = 1
var grid [][]int

func main() {
	var n int
	fmt.Scan(&n, &row, &col)
	grid = make([][]int, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]int, n)
	}
	tromino(0, 0, n, col, row)
	printGrid(n)
}

func tromino(x, y, n, tx, ty int) {
	if n == 2 {
		if y == ty {
			if x == tx {
				mark(x, y, 0)
			} else {
				mark(x, y, 1)
			}
		} else {
			if x == tx {
				mark(x, y, 2)
			} else {
				mark(x, y, 3)
			}
		}
	} else {
		m := n / 2
		if ty < y+m {
			if tx < x+m {
				mark(x+m-1, y+m-1, 0)
				tromino(x, y, m, tx, ty)
				tromino(x+m, y, m, x+m, y+m-1)
				tromino(x, y+m, m, x+m-1, y+m)
				tromino(x+m, y+m, m, x+m, y+m)
			} else {
				mark(x+m-1, y+m-1, 1)
				tromino(x, y, m, x+m-1, y+m-1)
				tromino(x+m, y, m, tx, ty)
				tromino(x, y+m, m, x+m-1, y+m)
				tromino(x+m, y+m, m, x+m, y+m)
			}
		} else {
			if tx < x+m {
				mark(x+m-1, y+m-1, 2)
				tromino(x, y, m, x+m-1, y+m-1)
				tromino(x+m, y, m, x+m, y+m-1)
				tromino(x, y+m, m, tx, ty)
				tromino(x+m, y+m, m, x+m, y+m)
			} else {
				mark(x+m-1, y+m-1, 3)
				tromino(x, y, m, x+m-1, y+m-1)
				tromino(x+m, y, m, x+m, y+m-1)
				tromino(x, y+m, m, x+m-1, y+m)
				tromino(x+m, y+m, m, tx, ty)
			}
		}
	}
}

func mark(x, y, dir int) {
	if dir != 0 {
		grid[y][x] = idx
	}
	if dir != 1 {
		grid[y][x+1] = idx
	}
	if dir != 2 {
		grid[y+1][x] = idx
	}
	if dir != 3 {
		grid[y+1][x+1] = idx
	}
	idx++
}

func printGrid(n int) {
	for y := 0; y < n; y++ {
		fmt.Print(grid[y][0])
		for x := 1; x < n; x++ {
			fmt.Print(" ", grid[y][x])
		}
		fmt.Println()
	}
}
