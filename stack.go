package structs

import "fmt"

type StackNode struct {
	Data string
	Next *StackNode
}

type Stack struct {
	Top   *StackNode
	Count int
}

func (s *Stack) Push(val string) {
	s.Top = &StackNode{Data: val, Next: s.Top}
	s.Count++
}

func (s *Stack) Pop() string {
	if s.Top == nil {
		return ""
	}
	val := s.Top.Data
	s.Top = s.Top.Next
	s.Count--
	return val
}

func (s *Stack) IsEmpty() bool { return s.Top == nil }
func (s *Stack) TopVal() string {
	if s.Top == nil {
		return ""
	}
	return s.Top.Data
}

func (s *Stack) Print() {
	fmt.Print("Стек: [")
	s.printRec(s.Top)
	fmt.Printf("] (вершина = %s)\n", s.TopVal())
}

func (s *Stack) printRec(n *StackNode) {
	if n == nil {
		return
	}
	s.printRec(n.Next)
	fmt.Print(n.Data)
	if n != s.Top {
		fmt.Print(", ")
	}
}
