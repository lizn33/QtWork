package service

import (
	"fmt"
	"github.com/gorilla/websocket"
	"server/entity"
	"strconv"
	"sync"
)

type Client struct {
	UserID           int64
	socketConnection *websocket.Conn
	Close            chan bool
	Read             chan *entity.Message
	Write            chan *entity.Message
}

func ClientNew(ID int64, conn *websocket.Conn) *Client {
	client := new(Client)
	*client = Client{
		UserID:           ID,
		socketConnection: conn,
		Close:            make(chan bool),
		Read:             make(chan *entity.Message),
		Write:            make(chan *entity.Message),
	}

	go func() {
		defer func() {
			Manager.Unregister <- ID
			client.socketConnection.Close()
		}()

		for {
			select {
			case close := <-client.Close:
				if close {
					return
				}
			case message := <-client.Write:
				if client.socketConnection.WriteJSON(message) != nil {
					return
				}
			}
		}
	}()

	go func() {
		client.socketConnection.Close()
		for {
			_, message, err := conn.ReadMessage()
			if err != nil {
				return
				fmt.Printf("%d disconnect\n", ID)
			}

			messageID, _ := strconv.ParseInt(string(message), 10, 64)
			ACKMessage(messageID)

			fmt.Println(string(message))
		}
	}()
	return client
}

type ClientManager struct {
	Clients       sync.Map
	Register      chan *Client
	Unregister    chan int64
	MessageBuffer chan *entity.Message
}

var Manager = ClientManager{
	Register:      make(chan *Client),
	Unregister:    make(chan int64),
	MessageBuffer: make(chan *entity.Message),
}

func Start() {
	for {
		select {
		case registerClient := <-Manager.Register:
			Manager.Clients.Store(registerClient.UserID, registerClient)
		case unregisterID := <-Manager.Unregister:
			if client, ok := Manager.Clients.LoadAndDelete(unregisterID); ok {
				client.(Client).Close <- true
			}
		case messageBuffer := <-Manager.MessageBuffer:
			if v, ok := Manager.Clients.Load(messageBuffer.ReceiverId); ok {
				client := v.(Client)
				select {
				case client.Write <- messageBuffer:
				default:
					close(client.Write)
					Manager.Clients.Delete(client.UserID)
				}
			}
		}
	}
}

func init() {
	Start()
}

func (manager *ClientManager) Login(client *Client) {
	manager.Register <- client
}

func (manager *ClientManager) Logout(ID int64) {
	manager.Unregister <- ID
}

func (manager *ClientManager) IsOnline(ID int64) bool {
	_, ok := manager.Clients.Load(ID)
	return ok
}

func GetManager() *ClientManager {
	return &Manager
}
