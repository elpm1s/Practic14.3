#include <stdio.h>
#include <math.h>
#include <locale.h>
#define N 100

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);

int main()
{
	setlocale(LC_ALL, "RUS");
	double array[N]; //объ€вление статического массива большой размерности
	// ввод числа элементов
	int size;

	printf("¬ведите размер массива: ");
	scanf("%d", &size);

	full_elements(array, size);
	put_elements(array, size);

	//обработка элементов массива и печать
	calc_elements(array, size);

	// ѕечать массива после обработки
	printf("ћассив после обработки:\n");
	put_elements(array, size);

	//вычисление суммы элементов от begin до end
	int begin, end;
	printf("¬ведите индексы begin и end дл€ вычислени€ суммы: ");
	scanf("%d %d", &begin, &end);

	if (begin >= 0 && end < size && begin <= end) {
		double sum = sum_elements(array, begin, end);
		printf("—умма элементов от %d до %d: %.2lf\n", begin, end, sum);
	}
	else {
		printf("Ќекорректные индексы дл€ суммы!\n");
	}

	//поиск элемента равного заданному значению
	double element;
	printf("¬ведите значение дл€ поиска: ");
	scanf("%lf", &element);

	int index = find_element(array, size, element);
	if (index != -1) {
		printf("Ёлемент %lf найден на индексе %d\n", element, index);
	}
	else {
		printf("Ёлемент %lf не найден\n", element);
	}

	//нахождение индекса минимального элемента
	int min_index = find_min_index(array, size);
	printf("»ндекс минимального элемента: %d, значение: %.2lf\n", min_index, array[min_index]);

	return 0;

}

double* full_elements(double* ptr_array, int n)
{
	printf("¬ведите элементы массива:\n");
	for (int i = 0; i < n; i++) {
		printf("Ёлемент %d: ", i + 1);
		scanf("%lf", &ptr_array[i]);
	}
	return ptr_array;

}

//функци€ дл€ печати элементов массива
int put_elements(double* ptr_array, int n) {
	printf("Ёлементы массива:\n");
	for (int i = 0; i < n; i++) {
		printf("%.2lf ", ptr_array[i]);
	}
	printf("\n");
	return 0;
}

//фнкци€ дл€ обработки элементов массива (уменьшение в 10 раз)
double* calc_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] /= 10.0;
	}
	return ptr_array;
}

//функци€ дл€ вычислени€ суммы элементов от индекса begin до end
double sum_elements(double* ptr_array, int begin, int end) {
	double sum = 0.0;
	for (int i = begin; i <= end; i++) {
		sum += ptr_array[i];
	}
	return sum;
}

//функци€ дл€ поиска элемента равного заданному значению
int find_element(double* ptr_array, int n, double element) {
	for (int i = 0; i < n; i++) {
	}
	return -1;
}

//функци€ дл€ нахождени€ индекса минимального элемента
int find_min_index(double* ptr_array, int n) {
	int min_index = 0;
	for (int i = 1; i < n; i++) {
		if (ptr_array[i] < ptr_array[min_index]) {
			min_index = i;
		}
	}
	return min_index;
}