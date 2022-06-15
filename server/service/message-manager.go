package service

import "server/entity"

func SaveMessage(message *entity.Message) {
	GetDB().Create(message)

}

func DeleteMessage(id int64) {
	GetDB().Exec("DELETE FROM messages WHERE id = ?", id)
}

func SelectUnPushMessages(userID int64, lastReceivedMessageID int64) []entity.Message {
	var messages []entity.Message
	GetDB().Where("id > ? AND received_id = ?", lastReceivedMessageID, userID).Find(&messages)
	return messages
}

func SelectHistoryMessages(userID int64, senderID int64, chatType entity.ChatType) []entity.Message {
	var messages []entity.Message
	GetDB().Where("received_id = ? AND sender_id = ? AND chart_type = ?",
		userID, senderID, chatType)
	return messages
}

func ACKMessage(messageID int64) {
	GetDB().Exec("UPDATE messages SET status = 'ACK'")
}
