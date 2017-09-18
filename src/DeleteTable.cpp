#include "header.h"

void deletetable(string table){
	if(M.find(table)==M.end()){
		cout << "Table does not exist\n";
		return;
	}
	int in=M[table];

	clearall(in);
	available[in]=0;

	return;
}


