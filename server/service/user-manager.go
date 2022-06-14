package service

import (
	"gorm.io/gorm"
	"server/entity"
)

func FindUser(id int64) *entity.User {
	user := new(entity.User)
	user.ID = id

	result := GetDB().First(user)
	if result.Error == nil {
		return user
	} else {
		return nil
	}
}

func UpdateUser(user entity.User) {
	GetDB().Updates(&user)
}

func CreateUser(user *entity.User) {
	GetDB().Create(user)
}

func UserAddFriend(userID int64, friendID int64) {

	db.Transaction(func(tx *gorm.DB) error {

		if err := db.Exec("INSERT INTO friends VALUES(?, ?)", userID, friendID).Error; err != nil {
			return err
		}
		if err := db.Exec("INSERT INTO friends VALUES(?, ?)", friendID, userID).Error; err != nil {
			return err
		}

		return nil
	})
}

func UserRemoveFriend(userID int64, friendID int64) {
	db.Transaction(func(tx *gorm.DB) error {

		if err := db.Exec("DELETE FROM friends WHERE user_id = ? AND friend_id = ?", userID, friendID).Error; err != nil {
			return err
		}

		if err := db.Exec("DELETE FROM friends WHERE user_id = ? AND friend_id = ?", friendID, userID).Error; err != nil {
			return err
		}
		return nil

	})
}
