#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(double* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(double* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int SumRecursive(double* a, const int size, int i = 1) {
	// ������� �������: ���� ������ �������� �� ��� ������
	if (i >= size) {
		return 0;
	}
	// ���� ��������� �������� �� ����������� ������ ��� ���������� ��������
	return a[i] + SumRecursive(a, size, i + 2);
}

// ����������� ����� ������� ��'������ ��������
int FindFirstNegativeIndex(double* a, const int size, int i = 0) {
	if (i >= size) return -1;      // ���� �� ��������, ��������� -1
	if (a[i] < 0) return i;        // ���� �������� ��'����� �������, ��������� ���� ������
	return FindFirstNegativeIndex(a, size, i + 1);  // ����������� ����� ���
}

// ����������� ����� ���������� ��'������ ��������
int FindLastNegativeIndex(double* a, const int size, int i) {
	if (i < 0) return -1;          // ���� �� ��������, ��������� -1
	if (a[i] < 0) return i;        // ���� �������� ��'����� �������, ��������� ���� ������
	return FindLastNegativeIndex(a, size, i - 1);  // ����������� ����� �����
}

// ���������� ���������� ���� �������� �� ����� ���������
int SumBetweenNegatives(double* a, int firstIndex, int lastIndex, int i) {
	if (i >= lastIndex) return 0;  // ���� ������� ���������� �������, ���������� �������
	return a[i] + SumBetweenNegatives(a, firstIndex, lastIndex, i + 1);  // ������ ������� � ��������� ������� ��� ����������
}

// ������� �������, ��� ������� ��������� ������� �������
int SumNegatives(double* a, const int size) {
	int firstNegativeIndex = FindFirstNegativeIndex(a, size);  // ��������� ������ ��'����� �������
	int lastNegativeIndex = FindLastNegativeIndex(a, size, size - 1);  // ��������� ������� ��'����� �������

	// ���� �� �������� ��'����� �������� ��� ���� ���������
	if (firstNegativeIndex == -1 || lastNegativeIndex == -1 || firstNegativeIndex >= lastNegativeIndex) {
		return 0;  // ���� �� ���� ���� ��������, ��������� 0
	}

	// ���������� ���������� ���� �� ������ � ������� ��'������ ����������
	return SumBetweenNegatives(a, firstNegativeIndex, lastNegativeIndex, firstNegativeIndex + 1);
}

void Insert(double* a, int i) {
	int tmp = a[i]; // �������� ������� ��� �������
	int j = i - 1;  // ������ ��� ������ ������� �������

	// ����� ��� �������� (�������� �� �������)
	if (tmp > 1) {
		a[i] = 0; // �������� �������, ���� ����� �� 1 (����� ���� ���� �����)
		return; // �����������, �� ��������� �������� ��������
	}

	// ���� ��������, ��� ������ ������� ��� �������
	while (j >= 0 && a[j] > tmp) {
		a[j + 1] = a[j];
		j--;
	}

	a[j + 1] = tmp; // ���������� ������� �� ��������� �������
}

void SortRecursive(double* a, const int size, int i = 1) {
	// ������� �������: ���� �������� ���� ������
	if (i >= size)
		return;

	// ���������� ������� �� ������� �������
	Insert(a, i);

	// ����������� ������ ��� ���������� ��������
	SortRecursive(a, size, i + 1);
}

int main()
{
	srand((unsigned)time(NULL)); // ����������� ���������� ���������� �����
	int n;
	cout << "n= "; cin >> n;
	double* a = new double[n];
	int Low = -40;
	int High = 50;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	int sum = SumRecursive(a, n); // ��������� ���������� ������� ��� ��������� ����
	cout << "Sum of elements with odd indices: " << sum << endl;
	int p = SumNegatives(a, n); // ��������� ���������� ������� ��� ���������� ����
	cout << "Sum of elements between first and last negative: " << p << endl;
	SortRecursive(a, n);
	Print(a, n, 0);  // ���������� ������ ��� ���������� ��������� ������
	delete[] a; // �������� ���'��
	return 0;
}
