/* Copyright 2008, 2010, Oracle and/or its affiliates. All rights reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

There are special exceptions to the terms and conditions of the GPL
as it is applied to this software. View the full text of the
exception in file EXCEPTIONS-CONNECTOR-C++ in the directory of this
software distribution.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
Include directly the different
headers from cppconn/ and mysql_driver.h + mysql_util.h
(and mysql_connection.h). This will reduce your build time!
*/

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void)
{
	cout << endl;
//	cout << "Running 'SELECT 'Hello World!' AS _message'...'" << endl;

	try
	{
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;

		/* Create a connection */

		driver = get_driver_instance();
		con = driver->connect("localhost", "root", "password");
		/* Connect to the MySQL test database */
		con->setSchema("gamesfleadh2016");

		stmt = con->createStatement();
//		stmt->executeUpdate("insert into card");
//		res = stmt->executeQuery("SELECT 'Hello World!' AS _message");

		stmt->execute("create table if not exists profile( username varchar(20), score int(6));");

//		stmt->executeUpdate("insert into playerprofile values ('player', 200);");

		res = stmt->executeQuery("select username, score from profile;");
		// 
		std::string data;
		while (res->next())
		{
			
//			std::istream* retrievedPassword_stream = res->getBlob("username");
//			cout << retrievedPassword_stream << endl;
			//if (retrievedPassword_stream)
			//{
			//	char pws[11] = "helloworld";
			//	retrievedPassword_stream->getline(pws, 10);
			//	std::string x = pws;
			//	//std::string retrievedPassword(pws);
			//	cout << x << endl;
				cout << res->getBlob("username") << "\t";
			//cout << res->getString("username") << ":\t";
			//cout << res->getBlob("name") << ":\t";
			cout << res->getInt("score") << endl;
			//}
		}
		delete res;
		delete stmt;
		delete con;
	}
	catch (sql::SQLException &e)
	{
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	cout << endl;
	cin.get();
	return EXIT_SUCCESS;
}