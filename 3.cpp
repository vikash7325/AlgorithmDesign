/*Author Vikash Kumar Goldman Sachs*/
#include<iostream>
using namespace std;
char getMaxLen(string inp){
	int len;
	int max = 1;
	char val;
	char temp;
	char Output = '\0';
	int count = 1;
	
	len = inp.length();
	temp = inp[0];
	val = temp;
	
	for (int index=1; index < len; index++){
		if (temp == inp[index]){
			count++;
			temp = inp[index];
			val = temp;
		}
		else{
			count=1;
			temp = inp[index];
		}
		
		if (max < count){
			max = count;
			Output = inp[index];
		}
	}
	
	return Output; 
}
int main(){
	string inp = "geeekk";
	char out;
	out = getMaxLen(inp);
	cout<<"Result is "<<out<<"\n";
	return 0;
}
