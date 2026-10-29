package tasks

import (
	"fmt"
	"labrab2/structs"
	"strconv"
)

func insertBST(root **structs.TNode, val int, depth int) int {
	if *root == nil {
		*root = structs.NewTNode(strconv.Itoa(val))
		return depth
	}
	rootVal, _ := strconv.Atoi((*root).Data)
	if val < rootVal {
		return insertBST(&(*root).Left, val, depth+1)
	}
	if val > rootVal {
		return insertBST(&(*root).Right, val, depth+1)
	}
	return 0
}

func RunTask5() {
	fmt.Println("\n=== Задание 5: Глубина добавляемых элементов ===")
	fmt.Println("Введите числа (0 - конец):")
	var root *structs.TNode
	for {
		var val int
		fmt.Scan(&val)
		if val == 0 {
			break
		}
		depth := insertBST(&root, val, 1)
		if depth > 0 {
			fmt.Print(depth, " ")
		}
	}
	fmt.Println()
}
