#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


/*경우의 수
1. (로 막대시작 -> 
2. )로 막대 종료
3. ()로 레이져 발사 

동작을 행하는건 다음 문자에 와서 실행 
NULL값을 만날때까지 반복하여 문자를 읽어 들인다. 
NULL값이 아닐경우 이전 문자와 지금 문자 비교하여 동작 결정
NULL값인 경우 조각 갯수에 1을 더하고 프로그램 종료 
*/

typedef struct {
	int stick, piece, plug;
}Stack;

void cut(Stack *s){
	// 레이져 처리 함수 
	s->piece += s->stick;
}

void end_stick(Stack *s){
	//막대 끝 처리함수
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
	문제 발견 ()()의 경우 레이져 두개인식이 힘들다.
	문자열로 받고 포인트 연산을 통해 ()를 모두 *로 치환한후, 본프로세스가 동작되는 방식 채용 필요  
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



