#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/*�˰���
�� ����
2������ ���� ť�� �̿��Ͽ� �����ϸ� �ɵ�
�� ��忡 �ڸ� ����Ű�� �����͸� �־��⿡ 
front�ܰ� back�ܿ��� ���� push, pop�ϴ� ���길 �߰��ϸ� �ȴ�.
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


/*���� �߰� Ǫ�� �˻�� ���ڿ��� �߷� cmd�� �պκи� ���Եȴ�.*/
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
	char *cmd = (char *)malloc(32); //��ɾ ������ �迭 
	while(N > 0) {
		if (gets(cmd)) {
			//�ش� ��� ���� �ڵ� : case��?
			switch (cmd_check(cmd)) {
			case 1:
				Push_front(&d, cmd);
				//Push_front�Լ�
				break;
			case 2:
				Push_back(&d, cmd);
				//Push_back �Լ� 
				break;	
			case 3:
				printf("%d\n", Pop_front(&d));
				//Pop_front �Լ� 
				break;
			case 4:
				printf("%d\n", Pop_back(&d));
				//Pop_back�Լ�					 
				 break;		
			case 5:
				printf("%d\n", empty(&d));
				//empty�Լ�
				break;
			case 6:
				printf("%d\n", size(&d));
				//size�Լ�
				break;
			case 7:
				printf("%d\n", Front(&d));
				//front�Լ�
				break;
			case 8:
				printf("%d\n", Back(&d));
				//back�Լ�	
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
