package controllor

import (
	"github.com/gin-gonic/gin"
	"server/service"
	"strconv"
)

// "/join-group/:user-id/:group-id
func joinGroup(c *gin.Context) {
	userIDStr := c.Param("user-id")
	friendIDStr := c.Param("group-id")

	userID, _ := strconv.ParseInt(userIDStr, 10, 64)
	groupID, _ := strconv.ParseInt(friendIDStr, 10, 64)
	service.GroupAddMember(groupID, userID)
}

// */leave-group/:user-id/:group-id
func leaveGroup(c *gin.Context) {
	userIDStr := c.Param("user-id")
	friendIDStr := c.Param("group-id")

	userID, _ := strconv.ParseInt(userIDStr, 10, 64)
	groupID, _ := strconv.ParseInt(friendIDStr, 10, 64)
	service.GroupRemoveMember(groupID, userID)
}
