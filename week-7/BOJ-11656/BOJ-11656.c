/*
알고리즘 구상
1. 문자열을 입력받는다.
2. 입력 받은 문자열부터 +1씩증가하는 포인터를 만든다.
3. 포인터가 하나씩 증가할때마다 배열에 저장
4. 포인터 증가는 널문자를 만날때까지 진행
5. 이후 문자열 배치 시작
6. 먼저 첫번째 문자열와 두번째문자열 0번인덱스 비교 교환
7.  같다면 1번 인덱스 비교 


*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

void Sort(char *str){
	
	printf("%s\n", str);
	

}

int main(){
	
	char *temp, *str;
	int i;
	
	temp = (char*)malloc(sizeof(char) * MAX);
	
	gets(temp);
	
	char *suffix[strlen(temp)];
	/*
	printf("%d\n", strlen(temp));
	
	printf("%d\n", sizeof(suffix));
	*/
	for(i = 0; i < strlen(temp); i++){
			
		str = temp+i; 
		printf("%d : %s\n", i, str);
		suffix[i] = (char*)malloc(sizeof(char) * strlen(str) + 1);
		suffix[i] = str;
		printf("%d \n", &suffix[i]);
	}
	
	for(i = 0; i < strlen(temp); i++){
		printf("%s\n", suffix[i]);
	}
	
	//Sort(suffix[0]);
	

//	free(suffix);
//	free(temp);
	
	return 0;
	
}
