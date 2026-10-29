package tasks

import (
	"labrab2/structs"
)

func RunTask6() {
	ht := structs.NewHashTableChaining()
	ht.Insert("apple")
	ht.Insert("banana")
	ht.Print()
}
