/*
���� ǥ���2 �˰��� ���� 

���� ǥ��İ� �� �ǿ����ڿ� �����ϴ� ������ �־��� ���� ��, �� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

1. ������ �̿��Ͽ� ����ǥ����� ����Ѵ�.
2. �ǿ����� ������ŭ �迭 ���� (���� �迭)  
3. ���� ���ڿ��� �Է¹��� 
4. �Է� ���� ���ڿ��� ������� ���󰡴µ� ������ ��� 'A'�� �� �迭�ε��� �����Ͽ�  PUSH
5. �������� ��� POP���� 2ȸ�����Ͽ� ������ ���� �Է� �� ���� �Լ��� ó��
6. ���ڿ��� ���������� �ݺ�   
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//������ �����ϴ� ���� ���� ����ü 
typedef struct{
	float val; 
	struct Node *defore;
}Node;  

typedef struct{
	int count;
	Node *top;
}Stack;

//���� �ʱ�ȭ �Լ� 
void init_Stack(Stack *s){
	s->count = 0;
	s->top = NULL;
}

void Push(Stack *s, float data){
	Node *temp = (Node*)malloc(sizeof(Node*));
	temp->val = data;
	if(s->count==0){
		temp->defore = NULL;
	}
	else{
		temp->defore = s->top;
	}
	s->top = temp;
	s->count++;
}

float Pop(Stack *s){
	Node *temp_node = s->top;
			
	float data = s->top->val;
	
	if( s->count > 0){
		s->top = temp_node->defore;		
	}
	else {
		return -1;
	}
	s->count--;
		
	//free(temp_node);
	return data;
}

float calculate(float op1, float op2, char op){
	switch(op){
		case '+':
			return op1 + op2;
			break;
		case '-' :
			return op1 - op2;
			break;
		case '*':
			return op1 * op2;
			break;
		case '/':
			return op1 / op2;
			break;				
	}	
}

void Operator(Stack *s,char op){
	float f1, f2;
	
	f2 = Pop(s);
	f1 = Pop(s);
	
	
	float (*cal)(float f1, float f2, char op);
	cal = calculate;
	
	Push(s, cal(f1,f2,op));
	
	
}

int main(){
	//���� ����� �ʱ�ȭ �� ���� ���� 
	Stack s;
	int N, flen;
	char *formula = (char*)malloc(sizeof(char)*100);
	float val;
	
	
	init_Stack(&s);
	
	//�ǿ����� ������ŭ ���� �迭 ���� 
	scanf("%d", &N);
	int operand[N];
	getchar();
	
	//���� ���ڿ��� �Է� ���� 
	gets(formula);
		
	
	//�� �ǿ������� ���� �Է¹޾� �迭�� ���� 
	for(int a = 0; a < N; a++){
		scanf("%d", &operand[a]);
	}
	
	//���� ���� ���� 
	N = 0;
	flen = strlen(formula);
	while(N < flen){
		if(*(formula+N) >= 'A'){
			//�ǿ����� ó�� 
			//Ǫ�� 
			//printf("%d\n",operand[*(formula+N)-'A']);
			Push(&s, operand[*(formula+N)-'A']);
		}
		else {
			//������ ó�� 
			//printf("%c\n", *(formula+N));
			Operator(&s, *(formula+N));
			//�� 2ȸ ���� �� Ǫ�� 
		}
	 	N++;
	}
	
	printf("%.2f", Pop(&s));
	
	return 0;
} 
