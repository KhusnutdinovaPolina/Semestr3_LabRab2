package tasks

import (
	"bufio"
	"fmt"
	"labrab2/structs"
	"os"
	"strconv"
	"strings"
)

func processAsteroid(st *structs.Stack, token string) {
	dir := token[len(token)-1:]
	sizeStr := token[:len(token)-1]
	curSize, _ := strconv.Atoi(sizeStr)
	alive := true

	for alive && dir == "L" && !st.IsEmpty() {
		topToken := st.TopVal()
		topDir := topToken[len(topToken)-1:]

		if topDir == "R" {
			topSize, _ := strconv.Atoi(topToken[:len(topToken)-1])
			if topSize < curSize {
				curSize -= topSize
				st.Pop()
			} else if topSize == curSize {
				st.Pop()
				alive = false
			} else {
				alive = false
				newTopSize := topSize - curSize
				st.Pop()
				if newTopSize > 0 {
					st.Push(strconv.Itoa(newTopSize) + "R")
				}
			}
		} else {
			break
		}
	}
	if alive {
		st.Push(strconv.Itoa(curSize) + dir)
	}
}

func RunTask1() {
	fmt.Println("\n=== Задание 1: Астероиды ===")
	fmt.Print("Введите астероиды (например: 30R 10L 25L): ")

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	tokens := strings.Fields(scanner.Text())

	st := &structs.Stack{}
	for _, tok := range tokens {
		processAsteroid(st, tok)
	}
	fmt.Print("Результат: ")
	st.Print()
}
