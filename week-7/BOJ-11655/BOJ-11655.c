/*
�˰��� ���� 
1. ���ڿ��� �Է� �޴´�.
2. �Է¹��� ���ڿ��� �ϳ��� ���󰡸� �ƽ�Ű �ڵ� 13�� ���Ѵ�.
3. ���� �ƽ�Ű ���� ���� zȤ�� Z��ŭ ������ ������ �Ѵ�.
4. ��, �ƽ�Ű ���� ���ĺ� �����ȿ� ������� ���� �Ѵ�.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	
	unsigned char temp[100], *S;
	int i = 0;
	
	gets(temp);
	
	
	while(temp[i] != NULL){
		if(!(temp[i] >= 'A'  && temp[i] <= 'Z' ) && !(temp[i] >= 'a' && temp[i] <= 'z')){ //���ĺ��� �ƴѰ�� 
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
