#include "Database.h"


Database::Database()
{
	m_db = nullptr;
}

Database::Database(Database const& d)
{
	m_db = nullptr;
}

Database* Database::m_instance = nullptr;

Database::~Database()
{
	sqlite3_close(m_db);
	delete m_instance;
}

Database* Database::Instance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Database();
	}

	return m_instance;
}

void Database::openDb(std::string dbName)
{
	int result = sqlite3_open(dbName.c_str(), &m_db);

	//TODO: Throw exception instead of printing

	if (result)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
	}
	else
	{
		fprintf(stderr, "Opened database successfully\n");
	}
}