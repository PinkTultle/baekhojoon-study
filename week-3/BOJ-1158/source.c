#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/*알고리즘
 원형큐를 이용하여 구현
 K크기의 원형큐 를 생성
 1번을 시작으로 N번 이동 후 pop연산
 큐가 빌때까지 위의 과정을 반복 
 pop연산을 통해 나온 수 들은 배열에 저장
 마지막에 출력ㄹ 
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
	//원형 큐에 넣을 Node생성 및 Node의 val에 값 대입 
	Node* temp = (Node *)malloc(sizeof(Node*));
	temp->val = data;	
	
	/*큐가 비어있다면 최초 노드 생성
      front와 rear은 첫 노드를 가르킨다. 
      
      이후부터는 큐의 현재 노드 rear의 다음에 temp의 주소를 주고
	  temp를 큐의 rear로 만든다.
	  
	  또한 항상 rear의 다음에 front가 오도록하여 원형 큐를 유지한다. 
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
	//큐가 비었다면 1, 값이 존재한다면 0 반환  
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
	
	//원형큐 선언 및 초기화 
	C_queue q;
	queue_init(&q);
	
	//N과 K를 입력 받는다. 
	int n, k;
	scanf("%d %d", &n, &k);
	int prt[n+1]; //수열을 저장할 N길이의 배열
	
	//1부터 N까지의 수를 원형큐에 push 
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
