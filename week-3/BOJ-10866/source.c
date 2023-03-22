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
	struct Node* before;
	struct Node* next;
}Node;

typedef struct {
	int count;
	Node* Front;
	Node* Back;
}Deque;

int empty(Deque *d){
	if(d->count == 0) return 1;
	else return 0;
}

void Push_back(Deque *d, char *data){
	data = strpbrk(data, " ");
	Node *temp = (Node*)malloc(sizeof(Node*));
	temp->val = atoi(data);
	
	if(empty(d)){
		d->Front = temp;
		d->Back = temp; 
	}
	else{
		temp->next = d->Front;
		d->Front->before = temp;
		d->Front = temp;
	}
	d->count++;	
}

void Push_front(Deque *d, char *data){
	data = strpbrk(data, " ");
	Node *temp = (Node*)malloc(sizeof(Node*));
	temp->val = atoi(data);
	
	if(d->count==0){
		d->Front = d->Back = temp; 
	}
	else{
		d->Back->next = temp;
		temp->before = d->Back;
		d->Back = temp;
	}
	d->count++;
}

int Pop_front(Deque *d){
	if(empty(d)) return -1;
	else{
		Node *temp = d->Front;
		
		int num = temp->val;
		d->Front = temp->next;
		d->count--;
		
		free(temp);
		
		return num;
	}
}

int Pop_back(Deque *d){
	if(empty(d)) return -1;
	else{
		Node *temp = d->Back;
		
		int num = temp->val;
		d->Back = temp->before;
		d->count--;
		
		free(temp);
		
		return num;
	}
}

int size(Deque *d){
	return d->count;
}


int Front(Deque *d){
	if (!empty(d)){
		return d->Front->val;
	}
	else return -1;
}

int Back(Deque *d){
	if (!empty(d)){
		return d->Back->val;
	}
	else return -1;
}

void Init_deque(Deque *d){
	d->count = 0;
	d->Back = NULL;
	d->Front = NULL;
}


/*에러 발견 푸쉬 검사시 문자열이 잘려 cmd에 앞부분만 남게된다.*/
int cmd_check(char* cmd) {	
	if (!strcmp(cmd, "pop_front")) return 3;
	else if (!strcmp(cmd, "pop_back")) return 4;
	else if (!strcmp(cmd, "empty")) return 5;
	else if (!strcmp(cmd, "size")) return 6;
	else if (!strcmp(cmd, "front")) return 7;
	else if (!strcmp(cmd, "back")) return 8;
	else if (!(strstr(cmd, "push_front"))) return 1;
	else //if (!(strcmp(strtok(cmd, " "), "push_fback"))) 
 		return 2;
	
}


int main(){
	
	Deque d;
	Init_deque(&d);
	
	unsigned short int N;
	scanf("%hd", &N);
	getchar();
	char *cmd = (char *)malloc(32); //명령어를 저장할 배열 
	while(N > 0) {
		if (gets(cmd)) {
			//해당 명령 실행 코드 : case문?
			switch (cmd_check(cmd)) {
			case 1:
				Push_front(&d, cmd);
				//Push_front함수
				break;
			case 2:
				Push_back(&d, cmd);
				//Push_back 함수 
				break;	
			case 3:
				printf("%d\n", Pop_front(&d));
				//Pop_front 함수 
				break;
			case 4:
				printf("%d\n", Pop_back(&d));
				//Pop_back함수					 
				 break;		
			case 5:
				printf("%d\n", empty(&d));
				//empty함수
				break;
			case 6:
				printf("%d\n", size(&d));
				//size함수
				break;
			case 7:
				printf("%d\n", Front(&d));
				//front함수
				break;
			case 8:
				printf("%d\n", Back(&d));
				//back함수	
			}
			N--;
			
			Node *temp = d.Front;
			printf("\n<");
			for(int i = 0; i< d.count; i++){
				if(temp != NULL){
					printf("%d", temp->val);
					temp = temp->next;
				}
			} 
			printf(">\n");
 		}
	}
	
	getch();
	return 0;
}
