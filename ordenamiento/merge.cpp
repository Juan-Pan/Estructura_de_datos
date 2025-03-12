#include <iostream>
#include <vector>
#include <climits> // Para INT_MAX

using namespace std;

void merge(vector<int> &a, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // Crear arreglos temporales
    vector<int> l(n1 + 1);
    vector<int> r_arr(n2 + 1);

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; i++)
        l[i] = a[p + i];

    for (int j = 0; j < n2; j++)
        r_arr[j] = a[q + 1 + j];

    // Agregar "sentinelas" al final
    l[n1] = INT_MAX;
    r_arr[n2] = INT_MAX;

    int i = 0, j = 0;

    // Mezclar los arreglos de vuelta en `a`
    for (int k = p; k <= r; k++) {
        if (l[i] <= r_arr[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r_arr[j];
            j++;
        }
    }
}

int main() {
    int n;
    cin >> n; // Leer cantidad de elementos

    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i]; // Leer los elementos del array

    int p = 0, q = (n / 2) - 1, r = n - 1;
    merge(a, p, q, r); // Aplicar la función merge

    // Imprimir el array resultante en una sola línea
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
