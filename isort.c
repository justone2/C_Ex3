#include <stdio.h>

#define SIZE 50

void shift_element(int* arr, int i) {
    for (int j = i; j > 0; j--) {
        *(arr + j) = *(arr + j - 1);
    }
}

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", *(arr + i));

    printf("\n");
}


void insertion_sort(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (*(arr + i) < *(arr + j)) {
                int temp = *(arr + i);
                shift_element((arr + j), i - j);
                *(arr + i - (i - j)) = temp;
                temp = *(arr + i);
            }
        }
    }
}

int main() {
	int arr[SIZE];

	for(int i = 0; i < SIZE; i++) {
		scanf("%d", &arr[i]);
	}

	insertion_sort(arr, SIZE);
	print_arr(arr, SIZE);
}
