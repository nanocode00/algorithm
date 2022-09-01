package main

import "fmt"

const INF = 999999

func minimum(i int, j int, mink *int, d []int, M [][]int) int {
	minValue, value := INF, 0
	for k := i; k <= j-1; k++ {
		value = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j]
		if minValue > value {
			minValue = value
			*mink = k
		}
	}
	return minValue
}

func minmult(n int, d []int, M [][]int, P [][]int) {
	for i := 1; i <= n; i++ {
		M[i][i] = 0
	}
	for diagonal := 1; diagonal <= n-1; diagonal++ {
		for i := 1; i <= n-diagonal; i++ {
			j, k := i+diagonal, 0
			M[i][j] = minimum(i, j, &k, d, M)
			P[i][j] = k
		}
	}
}

func order(i int, j int, P [][]int, s *string) {
	*s += "("
	if i == j {
		*s += "A" + fmt.Sprint(i)
	} else {
		k := P[i][j]
		order(i, k, P, s)
		order(k+1, j, P, s)
	}
	*s += ")"
}

func printmatrix(n int, m [][]int) {
	for i := 1; i <= n; i++ {
		fmt.Print(m[i][i])
		for j := i + 1; j <= n; j++ {
			fmt.Print(" ")
			fmt.Print(m[i][j])
		}
		fmt.Println()
	}
}

func main() {
	var n int
	s := ""
	fmt.Scan(&n)
	d := make([]int, n+1)
	for i := 0; i <= n; i++ {
		fmt.Scan(&d[i])
	}
	M := make([][]int, n+1)
	P := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		M[i] = make([]int, n+1)
		P[i] = make([]int, n+1)
	}
	minmult(n, d, M, P)
	order(1, n, P, &s)
	printmatrix(n, M)
	printmatrix(n, P)
	fmt.Println(M[1][n])
	fmt.Println(s)
}
