#include <stdio.h>
#include <math.h>

typedef struct _dot{
	double x, y;
}DOT;

double w; //1차함수의 기울기 
const double limit = 0.01; //오차 한도 
const double alpha = 10.0; //학습 계수 
double o = 100;

int main(){
	int n, i;
	int cnt = 0;
	w = 10;
	DOT train[100] = {0};
	printf("┌──────────────────────┐\n");
	printf("│                      │\n");
	printf("│ [[Linear Regression]]│\n");
	printf("│                      │\n");
	printf("└──────────────────────┘\n");
	printf("y = ax꼴 함수의 학습\n\n");
	printf("입력될 쌍의 개수를 입력해주세요.(2~100) : ");
	scanf("%d", &n);
	printf("%d개의 숫자 쌍을 입력해주세요(1~100)\n", n);
	for(i=0; i<n; i++){
		scanf("%lf %lf", &train[i].x, &train[i].y);
	}
	
	printf("\n\n");
	while(abs(o) > limit){
		o = 0;
		for(i=0; i<n; i++){
			double nowO = (w*train[i].x) - train[i].y;
			o += abs(nowO);
			w -= (nowO/alpha);
		}
		printf("%d : O = %.2lf\n", ++cnt, o);
	}
	
	printf("\n\n정답 = %lf", w);
}
