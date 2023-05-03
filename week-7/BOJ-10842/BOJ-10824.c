#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	char A[4][18];
	long long num1,num2;
	
	for(int i=0; i < 4; i++){
		scanf("%s", A[i]);
	}
		
	strcat(A[0], A[1]);
	strcat(A[2], A[3]);
	
	num1 = atoll(A[0]);
	num2 = atoll(A[2]);
	
	printf("%lld\n", num1+num2);
	
	return 0;
}
