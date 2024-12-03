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
	double array[N]; //���������� ������������ ������� ������� �����������
	// ���� ����� ���������
	int size;

	printf("������� ������ �������: ");
	scanf("%d", &size);

	full_elements(array, size);
	put_elements(array, size);

	//��������� ��������� ������� � ������
	calc_elements(array, size);

	// ������ ������� ����� ���������
	printf("������ ����� ���������:\n");
	put_elements(array, size);

	//���������� ����� ��������� �� begin �� end
	int begin, end;
	printf("������� ������� begin � end ��� ���������� �����: ");
	scanf("%d %d", &begin, &end);

	if (begin >= 0 && end < size && begin <= end) {
		double sum = sum_elements(array, begin, end);
		printf("����� ��������� �� %d �� %d: %.2lf\n", begin, end, sum);
	}
	else {
		printf("������������ ������� ��� �����!\n");
	}

	//����� �������� ������� ��������� ��������
	double element;
	printf("������� �������� ��� ������: ");
	scanf("%lf", &element);

	int index = find_element(array, size, element);
	if (index != -1) {
		printf("������� %lf ������ �� ������� %d\n", element, index);
	}
	else {
		printf("������� %lf �� ������\n", element);
	}

	//���������� ������� ������������ ��������
	int min_index = find_min_index(array, size);
	printf("������ ������������ ��������: %d, ��������: %.2lf\n", min_index, array[min_index]);

	return 0;

}

double* full_elements(double* ptr_array, int n)
{
	printf("������� �������� �������:\n");
	for (int i = 0; i < n; i++) {
		printf("������� %d: ", i + 1);
		scanf("%lf", &ptr_array[i]);
	}
	return ptr_array;

}

//������� ��� ������ ��������� �������
int put_elements(double* ptr_array, int n) {
	printf("�������� �������:\n");
	for (int i = 0; i < n; i++) {
		printf("%.2lf ", ptr_array[i]);
	}
	printf("\n");
	return 0;
}

//������ ��� ��������� ��������� ������� (���������� � 10 ���)
double* calc_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] /= 10.0;
	}
	return ptr_array;
}

//������� ��� ���������� ����� ��������� �� ������� begin �� end
double sum_elements(double* ptr_array, int begin, int end) {
	double sum = 0.0;
	for (int i = begin; i <= end; i++) {
		sum += ptr_array[i];
	}
	return sum;
}

//������� ��� ������ �������� ������� ��������� ��������
int find_element(double* ptr_array, int n, double element) {
	for (int i = 0; i < n; i++) {
	}
	return -1;
}

//������� ��� ���������� ������� ������������ ��������
int find_min_index(double* ptr_array, int n) {
	int min_index = 0;
	for (int i = 1; i < n; i++) {
		if (ptr_array[i] < ptr_array[min_index]) {
			min_index = i;
		}
	}
	return min_index;
}