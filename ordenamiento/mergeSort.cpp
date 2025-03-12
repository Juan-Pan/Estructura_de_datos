#include <iostream>
#include <climits> // Para INT_MAX

using namespace std;

// Función Merge
void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *l = new int[n1 + 1];  
    int *r_arr = new int[n2 + 1];

    for (int i = 0; i < n1; i++)  
        l[i] = a[p + i];

    for (int j = 0; j < n2; j++)  
        r_arr[j] = a[q + 1 + j];

    l[n1] = INT_MAX;
    r_arr[n2] = INT_MAX;

    int i = 0, j = 0;

    for (int k = p; k <= r; k++) {
        if (l[i] <= r_arr[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r_arr[j];
            j++;
        }
    }

    delete[] l;
    delete[] r_arr;
}

// Función Merge Sort
void mergeSort(int a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

int main() {
    int n;
    cin >> n;  // Leer la cantidad de números

    int *a = new int[n]; // Arreglo dinámico

    // Leer los elementos del arreglo
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Ordenar usando Merge Sort
    mergeSort(a, 0, n - 1);

    // Imprimir el arreglo ordenado
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a; // Liberar memoria

    return 0;
}
