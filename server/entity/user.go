package entity

type UserID int64

type User struct {
	ID                    int64   `json:"id,omitempty"`
	Name                  string  `gorm:"Column:name"json:"name,omitempty"`
	Password              string  `gorm:"Column:password"`
	LastReceivedMessageId int64   `gorm:"Column:last_received_message_id"`
	Friends               []User  `gorm:"many2many:friends"json:"friends"`
	Groups                []Group `gorm:"many2many:group_member"json:"groups"`
}

func (this *User) AddFriend(friend User) {
	this.Friends = append(this.Friends, friend)
}

func (this *User) RemoveFriend(friend User) {
	var index int = -1
	for i := 0; i < len(this.Friends); i++ {
		if this.Friends[i].ID == friend.ID {
			index = i
		}
	}
	if index != -1 {
		this.Friends = append(this.Friends[:index], this.Friends[index+1:]...)
	}
}

func (this *User) JoinGroup(group Group) {
	this.Groups = append(this.Groups, group)
}

func (this *User) LeaveGroup(group Group) {
	var index int = -1
	for i := 0; i < len(this.Groups); i++ {
		if this.Groups[i].ID == group.ID {
			index = i
		}
	}

	if index != -1 {
		this.Groups = append(this.Groups[:index], this.Groups[index+1:]...)
	}
}
