#include <iostream>
using namespace std;

// Função para fazer a troca de elementos
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para manter a propriedade do heap (max heap)
void heapify(int arr[], int n, int i) {
    int largest = i;  // Inicializa o maior como a raiz
    int left = 2 * i + 1;  // Filho esquerdo
    int right = 2 * i + 2;  // Filho direito

    // Verifica se o filho esquerdo é maior que a raiz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Verifica se o filho direito é maior que o maior até agora
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Se o maior não for a raiz
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Troca
        heapify(arr, n, largest);  // Recursão
    }
}

// Função principal do Heap Sort
void heapSort(int arr[], int n) {
    // Construa o heap (max heap)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extração dos elementos do heap um por um
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);  // Troca o maior (raiz) com o último elemento
        heapify(arr, i, 0);  // Reajusta o heap para manter a propriedade
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array antes da ordenação: ";
    printArray(arr, n);

    heapSort(arr, n);  // Chama o Heap Sort

    cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}

