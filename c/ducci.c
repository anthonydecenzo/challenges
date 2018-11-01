#include <stdio.h>

// Challenge #364 The Ducci Sequence from /r/dailyprogrammer

// prototype methods
int findStepsDucci(int arr[], int length);
int isZeroTuple(int arr[], int length);
int absoluteValue(int num);

// global variable
int numOfSteps = 0;

int main(){

	// sequence
	int sequence[4] = {0, 653, 1854, 4063};
	

	int numOfSteps = findStepsDucci(sequence, ((int) sizeof(sequence) / sizeof(sequence[0])));
	

	printf("Number of steps:%d\n", numOfSteps);
	return 0;
}

int findStepsDucci(int arr[], int length){
	
	int absDiff = 0;
	
	// create new array each iteration
	int tempArr[4] = {0,0,0,0};

	for(int i = 0; i < length; i++){
		// if end of array is met, subtract w/ first element in array 
		// else find absolute difference between current node and the successor node
		if(i == (length - 1)){
			absDiff = absoluteValue(arr[i] - arr[0]);
		} else {
			absDiff = absoluteValue(arr[i] - arr[i+1]); 
		}
		tempArr[i] = absDiff;
	}

	numOfSteps++;

	// check if the entire array is zero
	if(isZeroTuple(tempArr, ((int) sizeof(tempArr) / sizeof(tempArr[0]) )) == 1){
		return numOfSteps + 1;
	} else {
		// recursively call with the tempArr to redo until all elements are zero
		findStepsDucci(tempArr, ((int) sizeof(tempArr) / sizeof(tempArr[0])));
	}
}

// remaining methods are self explanatory

int isZeroTuple(int arr[], int length){
	for(int i = 0; i < length; i++){
		if(arr[i] != 0){
			return 0;
		}		
	}
	return 1;
}

int absoluteValue(int num){
	if(num < 0){
		return num * -1;
	}
	return num;
}

