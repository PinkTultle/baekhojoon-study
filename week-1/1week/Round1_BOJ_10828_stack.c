#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(lib, "mylibrary.lib")

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int val;
	struct Node* link;
} Node;

typedef struct {
	int count;
	Node* Top;
}stack;

int cmd_check(char* cmd) {

	if (!strcmp(cmd, "pop")) return 2;
	else if (!strcmp(cmd, "empty")) return 3;
	else if (!strcmp(cmd, "size")) return 4;
	else if (!strcmp(cmd, "top")) return 5;
	else /*(!(strcmp(strtok(cmd, " "), "push"))) */{
		return 1;
	}
}

void push(stack* s, char *data) {
	data = strpbrk(data, " ");
	Node* temp = (Node*)malloc(sizeof(Node*));
	temp->val = atoi(data);
	temp->link = s->Top;
	s->Top = temp;
	s->count++;
	//printf("%d\n", temp->val);
}

int pop(stack *s) {
	if (!empty(s)) {
		//Node* node = s->Top;
		int num = s->Top->val;
		s->Top = s->Top->link;
		s->count--;

		//free(node);
		return num;
	}
	else return -1;

}

int empty(stack *s) {
	if (s->count == 0) {
		return 1;
	}
	else return 0;
	
	
	/* 작동이 안되네...ㅠ
	if (s->Top == NULL) return 1;
	else return 0;*/
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


int main() {
	stack s;
	short int N;
	init(&s);
	char cmd[20] = { 0, }; //명령어를 저장할 배열 
	if (scanf("%hd", &N)) {
		//rewind(stdin);
		getchar();
		for (int i = 0; i < N; i++) {

			//명령어 인식 함수 : 공백문자 혹은 띄어쓰기로 명령어 인식
			if (gets(cmd)) {
				//해당 명령 실행 코드 : case문?
				switch (cmd_check(cmd)) {
				case 1:
					push(&s, cmd);
					//push함수
					break;
				case 2:
					printf("%d\n", pop(&s));
					//pop함수
					break;
				case 3:
					printf("%d\n", empty(&s));
					//empty함수
					break;
				case 4:
					printf("%d\n", size(&s));
					//size함수
					break;
				case 5:
					printf("%d\n", top(&s));
					//top함수
					break;
				}
			}
		}
	}
	return 0;
}