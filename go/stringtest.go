package main

import "fmt"

func main() {
	var s string
	s += "Hello"
	fmt.Println(s)
	addWorld(&s)
	fmt.Println(s)
}

func addWorld(s *string) {
	*s += ", world!"
}
