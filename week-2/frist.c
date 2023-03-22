#include<stdio.h>
#include<stdbool.h>
//ù �Է����� �迭 ���� �� �� �־��ֱ� 
//1���� n���� �������� ���ڵ� + ���� + ��µ� ������ ����
//���ÿ��� ������ top���� ���� ���ڸ� �ִ� -> ��� �� ���� ������ top���� �� 
//-> ū�� : ���� ���ÿ� ���� ���� ������ Ȯ�� 
//-> ������ : top���� ��¼��� �ٸ��� NO  
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
	//1���� n���� ������ ���� ���� 
	unsigned int len, num, count=0;
	bool flag = true;
	
	scanf("%d", &len);
	getchar();
	
	int seq[len];
	char anw[len*2];  
	
	while(flag){
		//������ ��ġ�� �� �Է� 
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
	//������� ���� �迭 ����
	return 0;
	
}
