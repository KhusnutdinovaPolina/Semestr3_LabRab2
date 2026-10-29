package structs

import "fmt"

type LFUNode struct {
	Key, Value, Frequency, Timestamp int
}

type LFUCache struct {
	Capacity    int
	Items       []*LFUNode
	CurrentTime int
}

func NewLFUCache(cap int) *LFUCache {
	return &LFUCache{Capacity: cap}
}

func (c *LFUCache) Set(key, value int) {
	for _, item := range c.Items {
		if item.Key == key {
			item.Value = value
			item.Frequency++
			item.Timestamp = c.CurrentTime
			c.CurrentTime++
			return
		}
	}

	if len(c.Items) == c.Capacity {
		minIdx := 0
		for i := 1; i < len(c.Items); i++ {
			if c.Items[i].Frequency < c.Items[minIdx].Frequency ||
				(c.Items[i].Frequency == c.Items[minIdx].Frequency && c.Items[i].Timestamp < c.Items[minIdx].Timestamp) {
				minIdx = i
			}
		}
		c.Items = append(c.Items[:minIdx], c.Items[minIdx+1:]...)
	}

	c.Items = append(c.Items, &LFUNode{key, value, 1, c.CurrentTime})
	c.CurrentTime++
}

func (c *LFUCache) Get(key int) int {
	for _, item := range c.Items {
		if item.Key == key {
			item.Frequency++
			item.Timestamp = c.CurrentTime
			c.CurrentTime++
			return item.Value
		}
	}
	return -1
}

func (c *LFUCache) Print() {
	fmt.Print("Кэш: [")
	for i, item := range c.Items {
		if i > 0 {
			fmt.Print(", ")
		}
		fmt.Printf("%d:%d(f=%d)", item.Key, item.Value, item.Frequency)
	}
	fmt.Println("]")
}
