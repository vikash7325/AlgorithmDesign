/*LCS  Goldman Sachs Bangalore Vikash Kumar*/
#include<iostream>
using namespace std;
void PRINT_LCS(int b[7][6], char *X, int i, int j){
	if (i < 0 || j < 0){
		return;
	}

	if (b[i][j] == -1){
		PRINT_LCS(b, X, i-1, j-1);
		cout<<X[i]<<"\t";
	}else if(b[i][j] == -2){
		PRINT_LCS(b, X, i-1, j);
	}else{
		PRINT_LCS(b, X, i, j-1);
	}
}

void LCS(char *X, char *Y, int m, int n, int c[8][7], int b[7][6]){
	int  i, j;
	
	for (i = 1; i <= m; i++){
		c[i][0] = 0;
	}
	
	for(j=0; j <= n; j++){
		c[0][j] = 0;
	}
	
	for (i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			if (X[i - 1 ] == Y[j - 1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i - 1][j - 1] = -1;
			}else if(c[i - 1][j] >= c[i][j - 1]){
				c[i][j] = c[i-1][j];
				b[i - 1][j - 1] = -2;
			}else{
				c[i][j] = c[i][j-1];
				b[i - 1][j - 1] = -3;
			}
		}
	}
	cout<<"Length "<<c[7][6]<<"\n";
}
int main(){
	char X[8] = "ABCBDAB";
	char Y[7] = "BDCABA";
	int c[8][7] = {0};
	int b[7][6] = {0};
	
	LCS(X, Y, 7, 6, c, b);
	cout<<"Maximum Length "<<c[7][6]<<"\n";
	PRINT_LCS(b, X, 6, 5);
	return 0;
}
