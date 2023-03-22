/*
알고리즘 구상
1. 문자열 배열과 소문자 대문자 공백과 숫자의 갯수를 저장할 4개의 원소를 가진 배열을 만든다.
2. 한줄씩 입력받는다
3. 입력된 줄의 처음부터 \n까지 검사한다. 이때 각 문자의 형식을 검사하여 결과배열에 +1한다.
4. 위 순서를 gets가 아무것도 입력 받지 않을때까지 반복한다. 
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
	char str[100] = {0,};
	int output[4]={0,}, i=0;
	
	while(gets(str)){		
		for(i=0; i < strlen(str); i++){
			if(str[i] >= 97 && str[i] <= 122){
				output[0]++;
				//printf("%d %d %d %d\n", output[0], output[1], output[2], output[3]);
			}
			else if(str[i] >= 65 && str[i] <= 90){
				output[1]++;
				//printf("%d %d %d %d\n", output[0], output[1], output[2], output[3]);
			}
			else if(str[i] >= 48 && str[i] <= 57){
				output[2]++;
				//printf("%d %d %d %d\n", output[0], output[1], output[2], output[3]);
			}
			else{
				output[3]++;
				//printf("%d %d %d %d\n", output[0], output[1], output[2], output[3]);
			}
		}
		printf("%d %d %d %d\n", output[0], output[1], output[2], output[3]);
		memset(output, 0, sizeof(int)*4);
	}
	
	
}
