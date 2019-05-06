//============================================================================
// Name        : Parser.cpp
// Author      : Rodger Byrd
// Version     :
// Copyright   : Your copyright notice
// Description : Text to SQLite converter in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sqlite3.h>
#include <stdio.h>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for(i=0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main(int argc, char **argv) {
	const char *dbname = "aol_database";
	const char *createTable = "CREATE TABLE searches (query_id INTEGER PRIMARY KEY, AnonID TEXT, Query TEXT, QueryTime TEXT, ItemRank INTEGER, ClickURL TEXT);";

	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

//	if( argc!=3 ){
//		fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
//			return(1);
//	}
	//open database
	rc = sqlite3_open(dbname, &db);
	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return(1);
	} else{
		fprintf(stderr, "Opening database\n");
	}
	//execute database command
	
	//rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
	//rc = sqlite3_exec(db, "CREATE TABLE searches (query_id INTEGER PRIMARY KEY, AnonID TEXT, Query TEXT, QueryTime TEXT, ItemRank INTEGER, ClickURL TEXT);", callback, 0, &zErrMsg);
	//rc = sqlite3_exec(db, "insert into searches values(NULL,'142','rentdirect.com','','','');", callback, 0, &zErrMsg);

	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	//close database
	sqlite3_close(db);

	return 0;
}
