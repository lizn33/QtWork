package service

import (
	"server/entity"
)

func FindGroup(groupID int64) *entity.Group {
	group := new(entity.Group)
	group.ID = int64(groupID)

	result := GetDB().First(group)
	if result.Error == nil {
		return group
	} else {
		return nil
	}
}

func GroupAddMember(groupID int64, memberID int64) bool {
	return db.Exec("INSERT INTO group_member VALUES(?,?)", groupID, memberID).Error == nil
}

func GroupRemoveMember(groupID int64, memberID int64) {
	db.Exec("DELETE FROM group_member WHERE group_id = ? AND member_id = ?", groupID, memberID)
}
