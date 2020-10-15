#include "User.h"

User::User()
{

}

User::User(const std::string &username, const std::string &email, const std::string &password)
{
	this->username = username;
	this->email = email;
	this->password = password;
}

User::~User()
{

}

void User::insertIntoDB(sqlite3* db)
{
	Wrapper wr(db, std::string("INSERT INTO USER (USERNAME, EMAIL, PASSWORD) VALUES(?, ?, ?)"));

	wr.bindString(1, username);
	wr.bindString(2, email);
	wr.bindString(3, password);

	wr.step();
}