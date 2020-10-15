#pragma once

#include <google/protobuf/stubs/common.h>
#include "sqlite3.h"
#include <string>

class Wrapper
{
public:
	Wrapper(sqlite3* db, std::string &sql);
	~Wrapper();

	void bindInt(int index, int value);
	void bindString(int index, const std::string &value);
	void bindDouble(int index, double value);

	int step();
	sqlite3_stmt* getStatement();

private:
	Wrapper();
	sqlite3_stmt* m_stmt; //TODO: use smart pointer
	int m_error;
};