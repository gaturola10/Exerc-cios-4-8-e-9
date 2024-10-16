#include <stdio.h>

// Função que ordena o array usando o algoritmo Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Percorre todo o array
    for (i = 0; i < n - 1; i++) {
        // Encontra o menor elemento no array não ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro elemento
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;

    // Solicita ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int arr[n];

    // Solicita ao usuário para digitar os elementos do array
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array original: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Chama a função para ordenar o array
    selectionSort(arr, n);

    printf("Array ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

