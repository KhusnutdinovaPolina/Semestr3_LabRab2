package tasks

import (
	"fmt"
	"sort"
	"lab2-go/structs"
)

func countDescendants(name string, children map[string][]string) int {
	count := 0
	for _, child := range children[name] {
		count += 1 + countDescendants(child, children)
	}
	return count
}

func printTree(name string, children map[string][]string, prefix string, isLast bool) {
	fmt.Print(prefix)
	if isLast {
		fmt.Print("+-- ")
	} else {
		fmt.Print("|-- ")
	}
	fmt.Println(name)

	newPrefix := prefix
	if isLast {
		newPrefix += "    "
	} else {
		newPrefix += "|   "
	}

	kids := children[name]
	for i, child := range kids {
		printTree(child, children, newPrefix, i == len(kids)-1)
	}
}

func RunTask6() {
	for {
		fmt.Println("\n=== Задание 6 ===")
		fmt.Println("1. Метод цепочек (демо)")
		fmt.Println("2. Кукушка (демо)")
		fmt.Println("3. Подзадание 6.2: Родословная")
		fmt.Println("0. Назад")
		fmt.Print("Выбор: ")

		var choice int
		fmt.Scan(&choice)
		fmt.Scanln() // очистка буфера

		if choice == 0 {
			break
		}

		if choice == 1 {
			ht := structs.NewHashTableChaining()
			fmt.Println("Введите слова (exit - выход):")
			var word string
			for {
				fmt.Scan(&word)
				if word == "exit" {
					break
				}
				ht.Insert(word)
			}
			ht.Print()
		} else if choice == 2 {
			ht := structs.NewHashTableCuckoo()
			fmt.Println("Введите слова (exit - выход):")
			var word string
			for {
				fmt.Scan(&word)
				if word == "exit" {
					break
				}
				if !ht.Insert(word) {
					fmt.Println("Переполнение (зацикливание)!")
				}
			}
			ht.Print()
		} else if choice == 3 {
			var n int
			fmt.Print("Количество людей: ")
			fmt.Scan(&n)

			parentTable := structs.NewHashTableChaining()
			children := make(map[string][]string)
			allPeople := make(map[string]bool)
			allParents := make(map[string]bool)

			fmt.Println("Введите N-1 строк (Потомок Родитель):")
			for i := 0; i < n-1; i++ {
				var child, parent string
				fmt.Scan(&child, &parent)

				parentTable.Insert(child)
				children[parent] = append(children[parent], child)
				allPeople[child] = true
				allPeople[parent] = true
				allParents[parent] = true
			}

			// Собираем имена в срез и сортируем
			var names []string
			for name := range allPeople {
				names = append(names, name)
			}
			sort.Strings(names)

			fmt.Println("\nРезультат:")
			for _, name := range names {
				desc := countDescendants(name, children)
				fmt.Printf("%s %d\n", name, desc)
			}

			// Ищем корень и печатаем дерево
			for _, name := range names {
				if !allParents[name] {
					fmt.Println("\nСамо древо:")
					printTree(name, children, "", true)
					break
				}
			}
		}
	}
}
