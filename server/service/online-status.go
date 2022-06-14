package service

import (
	"server/entity"
	"sync"
	"time"
)

var onlineList sync.Map

func IsOnline(id entity.UserID) bool {
	_, ok := onlineList.Load(id)
	return ok
}

func SetOnline(id entity.UserID) {
	onlineList.Store(id, time.Now())
}

func OffLine(id entity.UserID) {
	onlineList.Delete(id)
}

func clear() {
	// 每5s更新
	ticker := time.NewTicker(5 * time.Second)
	for _ = range ticker.C {
		onlineList.Range(func(key, value any) bool {
			if value.(time.Time).Add(10 * time.Second).Before(time.Now()) {
				onlineList.Delete(key)
			}
			return true
		})
	}
}
func init() {
	go clear()
}
