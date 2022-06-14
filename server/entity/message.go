package entity

import "time"

type Message struct {
	ID           int64
	SenderId     int64     `gorm:"Column:sender_id"`
	ReceiverId   int64     `gorm:"Column:receiver_id"`
	ChartType    string    `gorm:"Column:chart_type"`
	Type         string    `gorm:"Column:type"`
	Content      string    `gorm:"Column:content"`
	SendTime     time.Time `gorm:"Column:send_time"`
	ReceivedTime time.Time `gorm:"Column:received_time"`
	Status       string    `gorm:"Column:status"`
}
