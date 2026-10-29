package main

import (
	"fmt"
	"labrab2/tasks" // Обрати внимание: здесь должно быть имя твоего модуля!
	"os"
)

func main() {
	// Проверка аргументов для Задания 2 (СУБД)
	if len(os.Args) > 4 && os.Args[1] == "--file" && os.Args[3] == "--query" {
		tasks.RunTask2Console(os.Args[2], os.Args[4])
		return
	}

	for {
		fmt.Println("\n=== Лабораторная работа №2 (Go) ===")
		fmt.Println("1. Астероиды (Стек)")
		fmt.Println("2. АТД Множество (демо)")
		fmt.Println("3. Черепахи")
		fmt.Println("4. Гистограмма")
		fmt.Println("5. Дерево (Глубина)")
		fmt.Println("6. Хеш-таблица")
		fmt.Println("7. LFU Cache")
		fmt.Println("0. Выход")
		fmt.Print("Выберите задание: ")

		var choice int
		_, err := fmt.Scan(&choice)
		if err != nil {
			// Очистка буфера, чтобы не было бесконечного цикла при ошибке ввода
			var dump string
			fmt.Scanln(&dump)
			continue
		}
		fmt.Scanln() // очистка после ввода числа

		switch choice {
		case 1:
			tasks.RunTask1()
		case 2:
			fmt.Println("Для задания 2 используйте запуск через консоль: go run main.go --file data.txt --query 'SETADD apple'")
		case 3:
			tasks.RunTask3()
		case 4:
			tasks.RunTask4()
		case 5:
			tasks.RunTask5()
		case 6:
			tasks.RunTask6()
		case 7:
			tasks.RunTask7()
		case 0:
			return
		default:
			fmt.Println("Неверный выбор")
		}
	}
}
