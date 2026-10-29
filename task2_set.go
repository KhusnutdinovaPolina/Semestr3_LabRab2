package tasks

import (
	"fmt"
	"labrab2/structs"
	"strings"
)

func RunTask2Console(filename, query string) {
	set := structs.NewMySet()
	// Загрузка из файла (опущена для краткости, аналогично C++)

	parts := strings.Fields(query)
	if len(parts) < 2 {
		return
	}
	cmd, val := parts[0], parts[1]

	switch cmd {
	case "SETADD":
		set.Add(val)
		fmt.Println("Добавлено:", val)
	case "SETDEL":
		set.Remove(val)
		fmt.Println("Удалено:", val)
	case "SET_AT":
		if set.Contains(val) {
			fmt.Println("TRUE")
		} else {
			fmt.Println("FALSE")
		}
	case "PRINT":
		set.Print()
	}
}
