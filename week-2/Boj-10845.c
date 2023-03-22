#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct {
	int val;
	struct Node* flink;
	struct Node* Blink;
}Node;

typedef struct {
	int count;
	Node* Front;
	Node* Back;
}queue;

int cmd_check(char* cmd) {

	if (!strcmp(cmd, "pop")) return 2;
	else if (!strcmp(cmd, "empty")) return 3;
	else if (!strcmp(cmd, "size")) return 4;
	else if (!strcmp(cmd, "front")) return 5;
	else if (!strcmp(cmd, "back")) return 6;
	else /*(!(strcmp(strtok(cmd, " "), "push"))) */{
		return 1;
	}
}

void push(queue* s, char *data) {
	data = strpbrk(data, " ");
	
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp->val = atoi(data);
	if(s->count==0){
		s->	Front = temp;
		s-> Back = temp; 
	}
	else{
		temp->flink = s->Back;
		s->Back->Blink = temp;
		temp->Blink = NULL;
		s->Back = temp;
	}
	s->count++;

}

int pop(queue *s) {
	if (!empty(s)) {
		Node* node = s->Front;
		int num = node->val;
		s->Front = node->Blink;
		s->count--;

		free(node);
		return num;
	}
	else return -1;

}

int empty(queue *s) {
	if (s->count == 0) {
		return 1;
	}
	else return 0;
}

int size(queue *s) {
	return s->count;
}

int front(queue *s) {
	if (!empty(s)) {
		return s->Front->val;
	}
	else return -1;
}

int back(queue *s){
	if (!empty(s)){
		return s->Back->val;
	}
	else return -1;
}


void init(queue *s) {
	s->count = 0;
	s->Front = NULL;
	s->Back = NULL;
}


int main() {
	queue s;
	unsigned short int N;
	init(&s);
	char cmd[20] = { 0, }; //��ɾ ������ �迭 
	if (scanf("%hd", &N)) {
		//rewind(stdin);
		getchar();
		for (int i = 0; i < N; i++) {
			//��ɾ� �ν� �Լ� : ���鹮�� Ȥ�� ����� ��ɾ� �ν�
			if (gets(cmd)) {
				//�ش� ��� ���� �ڵ� : case��?
				switch (cmd_check(cmd)) {
				case 1:
					push(&s, cmd);
					//push�Լ�
					break;
				case 2:
					printf("%d\n", pop(&s));
					//pop�Լ�
					break;
				case 3:
					printf("%d\n", empty(&s));
					//empty�Լ�
					break;
				case 4:
					printf("%d\n", size(&s));
					//size�Լ�
					break;
				case 5:
					printf("%d\n", front(&s));
					//front�Լ�
					break;
				case 6:
					printf("%d\n", back(&s));
					//back�Լ�	
				}
			}
		}
	}
	getch();
	return 0;
}
