#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/*알고리즘
덱 구현
2주차에 만든 큐를 이용하여 구현하면 될듯
각 노드에 뒤를 가르키는 포인터를 주었기에 
front단과 back단에서 값을 push, pop하는 연산만 추가하면 된다.
*/

typedef struct {
	int val;
	struct Node* flink;
	struct Node* Blink;
}Node;

typedef struct {
	int count;
	struct Node* Front;
	struct Node* Back;
}Deque;


void Push_front(Deque *d, int data){
	
}

void Push_back(Deque *d, int data){
	
}

int Pop_front(Deque *d){
	
}

int Pop_back(Deque *d){
	
}

int size(Deque *d){
	
}

int size(Deque *d){
	
}

int Front(Deque *d){
	
}

int Back(Deque *d){
	
}

void Init_deque(Deque *d){
	
}



int main(){
	
	Deque d;
	Init_deque(&d);
	
	unsigned short int N;
	scanf("%hd", &N);
	
	char cmd[20] = { 0, }; //명령어를 저장할 배열 
	if (scanf("%hd", &N)) {
		getchar();
		for (int i = 0; i<N; i++){
			
		}
	
	
	
	
		   
	



	
	getch();
	return 0;
}
