package structs

type MySet struct {
	ht *HashTableChaining
}

func NewMySet() *MySet { return &MySet{ht: NewHashTableChaining()} }

func (s *MySet) Add(key string)           { s.ht.Insert(key) }
func (s *MySet) Remove(key string)        { s.ht.Remove(key) }
func (s *MySet) Contains(key string) bool { return s.ht.Search(key) }
func (s *MySet) Print()                   { s.ht.Print() }
