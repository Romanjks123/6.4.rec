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
	// Ѕазовий випадок: €кщо ≥ндекс виходить за меж≥ масиву
	if (i >= size) {
		return 0;
	}
	// —ума поточного елемента та рекурсивний виклик дл€ наступного елемента
	return a[i] + SumRecursive(a, size, i + 2);
}

// –екурсивний пошук першого в≥д'Їмного елемента
int FindFirstNegativeIndex(double* a, const int size, int i = 0) {
	if (i >= size) return -1;      // якщо не знайдено, повертаЇмо -1
	if (a[i] < 0) return i;        // якщо знайдено в≥д'Їмний елемент, повертаЇмо його ≥ндекс
	return FindFirstNegativeIndex(a, size, i + 1);  // –екурсивний пошук дал≥
}

// –екурсивний пошук останнього в≥д'Їмного елемента
int FindLastNegativeIndex(double* a, const int size, int i) {
	if (i < 0) return -1;          // якщо не знайдено, повертаЇмо -1
	if (a[i] < 0) return i;        // якщо знайдено в≥д'Їмний елемент, повертаЇмо його ≥ндекс
	return FindLastNegativeIndex(a, size, i - 1);  // –екурсивний пошук назад
}

// –екурсивне обчисленн€ суми елемент≥в м≥ж двома ≥ндексами
int SumBetweenNegatives(double* a, int firstIndex, int lastIndex, int i) {
	if (i >= lastIndex) return 0;  // якщо дос€гли останнього ≥ндексу, припин€Їмо рекурс≥ю
	return a[i] + SumBetweenNegatives(a, firstIndex, lastIndex, i + 1);  // ƒодаЇмо елемент ≥ викликаЇмо функц≥ю дл€ наступного
}

// √оловна функц≥€, €ка викликаЇ рекурсивн≥ допом≥жн≥ функц≥њ
int SumNegatives(double* a, const int size) {
	int firstNegativeIndex = FindFirstNegativeIndex(a, size);  // «находимо перший в≥д'Їмний елемент
	int lastNegativeIndex = FindLastNegativeIndex(a, size, size - 1);  // «находимо останн≥й в≥д'Їмний елемент

	// якщо не знайдено в≥д'Їмних елемент≥в або вони зб≥гаютьс€
	if (firstNegativeIndex == -1 || lastNegativeIndex == -1 || firstNegativeIndex >= lastNegativeIndex) {
		return 0;  // якщо м≥ж ними немаЇ елемент≥в, повертаЇмо 0
	}

	// –екурсивно обчислюЇмо суму м≥ж першим ≥ останн≥м в≥д'Їмними елементами
	return SumBetweenNegatives(a, firstNegativeIndex, lastNegativeIndex, firstNegativeIndex + 1);
}

void Insert(double* a, int i) {
	int tmp = a[i]; // вибираЇмо елемент дл€ вставки
	int j = i - 1;  // ≥ндекс дл€ пошуку позиц≥њ вставки

	// ”мова дл€ перев≥рки (зам≥нюЇмо на потр≥бну)
	if (tmp > 1) {
		a[i] = 0; // зам≥нюЇмо елемент, €кщо б≥льше за 1 (умова може бути ≥ншою)
		return; // повертаЇмось, не виконуючи подальш≥ операц≥њ
	}

	// «сув елемент≥в, щоб знайти позиц≥ю дл€ вставки
	while (j >= 0 && a[j] > tmp) {
		a[j + 1] = a[j];
		j--;
	}

	a[j + 1] = tmp; // вставл€Їмо елемент на правильну позиц≥ю
}

void SortRecursive(double* a, const int size, int i = 1) {
	// Ѕазовий випадок: коли дос€гаЇмо к≥нц€ масиву
	if (i >= size)
		return;

	// ¬ставл€Їмо елемент на потр≥бну позиц≥ю
	Insert(a, i);

	// –екурсивний виклик дл€ наступного елемента
	SortRecursive(a, size, i + 1);
}

int main()
{
	srand((unsigned)time(NULL)); // ≥н≥ц≥ал≥зац≥€ генератора випадкових чисел
	int n;
	cout << "n= "; cin >> n;
	double* a = new double[n];
	int Low = -40;
	int High = 50;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	int sum = SumRecursive(a, n); // ¬икликаЇмо рекурсивну функц≥ю дл€ п≥драхунку суми
	cout << "Sum of elements with odd indices: " << sum << endl;
	int p = SumNegatives(a, n); // ¬икликаЇмо рекурсивну функц≥ю дл€ обчисленн€ суми
	cout << "Sum of elements between first and last negative: " << p << endl;
	SortRecursive(a, n);
	Print(a, n, 0);  // ¬иправлено ≥ндекс дл€ коректного виведенн€ масиву
	delete[] a; // ќчищенн€ пам'€т≥
	return 0;
}
