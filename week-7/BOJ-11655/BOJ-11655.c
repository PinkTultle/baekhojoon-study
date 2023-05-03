/*
알고리즘 구상 
1. 문자열을 입력 받는다.
2. 입력받은 문자열을 하나씩 따라가며 아스키 코드 13씩 더한다.
3. 더한 아스키 값에 대해 z혹은 Z만큼 나머지 연산을 한다.
4. 단, 아스키 값이 알파벳 범위안에 있을경우 실행 한다.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	unsigned char temp[100], *S;
	int i = 0;
	
	gets(temp);
	
	
	while(temp[i] != NULL){
		if(!(temp[i] >= 'A'  && temp[i] <= 'Z' ) && !(temp[i] >= 'a' && temp[i] <= 'z')){ //알파벳이 아닌경우 
			;
		}
		else if(temp[i] >= 'a'){
			temp[i] = temp[i]+13;
			if(temp[i] > 'z') temp[i] = temp[i] - 26;
		}else {
			temp[i] = temp[i]+13;
			if(temp[i] > 'Z') temp[i] = temp[i] - 26;
		}
		
		i++;
	}	
	
	printf("%s", temp); 
	return 0;
} 
