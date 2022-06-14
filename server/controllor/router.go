package controllor

import "github.com/gin-gonic/gin"

func Run() {
	router := gin.Default()
	router.GET("/add-friend/:user-id/:friend-id", addFriend)
	router.GET("/remove-friend/:user-id/:friend-id", removeFriend)
	router.GET("/join-group/:user-id/:group-id", joinGroup)
	router.GET("/leave-group/:user-id/:group-id", leaveGroup)
	router.GET("/get-chats/:user-id", getChats)
	//router.POST("/send-massage/:from/:to")
	router.Run()
}
