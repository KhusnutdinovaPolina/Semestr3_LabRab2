package tasks

import (
	"fmt"
	"labrab2/structs"
	"strconv"
)

func RunTask3() {
	fmt.Println("\n=== Задание 3: Черепахи ===")
	var N int
	fmt.Print("Введите количество черепах: ")
	fmt.Scan(&N)

	set := structs.NewMySet()
	trueCount := 0

	fmt.Println("Введите пары (впереди позади):")
	for i := 0; i < N; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		if a+b+1 == N {
			pos := a + 1
			posStr := strconv.Itoa(pos)
			if !set.Contains(posStr) {
				set.Add(posStr)
				trueCount++
			}
		}
	}
	fmt.Println("Максимальное количество правдивых черепах:", trueCount)
}
