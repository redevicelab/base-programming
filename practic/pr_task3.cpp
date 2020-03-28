void printPosetiv(int arr[]) {
	cout << "Все положительные: ";
	for (int i = 0; i < ARR_SIZE; i++) {
		if (arr[i] >= 0) {
			cout << arr[i] << " , ";
		}

	}
	cout << endl;
}
void printNegativ(int arr[]) {
	cout << "Все отрецательные: ";
	for (int i = 0; i < ARR_SIZE; i++) {
		if (arr[i] < 0) {
			cout << arr[i] << " , ";
		}

	}
	cout << endl;
}
