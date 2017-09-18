/*
 * header.h
 *
 *  Created on: Oct 15, 2016
 *      Author: Mr Bean
 */

#ifndef HEADER_H_
#define HEADER_H_



#include <bits/stdc++.h>
#define MAXSIZE 10
#define ERROR -1
using namespace std;


struct table{
    vector < vector <string> >  V1;
    vector < vector <int> > V2;

    map <string , pair<int,int> > attr;   // Attribute type and index in that type

    map <string,int> actualattr; // Actual indices of attributes

    vector <string> names;        // Names of attributes

    int tuples;					// No of tuples
};

extern map <string,int> M;

extern table arr[MAXSIZE];

extern int available[MAXSIZE];

extern map <string,int> Keywords;


string ClosingParanthesis(string s,int &a);
table Parse(string s,table &ans);


table UnionMain(string s,table &X);
table Union(table &AA,table &BB,table &X);
bool UnionError(table &A,table &B);
void RemoveDuplicatesTable(table &A,int trace[]);
bool CheckSame(table &A,int in1,table &B,int in2);

table SetDifference(table &AA,table &BB,table &X);
table MinusMain(string s,table &X);

table CartesianProduct(table &A,table &B,table &X);
table ProductMain(string s,table &X);

void AddRowTable(table &A,int in1,table &B,int in2);

void clearall(int in);

void initialize();

string func(string s,int &a);
bool error_create(string s,int &a);

int CheckAvailability();
void create(string s,string tablename);
int if_integer(string s);


bool error_insert(string s,int &a);
void insert(string s);
bool checkerror(string s,int y,table A);
bool error_project(string s, int &a);
string IntToString(int a);
table project(string s,table &X);
bool error_select(string s,int &a);
table select(string s,table &X);

bool isContained(string st, string arr[], int size);

bool isHigher(char a, char b);
string convert_to_postfix(string stmt);
int isContained_2(string st, string arr[], int size);
void string_to_chararr(string st, char* str);
bool isNumeric(char* st);
int select_str_op(string postfix, string field_name[], string field_type[], string record[], int size);

table Rename(table &A,string s2,table &X);


void PrintRow(string table,int row_index);

bool DupliUtil(vector < vector <string> > &s1,vector < vector <string> > &s2,int i,int j,int len);

int RemoveDuplicates(vector < vector <string> > &s1,int len,int size);

void PrintVector(vector <vector <string> > &s1,int size);

void PrintVector(vector <vector <string> > &s1,int trace[],int size);


void deletetable(string table);

void Printing(table &A,map<string,int> &selected,table &X,vector <string>&Y);


void TableToVector(table &X,vector < vector <string> > &V);
void AddRow(table &X,vector < vector <string> > &V,int index);
void AddNames(table &X,vector < vector <string> > &V);
void AddEmpty(vector < vector <string> > &V);

void PrintTable(table &X);
void CreateRowTable(table &X,int in1,table &Y,int in2);
void CreateMapping(table &X,vector <string> &Y,map <string , pair<int,int> > &Z);
void CreateTableNames(table &X,vector <string> &Y);
void CartesianProductUtil(table &A,int row_index,table &B,table &X);

#endif /* HEADER_H_ */
