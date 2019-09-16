#include<iostream>
#include<ctime>

using namespace std;

int GetRandomNum(int max, int min){
    return(rand() % (max - min) + min);
}

char GetRandomOp(){
	switch(rand() % 4){
		case 0: return '+';
		case 1: return '-';
		case 2: return '*';
		case 3: return '/'; 
	}
}

void PrintQuestion(int num, int max, int min){
	srand((int)time(0));
	int a, b;
	char op;
	for(int i = 0; i < num; ++i){
		a = GetRandomNum(max, min);
		b = GetRandomNum(max, min);
		op = GetRandomOp();
		if(op == '-' && a < b)
			i--;
		else if(op == '/' && (b == 0 || a % b != 0))
			i--;
		else
			cout << a << ' ' << op << ' ' << b << '=' << endl;
	}
}

int main(){
    int allNum, min, max;
    cout << "请输入预计题目数量>>>";
    cin >> allNum;
    min = 0; max = 10;
    
    PrintQuestion(allNum, max, min);
    
    cout << "请按任意键继续"; 
    getchar();
}
