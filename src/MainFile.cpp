#include "header.h"


int main(){
	initialize();
	string s,s1;
	getline(cin,s);
	while(s!="exit"){
		int a=0;
		string temp=func(s,a);

		if(temp=="create"){
			cout << "\nEnter Table Name:";
			getline(cin,s1);
			create(s,s1);
		}
		else if(temp=="insert"){
			insert(s);
		}
		else{
			table ans=Parse(s,ans);
			PrintTable(ans);
		}
		getline(cin,s);
	}


}
/*
 * int main() {


    create("create table roll int name string","table1");

    create("create table freq1 int freq2 int freq3 int","frequency");
    insert("insert into frequency 1 2 3");
    insert("insert into frequency 2 3 4");
    insert("insert into frequency 3 4 5");
    insert("insert into frequency 4 5 6");


    insert("insert into table1 1 robin");
    insert("insert into table1 2 vivek");

    insert("insert into table1 3 janvijay");
    insert("insert into table1 4 rithvik");
    insert("insert into table1 3 vivek");
    insert("insert into table1 3 vivek");
    insert("insert into table1 3 vivek");

    table A,B,C,D;
   // A=project("project from table1 roll name",A);
    cout << "*****************\n";
    create("create table roll int name string rank int section string","table2");
    insert("insert into table2 1 robin 2 btech");
    insert("insert into table2 2 virat 3 btech");
    insert("insert into table2 3 vivek 4 btech");
    insert("insert into table2 4 rithvik 5 btech");

  // B= project("project from table2 rank section roll name",B);

    cout << endl << endl << endl;

    D=Parse("select from table2 roll name where roll>\"2\" & section>\"3\"",D);
    //renames("table2","stud_database");

    //project("project from stud_database rank section roll name",C);


   // vector < vector <string> > abcd;
    //int in=M["stud_database"];
    //TableToVector(arr[in],abcd);

    //PrintVector(abcd,abcd.size());
    //cout << endl << endl << endl;
    /*PrintTable(D);

    table E,F,G,H;
    Union(A,D,E);
    F=SetDifference(A,D,F);

    PrintTable(A);
    G=Rename(A,"heybitch",G);
    PrintTable(G);
    H=CartesianProduct(A,G,H);

    table N,N1,N2,N3,N4,N5;
    Parse("select from ( select from frequency freq1 freq2 where freq1>\"2\" ) freq1 where freq1>\"0\"",N);

    PrintTable(N);
    Parse("project from ( select from frequency freq1 freq2 where freq1>\"2\" ) freq2",N1);
    PrintTable(N1);
    Parse("select from ( product ( union ( project from table1 roll name ) , ( project from table2 roll name ) ) , ( project from frequency freq1 ) ) A.roll where A.name=\"robin\" ",N2);

    PrintTable(N2);
	return 0;
}
 *
 */
