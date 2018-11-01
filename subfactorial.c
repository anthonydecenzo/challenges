#include <stdio.h>

int subfactorialNum(int x);
int numPower(int x, int exp);
int factorialNum(int x);

int main(int argc, char *argv[]){
	int num = *argv[1] - '0';	
	printf("Subfactorial of %d: %d\n", num, subfactorialNum(num));
	
	return 0;
}

 int subfactorialNum(int x){
	float sum = 0;
	int factorialY = factorialNum(x);

	int num, denom;
	float output = 0.0f;

	for(int i = 0; i <= x; i++){
		num = numPower(-1, i);
		denom = factorialNum(i);
		
		output = (((float)num / (float)denom));
		
		sum += output;
	}

	return (int)(factorialY * sum)+1;
}

int factorialNum(int x){
	if(x == 0 || x == 1){
		return 1;
	} else {
		return x * factorialNum(x - 1);
	}
}

int numPower(int x, int exp){
	int ret = 1;

	while(exp != 0){
		if((exp & 1) == 1){
			ret *= x;
		}
		x *= x;
		exp >>= 1;
	}
	return ret;
}
