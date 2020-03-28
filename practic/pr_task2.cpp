using namespace std;

const int ARR_SIZE = 20;
const int RANGE = 9;
const int SHIFT_VALUE = 3;


void fillArr(int arr[]) {
		for (int i = 0; i < ARR_SIZE; i++) {
		arr[i] = rand() % RANGE - SHIFT_VALUE;
	}
}

void printArr(int arr[]) {
	for (int i = 0; i < ARR_SIZE; i++) {
		cout << arr[i] << " , ";
	}
	cout << endl;
}

int main() {
	srand(time(NULL));
	int arr[ARR_SIZE];
	fillArr(arr);
	printArr(arr);
	cout << endl;
	return 0;
}
