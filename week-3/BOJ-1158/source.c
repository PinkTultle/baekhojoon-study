#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/*�˰���
 ����ť�� �̿��Ͽ� ����
 Kũ���� ����ť �� ����
 1���� �������� N�� �̵� �� pop����
 ť�� �������� ���� ������ �ݺ� 
 pop������ ���� ���� �� ���� �迭�� ����
 �������� ��¤� 
*/

typedef struct{
	int val;
	struct node* next;
}Node;

typedef struct{
	int count;
	Node* front;
	Node* rear;
}C_queue;

void push(C_queue *q, int data){
	//���� ť�� ���� Node���� �� Node�� val�� �� ���� 
	Node* temp = (Node *)malloc(sizeof(Node*));
	temp->val = data;	
	
	/*ť�� ����ִٸ� ���� ��� ����
      front�� rear�� ù ��带 ����Ų��. 
      
      ���ĺ��ʹ� ť�� ���� ��� rear�� ������ temp�� �ּҸ� �ְ�
	  temp�� ť�� rear�� �����.
	  
	  ���� �׻� rear�� ������ front�� �������Ͽ� ���� ť�� �����Ѵ�. 
	*/
	if(empty(q)){
		q->rear = temp;
		q->front = temp;
	} 
	else {
		q->rear->next = temp;
		q->rear = temp;
		
		q->rear->next = q->front;
	}
	
	q->count++;
}


int pop(C_queue *q){
	if(empty(q)){
		return -1;
	}
	
	int num;
	Node* temp = q->front;
	
	num = temp->val;
	
	q->front = temp->next;
	q->rear->next = q->front;
	
	free(temp);
	
	return num;	
}

int empty(C_queue *q){
	//ť�� ����ٸ� 1, ���� �����Ѵٸ� 0 ��ȯ  
	if(q->count == 0) return 1;
	else return 0;
}


void queue_init(C_queue *q){
	q->count = 0;
	q->front = NULL;
	q->rear = NULL;
}

void rotation_queue(C_queue *q){
	q->front = q->front->next;
	q->rear = q->rear->next;	
}


int main(){
	
	//����ť ���� �� �ʱ�ȭ 
	C_queue q;
	queue_init(&q);
	
	//N�� K�� �Է� �޴´�. 
	int n, k;
	scanf("%d %d", &n, &k);
	int prt[n+1]; //������ ������ N������ �迭
	
	//1���� N������ ���� ����ť�� push 
	for(int i = 1; i<=n; i++){
		push(&q, i);
	}
	
	
	while(!empty(&q)){
		
		for(int i = 0; i<k-1; i++){
			rotation_queue(&q);
		}
		
		
		prt[n-q.count] = pop(&q);
		
		q.count--;
	}
	
	
	printf("<");
	for(int i=0; i<n-1; i++){
		printf("%d, ", prt[i]);
	}
	printf("%d", prt[n-1]);
	printf(">");
		
	getch();
	return 0;
}
