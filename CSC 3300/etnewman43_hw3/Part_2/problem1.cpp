#include <stdlib.h>
#include <iostream>
#include <mysql.h>
#include <stdio.h>
#include <iomanip>
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "coursework"

using namespace std;

int main()
{
    MYSQL *connect;
    connect = mysql_init(NULL);

    if (!connect)
    {
        cout << "MySQL Initialization Failed.\n";
        return 0;
    }

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, NULL, 0, NULL, 0);

    if (connect)
    {
        cout << "Connection Successful.\n";
    }
    else
    {
        cout << "Connection Failed.\n";
        exit(1);
    }
    //cout << "Passed First Connection\n";

    //mysql_query(connect, "DROP DATABASE IF EXISTS TTU");
    mysql_query(connect, "CREATE DATABASE TTU");

    mysql_close(connect);

        //*****Database Created*****  

    MYSQL *connect1;
    connect1 = mysql_init(NULL);

    connect1 = mysql_real_connect(connect1, SERVER, USER, PASSWORD, "TTU", 0, NULL, 0);

    if (connect1)
    {
        cout << "Connection Successful.\n";
    }
    else
    {
        cout << "Connection Failed.\n";
        exit(1);
    }

    mysql_query(connect1, "CREATE TABLE student (tnumber CHAR(8) NOT NULL UNIQUE, firstname VARCHAR(20) NOT NULL, lastname VARCHAR(20) NOT NULL, dateofbirth DATE NOT NULL, credits NUMERIC(3,0), PRIMARY KEY (tnumber)) engine=innodb;");
    mysql_query(connect1, "INSERT INTO student(tnumber, firstname, lastname, dateofbirth, credits) VALUES('00001234', 'Joe', 'Smith', '1950-08-12', 35);");
    
        //*****TABLE CREATED + VALUES*****

    MYSQL_RES *res_set;
    MYSQL_ROW row;

    mysql_query(connect1, "SELECT * FROM student;");

    unsigned int i = 0;
    res_set = mysql_store_result(connect1);
    unsigned int numrows = mysql_num_rows(res_set);

        //*****PRINTING ROWS FROM RESULT SET*****

    while ((row = mysql_fetch_row(res_set)) != NULL )
    {
     cout << "Tnumber" << setw(27) << "FirstName" << setw(17) << "LastName" << setw(18) << "DateOfBirth" << setw(25) << "Credits\n"; 
     cout << row[0] << setw(20);
     cout << row[1] << setw(20);
     cout << row[2] << setw(20);
     cout << row[3] << setw(20);
     cout << row[4] << endl;
    }
    
    mysql_close (connect1);
    return 0;
}