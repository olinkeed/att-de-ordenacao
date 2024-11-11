#include <iostream>
using namespace std;

// Função para fazer a troca de elementos
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função de particionamento
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Escolhe o pivô como o último elemento
    int i = low - 1;  // Índice do menor elemento

    // Reorganiza os elementos para que os menores fiquem à esquerda e os maiores à direita do pivô
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Coloca o pivô na posição correta
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Retorna o índice do pivô
}

// Função recursiva de Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtém o índice do pivô
        int pi = partition(arr, low, high);

        // Ordena as duas sublistas recursivamente
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array antes da ordenação: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);  // Chama o Quick Sort

    cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}
