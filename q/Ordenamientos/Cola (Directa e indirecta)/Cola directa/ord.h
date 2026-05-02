#ifndef ORD_H
#define ORD_H
#include <iostream>
#include <algorithm>
using namespace std;

class quickEst {
public:
    template <typename T>
    int part(T arr[], int i, int d) {
        T piv = arr[d];
        int k = i - 1;
        for(int j=i; j<d; j++){
            if(arr[j] < piv){
                k++;
                swap(arr[k], arr[j]);
            }
        }
        swap(arr[k + 1], arr[d]);
        return k + 1;
    }

    template <typename T>
    void rec(T arr[], int i, int d) {
        if(i < d){
            int p = part(arr, i, d);
            rec(arr, i, p - 1);
            rec(arr, p + 1, d);
        }
    }

    template <typename T>
    void ordArreglo(T arr[], int n) {
        rec(arr, 0, n - 1);
    }

    template <typename T>
    void ordLibreria(T arr[], int n) {
        sort(arr, arr + n);
    }

    template <typename T>
    void mostrar(T arr[], int n) {
        for(int i=0; i<n; i++) cout << arr[i] << " ";
        cout << "\n";
    }
};
#endif