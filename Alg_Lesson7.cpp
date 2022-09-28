#include <iostream>

using namespace std;

void printArr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}
void randArr(int* arr, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {

		arr[i] = rand() % 100;
	}
}
void qs(int* arr, int first, int last) {
	int i = first;
	int j = last;
	int x = arr[(first + last) / 2];
	do {
		while (arr[i] < x) i++;
		while (arr[j] > x) j--;
		if (i <= j) {
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last) qs(arr, i, last);
	if (first < j) qs(arr, first, j);
}
void sort(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			if (arr[i] % 2  == 0 && arr[j] % 2 == 0 && arr[i] > arr[j]) {
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}

int main()
{
	const int n = 10;

	int arr[n];
	randArr(arr, n);
	printArr(arr, n);
	/*qs(arr, 0, n - 1);
	printArr(arr, n);*/
	sort(arr, n);
	printArr(arr, n);
}
