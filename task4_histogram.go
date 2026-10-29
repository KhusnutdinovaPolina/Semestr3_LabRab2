package tasks

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func RunTask4() {
	fmt.Println("\n=== Задание 4: Гистограмма ===")
	fmt.Println("Введите текст:")

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	text := scanner.Text()

	counts := make([]int, 128)
	maxHeight := 0

	for _, c := range text {
		if c == ' ' || c == '\n' || c == '\r' {
			continue
		}
		counts[c]++
		if counts[c] > maxHeight {
			maxHeight = counts[c]
		}
	}

	for h := maxHeight; h > 0; h-- {
		var sb strings.Builder
		for i := 0; i < 128; i++ {
			if counts[i] >= h {
				sb.WriteString("#")
			} else if counts[i] > 0 {
				sb.WriteString(" ")
			}
		}
		fmt.Println(sb.String())
	}
	for i := 0; i < 128; i++ {
		if counts[i] > 0 {
			fmt.Printf("%c", i)
		}
	}
	fmt.Println()
}
