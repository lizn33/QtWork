package main

import "fmt"
import "database/sql"

func main() {
	fmt.Println("Hello World")
	db, _ := sql.Open("sqlite3", "db/hello.db")
	db.Exec("SELECT * FROM a")

}
