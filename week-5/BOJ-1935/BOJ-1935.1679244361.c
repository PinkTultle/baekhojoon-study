/*
후위 표기식2 알고리즘 구상 

후위 표기식과 각 피연산자에 대응하는 값들이 주어져 있을 때, 그 식을 계산하는 프로그램을 작성하시오.

1. 스택을 이용하여 후위표기식을 계산한다.
2. 피연산자 개수만큼 배열 생성 (가변 배열)  
3. 계산식 문자열로 입력받음 
4. 입력 받은 문자열을 순서대로 따라가는데 문자의 경우 'A'를 뺀 배열인덱스 참조하여  PUSH
5. 연산자의 경우 POP연산 2회실행하여 변수에 각각 입력 후 연산 함수로 처리
6. 문자열이 끝날때까지 반복   
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//스택을 구성하는 노드와 스택 구조체 
typedef struct{
	float val; 
	struct Node *defore;
}Node;  

typedef struct{
	int count;
	Node *top;
}Stack;

//스택 초기화 함수 
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
	//스택 선언과 초기화 및 변수 선언 
	Stack s;
	int N, flen;
	char *formula = (char*)malloc(sizeof(char)*100);
	float val;
	
	
	init_Stack(&s);
	
	//피연산자 개수만큼 가변 배열 생성 
	scanf("%d", &N);
	int operand[N];
	getchar();
	
	//계산식 문자열로 입력 받음 
	gets(formula);
		
	
	//각 피연산자의 값을 입력받아 배열에 삽입 
	for(int a = 0; a < N; a++){
		scanf("%d", &operand[a]);
	}
	
	//계산식 연산 시작 
	N = 0;
	flen = strlen(formula);
	while(N < flen){
		if(*(formula+N) >= 'A'){
			//피연산자 처리 
			//푸쉬 
			//printf("%d\n",operand[*(formula+N)-'A']);
			Push(&s, operand[*(formula+N)-'A']);
		}
		else {
			//연산자 처리 
			//printf("%c\n", *(formula+N));
			Operator(&s, *(formula+N));
			//팝 2회 연산 후 푸쉬 
		}
	 	N++;
	}
	
	printf("%.2f", Pop(&s));
	
	return 0;
} 
