/*
�˰��� ����
1. ���ڿ� �迭�� �ҹ��� �빮�� ����� ������ ������ ������ 4���� ���Ҹ� ���� �迭�� �����.
2. ���پ� �Է¹޴´�
3. �Էµ� ���� ó������ \n���� �˻��Ѵ�. �̶� �� ������ ������ �˻��Ͽ� ����迭�� +1�Ѵ�.
4. �� ������ gets�� �ƹ��͵� �Է� ���� ���������� �ݺ��Ѵ�. 
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
