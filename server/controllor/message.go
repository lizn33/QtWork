package controllor

import (
	"github.com/gin-gonic/gin"
	"net/http"
	"server/entity"
	"server/service"
	"strconv"
)

func sendMessage(c *gin.Context) {

	var message entity.Message

	if err := c.ShouldBind(&message); err != nil {
		c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
	}
	service.SaveMessage(&message)
}

func getHistoryMessages(c *gin.Context) {
	userIDStr := c.Param("user-id")
	senderIDStr := c.Param("sender-id")
	chatType := c.Param("chart-type")

	userID, _ := strconv.ParseInt(userIDStr, 10, 64)
	senderID, _ := strconv.ParseInt(senderIDStr, 10, 64)

	messages := service.SelectHistoryMessages(userID, senderID, entity.ChatType(chatType))
	c.JSON(200, messages)

}

func getUnPushMessages(c *gin.Context) {
	userIDStr := c.Param("user-id")
	lastReceivedIDStr := c.Param("last-received-id")

	userID, _ := strconv.ParseInt(userIDStr, 10, 64)
	lastReceivedID, _ := strconv.ParseInt(lastReceivedIDStr, 10, 64)
	service.SelectUnPushMessages(userID, lastReceivedID)

}
