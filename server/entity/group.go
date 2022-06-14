package entity

type Group struct {
	ID      int64
	Name    string `gorm:"Column:name"`
	Members []User `gorm:"many2many:group_member"`
}

func (this *Group) GroupAddMember(user User) {
	this.Members = append(this.Members, user)
}

func (this *Group) GroupRemoveMember(user User) {
	var index int = -1
	for i := 0; i < len(this.Members); i++ {
		if this.Members[i].ID == user.ID {
			index = i
		}
	}
	if index != -1 {
		this.Members = append(this.Members[:index], this.Members[index+1:]...)
	}
}
