void checkArr (int arr[]) {
	const int SEARCH_ZERO = 0;
	const int SEARCH_ONE = 1;
	char star = '*';
	char dash = '-';
	char space = ' ';
	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (SEARCH_ZERO == arr[i]) {
			cout << star;
		}
		else if (SEARCH_ONE == arr[i]) {
			cout << dash;
		}
		else cout << space;
	}
	cout << endl;
}
