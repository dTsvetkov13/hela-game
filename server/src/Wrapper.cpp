#include "Wrapper.h"

Wrapper::Wrapper(sqlite3* db, std::string &sql)
{
	m_error = sqlite3_prepare_v2(db, sql.c_str(), -1, &m_stmt, 0);

	if (m_error != SQLITE_OK)
	{
		//TODO: throw exception
		std::cout << "Error in constructor: " << sqlite3_errmsg(db) << "\n";
		throw(m_error);
	}
}

Wrapper::~Wrapper()
{
	sqlite3_reset(m_stmt);
	sqlite3_finalize(m_stmt);
	//delete m_stmt;
}

void Wrapper::bindInt(int index, int value)
{
	m_error = sqlite3_bind_int(m_stmt, index, value);

	if (m_error != SQLITE_OK)
	{
		//TODO: throw exception
		std::cout << "Error binding int\n";
		throw(m_error);
	}
}

void Wrapper::bindString(int index, const std::string &value)
{
	m_error = sqlite3_bind_text(m_stmt, index, value.c_str(), std::strlen(value.c_str()), SQLITE_TRANSIENT);

	if (m_error != SQLITE_OK)
	{
		//TODO: throw exception
		std::cout << "Error binding string\n";
		throw(m_error);
	}
}

void Wrapper::bindDouble(int index, double value)
{
	m_error = sqlite3_bind_double(m_stmt, index, value);

	if (m_error != SQLITE_OK)
	{
		//TODO: throw exception
		std::cout << "Error binding double\n";
		throw(m_error);
	}
}

int Wrapper::step()
{
	m_error = sqlite3_step(m_stmt);

	if (m_error != SQLITE_ROW && m_error != SQLITE_OK && m_error != SQLITE_DONE)
	{
		std::cout << "Error in stepping\n";
		throw(m_error);
	}
	else
	{
		return m_error;
	}
}

sqlite3_stmt* Wrapper::getStatement()
{
	return m_stmt;
}