#include<stdio.h>
#include<stdbool.h>
//첫 입력으로 배열 생성 및 값 넣어주기 
//1부터 n까지 오름차순 숫자들 + 스택 + 출력된 수열로 구성
//스택에는 스택의 top보다 작은 숫자만 있다 -> 출력 할 수와 스택의 top값과 비교 
//-> 큰수 : 아직 스택에 넣지 않은 숫자중 확인 
//-> 작은수 : top값이 출력수와 다르면 NO  
typedef struct {
	int val;
	struct Node* link;
} Node;

typedef struct {
	int count;
	Node* Top;
}stack;

void push(stack* s,int num) {
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp->val = num;
	temp->link = s->Top;
	s->Top = temp;
	s->count++;
}

int pop(stack *s) {
	if (!empty(s)) {
		Node* node = s->Top;
		int num = node->val;
		s->Top = node->link;
		s->count--;

		free(node);
		return num;
	}
	else return -1;

}

int empty(stack *s) {
	if (s->count == 0) {
		return 1;
	}
	else return 0;
}

int size(stack *s) {
	return s->count;
}

int top(stack *s) {
	if (!empty(s)) {
		return s->Top->val;
	}
	else return -1;
}


void init(stack *s) {
	s->count = 0;
	s->Top = NULL;
}

int main(){
	
	stack s;
	init(&s);
	//1부터 n개의 숫자의 열을 생성 
	unsigned int len, num, count=0;
	bool flag = true;
	
	scanf("%d", &len);
	getchar();
	
	int seq[len];
	char anw[len*2];  
	
	while(flag){
		//수열에 배치할 수 입력 
		scanf("%d", &num);
		
		if( count != 0 && num < (int)(s->Top->val) ){
			flag = false;
			break;
		}
		else if(num == s->Top->val){
			if(pop(&s)<0) flag = false;
			else anw[count] = '-';
			count ++;
		}else {
			while(s->Top->val <= num){
				push(&s, s->Top->val+1);
				anw[count] = '+';
			}
		}
		
		if( flag == true ){
			for(int s = 0 ; s < sizeof(anw)-1; s++){
				printf("%c\n",anw[s]);
			}
		}
		else printf("NO\n");
		
	
		
	}
	//여기까지 숫자 배열 생성
	return 0;
	
}
