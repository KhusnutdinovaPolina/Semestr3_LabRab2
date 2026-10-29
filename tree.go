package structs

import "fmt"

type TNode struct {
	Data  string
	Left  *TNode
	Right *TNode
}

func NewTNode(data string) *TNode {
	return &TNode{Data: data}
}

func (t *TNode) PrintRec(prefix string, isTail bool) {
	if t == nil {
		return
	}
	childPrefix := prefix
	if isTail {
		childPrefix += "    "
	} else {
		childPrefix += "|   "
	}
	fmt.Printf("%s+-- %s\n", prefix, t.Data)
	if t.Left != nil {
		t.Left.PrintRec(childPrefix, t.Right == nil)
	}
	if t.Right != nil {
		t.Right.PrintRec(childPrefix, true)
	}
}
