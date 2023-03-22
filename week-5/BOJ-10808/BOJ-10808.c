/*알파벳 개수 알고리즘 구상*/


/*
알파벳은 소문자로만 이루어진다 각 알파벳이 단어 에 몇개가 포함됐는지 구하여 출력하는 프로그램
흐름
1. 알파벳의 종류는 26가지 26크기의 배열을 만든다.
2. 입력을 하나씩 받아 char형에 저장 
3. 받은 문자에 a를 뺸다 -> 아스키코드이용
4. 결과 정수의 인덱스인 배열의 순서에 +1
5. 마지막으로 배열을 순차출력 
 

*/

#include<stdio.h>

int main(){
	int anser[26] = {0,},num;
	char input;
	
	while(scanf("%c", &input)){
		if(input == '\n') break;
		num = input - 'a';
		anser[num]++;
		
	}
	
	for(int i =0; i<26 ; i++){
		printf("%d ", anser[i]);
	}
	return 0;
}
