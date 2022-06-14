package service

import (
	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

func openDB() *gorm.DB {
	res, err := gorm.Open(sqlite.Open("db/im.db"))
	if err != nil {
		panic("failed open database")
	}
	return res
}

var db *gorm.DB = openDB()

func GetDB() *gorm.DB {
	return db
}
