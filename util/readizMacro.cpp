#define	ARRAY_SIZE(x)	( sizeof((x))/sizeof((x)[0]) ) // 배열 길이
#define	ABS(x)			( ((x)<0)?-(x):(x) )	// 절대 값
#define	SQUARE(x)		( (x)*(x) )	// 제곱근
#define	MAX(x,y)		( (x) > (y) ? (x) : (y) )	// 최대 값
#define	MIN(x,y)		( (x) < (y) ? (x) : (y) )	// 최소 값
#define	UPCASE(c)		( ( (c)>='a' && (c)<='z') ? (c)-('a'-'A') : (c) )	// 소문자->대문자
#define LOWCASE(c)		( ( (c)>='A' && (c)<='Z') ? (c)+('a'-'A') : (c) )	// 대문자->소문자

// ARRAY_SIZE(x) 사용 예
int arn_numbers[] = {1, 2, 3, 4, 5};
int n_index;
for( n_index=0 ; n_index<ARRAY_SIZE(arn_numbers) ; n_index++ )
{
	printf("%d\t", arn_numbers[n_index]);
}
printf("\n");


// ABS(x) 사용 예
int n_num = -5;
printf("원래 값: %d, 절대 값: %d\n", n_num, ABS(n_num));


// SQUARE(x) 사용 예
int n_num = -5;
printf("결과 값: %d\n", SQUARE(n_num));


// MAX(x,y), MIN(x,y) 사용 예
int n_x = 10;
int n_y = 20;
printf("Max : %d, Min : %d\n", MAX(n_x, n_y), MIN(n_x, n_y));


// UPCASE(c), LOWCASE(c) 사용 예
char c_input = 'a';
char c_output1 = UPCASE(c_input);
char c_output2 = LOWCASE(c_output1);
printf("input : %c, ouput1 : %c, output2 : %c\n", c_input, c_output1, c_output2);