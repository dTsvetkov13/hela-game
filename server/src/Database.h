#pragma once

#include <string>
#include "sqlite3.h"

#include "User.h"

class Database
{
public:
	~Database();
	static Database* Instance();
	
	void openDb(std::string dbName);
	
	//Test insertion, should be changed
	void Insert(User u)
	{
		u.insertIntoDB(m_db);
	}

private:
	Database();
	Database(Database const& d);

	static Database* m_instance;
	sqlite3 *m_db;
};