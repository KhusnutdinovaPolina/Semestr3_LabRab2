package structs

import "fmt"

type Array struct {
	Data []string
}

func NewArray() *Array { return &Array{Data: []string{}} }

func (a *Array) PushBack(v string) { a.Data = append(a.Data, v) }
func (a *Array) Get(i int) string {
	if i < 0 || i >= len(a.Data) {
		return ""
	}
	return a.Data[i]
}
func (a *Array) Set(i int, v string) {
	if i >= 0 && i < len(a.Data) {
		a.Data[i] = v
	}
}
func (a *Array) RemoveAt(i int) {
	if i >= 0 && i < len(a.Data) {
		a.Data = append(a.Data[:i], a.Data[i+1:]...)
	}
}
func (a *Array) Length() int { return len(a.Data) }
func (a *Array) Print()      { fmt.Println(a.Data) }
