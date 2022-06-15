package controllor

import (
	"github.com/gin-gonic/gin"
	"server/service"
	"strconv"
)

// "/add-friend/:user-id/:friend-id"
func addFriend(c *gin.Context) {

	userIDStr := c.Param("user-id")
	friendIDStr := c.Param("friend-id")

	userID, _ := strconv.ParseInt(userIDStr, 10, 64)
	friendID, _ := strconv.ParseInt(friendIDStr, 10, 64)
	service.UserAddFriend(userID, friendID)
}

// "/remove-friend/:user_id/:friend_id
func removeFriend(c *gin.Context) {
	userIDStr := c.Param("user-id")
	friendIDStr := c.Param("friend-id")

	userID, _ := strconv.ParseInt(userIDStr, 10, 64)
	friendID, _ := strconv.ParseInt(friendIDStr, 10, 64)
	service.UserRemoveFriend(userID, friendID)
}

func getChats(c *gin.Context) {
	userIDStr := c.Param("user-id")
	userID, _ := strconv.ParseInt(userIDStr, 10, 64)
	user := service.FindUser(userID)
	user.ID = 0
	user.Name = ""
	c.JSON(200, user)
}
