package structs

import "fmt"

const TableSize = 10

// --- Метод цепочек ---
type HashTableChaining struct {
	Table [TableSize]*Array
}

func NewHashTableChaining() *HashTableChaining {
	ht := &HashTableChaining{}
	for i := 0; i < TableSize; i++ {
		ht.Table[i] = NewArray()
	}
	return ht
}

func (h *HashTableChaining) hash(key string) int {
	sum := 0
	for _, c := range key {
		sum += int(c)
	}
	return sum % TableSize
}

func (h *HashTableChaining) Insert(key string) {
	idx := h.hash(key)
	for i := 0; i < h.Table[idx].Length(); i++ {
		if h.Table[idx].Get(i) == key {
			return
		}
	}
	h.Table[idx].PushBack(key)
}

func (h *HashTableChaining) Search(key string) bool {
	idx := h.hash(key)
	for i := 0; i < h.Table[idx].Length(); i++ {
		if h.Table[idx].Get(i) == key {
			return true
		}
	}
	return false
}

func (h *HashTableChaining) Remove(key string) {
	idx := h.hash(key)
	for i := 0; i < h.Table[idx].Length(); i++ {
		if h.Table[idx].Get(i) == key {
			h.Table[idx].RemoveAt(i)
			return
		}
	}
}

func (h *HashTableChaining) Print() {
	fmt.Println("--- Хеш-таблица (Метод цепочек) ---")
	for i := 0; i < TableSize; i++ {
		fmt.Printf("[%d]: ", i)
		if h.Table[i].Length() == 0 {
			fmt.Print("NULL")
		} else {
			for j := 0; j < h.Table[i].Length(); j++ {
				fmt.Printf("%s -> ", h.Table[i].Get(j))
			}
			fmt.Print("NULL")
		}
		fmt.Println()
	}
}

// --- Кукушка ---
const CuckooSize = 10
const MaxKicks = 20

type HashTableCuckoo struct {
	Table1 [CuckooSize]string
	Table2 [CuckooSize]string
}

func NewHashTableCuckoo() *HashTableCuckoo {
	return &HashTableCuckoo{}
}

func (h *HashTableCuckoo) hash1(key string) int {
	sum := 0
	for _, c := range key {
		sum += int(c)
	}
	return sum % CuckooSize
}
func (h *HashTableCuckoo) hash2(key string) int {
	sum := 0
	for _, c := range key {
		sum += int(c) * 7
	}
	return sum % CuckooSize
}

func (h *HashTableCuckoo) Insert(key string) bool {
	if h.Search(key) {
		return true
	}

	current := key
	for i := 0; i < MaxKicks; i++ {
		pos1 := h.hash1(current)
		if h.Table1[pos1] == "" {
			h.Table1[pos1] = current
			return true
		}
		victim := h.Table1[pos1]
		h.Table1[pos1] = current
		current = victim

		pos2 := h.hash2(current)
		if h.Table2[pos2] == "" {
			h.Table2[pos2] = current
			return true
		}
		victim = h.Table2[pos2]
		h.Table2[pos2] = current
		current = victim
	}
	return false
}

func (h *HashTableCuckoo) Search(key string) bool {
	if h.Table1[h.hash1(key)] == key {
		return true
	}
	if h.Table2[h.hash2(key)] == key {
		return true
	}
	return false
}
