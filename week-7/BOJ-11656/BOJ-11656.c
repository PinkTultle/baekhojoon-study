/*
�˰��� ����
1. ���ڿ��� �Է¹޴´�.
2. �Է� ���� ���ڿ����� +1�������ϴ� �����͸� �����.
3. �����Ͱ� �ϳ��� �����Ҷ����� �迭�� ����
4. ������ ������ �ι��ڸ� ���������� ����
5. ���� ���ڿ� ��ġ ����
6. ���� ù��° ���ڿ��� �ι�°���ڿ� 0���ε��� �� ��ȯ
7.  ���ٸ� 1�� �ε��� �� 


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
