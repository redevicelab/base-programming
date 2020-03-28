float oddArrAverageValue(int arr[]) {
	const int SEARCH_VALUE = 2;
	float sum = 0;
	int counter = 0;
	for (int i = 0; i < ARR_SIZE; i++) {
		if (arr[i] % SEARCH_VALUE) {
			sum += arr[i];
			counter++;
		}
	}
	return sum / counter;
}

float evenArrAverageValue(int arr[]) {
	const int SEARCH_VALUE = 2;
	float sum = 0;
	int counter = 0;
	for (int i = 0; i < ARR_SIZE; i++) {
		if (!(arr[i] % SEARCH_VALUE)) {
			sum += arr[i];
			counter++;
		}

	}
	return sum / counter;
}

void findWhatBig(float odd, float even) {
	if (odd < even) {
		cout << "Сравнение четных и нечетных значений массива. Итог: Четных больше\n";
	}
	else cout << "Сравнение четных и нечетных значений массива. Итог: Нечетных больше\n";
}
