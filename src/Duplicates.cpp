#include "header.h"

int RemoveDuplicates(vector < vector <string> > &s1,int len,int size){
	int dupli[size];
	memset(dupli,0,sizeof(dupli));

	for(int i=0;i<size;i++){
		if(dupli[i]==0){
			for(int j=i+1;j<size;j++){
				if(DupliUtil(s1,s1,i,j,len)){
					dupli[j]=1;
				}
			}
		}
	}

	string s2[size][len]; int cnt=0;

	for(int i=0;i<size;i++){
		if(dupli[i]==0){
			for(int j=0;j<len;j++){
				s2[cnt][j]=s1[i][j];
			}
			cnt++;
		}
	}

	// Copy s2 to s1
	for(int i=0;i<cnt;i++){
		for(int j=0;j<len;j++){
			s1[i][j]=s2[i][j];
		}
	}
	return cnt;
}


bool DupliUtil(vector < vector <string> > &s1,vector < vector <string> > &s2,int i,int j,int len){
	int flag=1;
	for(int k=0;k<len;k++){
		if(s1[i][k]!=s2[j][k])flag=0;
	}
	return (flag==1);
}



