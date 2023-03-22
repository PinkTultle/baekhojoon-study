#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define test

int main(){
	int output[26],a='a';
	char temp[101];
	
	memset(output, -1, sizeof(int)*26);
	gets(temp);	
	
	char *ptr = temp, *find;
	
	while(a < 'z'+1){
		
		find = strchr(ptr, a);
		if(find != NULL){
			output[a-'a'] = find - &temp[0];	
		}
		
		#ifdef test
		
		printf("찾은 포인터 : %d \n시작 포인터 : %d \n뺀결과 : %d\n", find, &temp[0], find - &temp[0]); 
		
		#endif
		a++;
	}
	
	for(int i= 0; i<26; i++){
		printf("%d ", output[i]);
	}
	
	return 0;
}


