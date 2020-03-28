void findUserValue(int arr[]) {
	int userValue;
	int counter = 0;
	cout << "Введите любое целое число для поиска в массиве: ";
	cin >> userValue;
	for (int i = 0; i < ARR_SIZE; i++) {
		if (arr[i] == userValue) {
			cout << "Пользовательское число найдено в ячейке массива c индексом: "<< i << endl;
			counter++;
		}
	}
	cout << "Количество совпадений: " << counter<<endl;
}
