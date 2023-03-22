#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


/*����� ��
1. (�� ������� -> 
2. )�� ���� ����
3. ()�� ������ �߻� 

������ ���ϴ°� ���� ���ڿ� �ͼ� ���� 
NULL���� ���������� �ݺ��Ͽ� ���ڸ� �о� ���δ�. 
NULL���� �ƴҰ�� ���� ���ڿ� ���� ���� ���Ͽ� ���� ����
NULL���� ��� ���� ������ 1�� ���ϰ� ���α׷� ���� 
*/

typedef struct {
	int stick, piece, plug;
}Stack;

void cut(Stack *s){
	// ������ ó�� �Լ� 
	s->piece += s->stick;
}

void end_stick(Stack *s){
	//���� �� ó���Լ�
	s->stick--;  
	s->piece++;
}  

void add_stick(Stack *s){
	s->stick++;
}

int main(){
	
	Stack s;
	s.plug = 0;
	s.piece = 0;
	s.stick = 0;
	
	char *now;
	
	
	/*
	���� �߰� ()()�� ��� ������ �ΰ��ν��� �����.
	���ڿ��� �ް� ����Ʈ ������ ���� ()�� ��� *�� ġȯ����, �����μ����� ���۵Ǵ� ��� ä�� �ʿ�  
	*/
	while(scanf("%c",&now)){
		if(now == ')' && s.plug == 1){
			cut(&s);
			s.plug = 0;
		} 
		else if( now == '(' && s.plug == 0 ){
			add_stick(&s);
			s.plug = 1;
		}
		else if( now == ')' && s.plug == 0) {
			end_stick(&s);
		}
	}
	
	
	printf("%d\n", s.piece);
		
	getch();
	return 0;
}



