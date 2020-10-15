#pragma once

#include <string>

#include "Wrapper.h"

class User
{
public:
	User();
	User(const std::string& username, const std::string& email, const std::string& password);
	~User();

	void insertIntoDB(sqlite3* db);
private:
	std::string username;
	std::string email;
	std::string password;
};