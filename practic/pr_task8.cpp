void findSmallestValue(int arr[]) {
	const int BEGIN_ARR = 0;
	int buffer = arr[BEGIN_ARR];
	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (buffer > arr[i]) {
			buffer = arr[i];
		}
	}
	cout << "Наименьшее значение в массиве: " << buffer << endl;
}
