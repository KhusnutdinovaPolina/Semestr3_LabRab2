package tasks

import (
	"fmt"
	"labrab2/structs"
)

func RunTask7() {
	fmt.Println("\n=== Задание 7: LFU Cache ===")
	var cap, q int
	fmt.Print("Введите емкость (cap): ")
	fmt.Scan(&cap)
	fmt.Print("Введите кол-во запросов (Q): ")
	fmt.Scan(&q)

	cache := structs.NewLFUCache(cap)
	fmt.Println("Введите запросы (SET k v / GET k):")

	for i := 0; i < q; i++ {
		var cmd string
		fmt.Scan(&cmd)
		if cmd == "SET" {
			var k, v int
			fmt.Scan(&k, &v)
			cache.Set(k, v)
		} else if cmd == "GET" {
			var k int
			fmt.Scan(&k)
			fmt.Print(cache.Get(k), " ")
		}
	}
	fmt.Println()
}
