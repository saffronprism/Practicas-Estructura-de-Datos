#ifndef ORD_H
#define ORD_H
#include <iostream>
#include <algorithm>
using namespace std;

class quickDin {
public:
    template <typename T>
    int partP(T* arr[], int i, int d) {
        T piv = *arr[d];
        int k = i - 1;
        for(int j=i; j<d; j++){
            if(*arr[j] < piv){
                k++;
                swap(arr[k], arr[j]);
            }
        }
        swap(arr[k + 1], arr[d]);
        return k + 1;
    }

    template <typename T>
    void recP(T* arr[], int i, int d) {
        if(i < d){
            int p = partP(arr, i, d);
            recP(arr, i, p - 1);
            recP(arr, p + 1, d);
        }
    }

    template <typename T>
    void ordPunter(T* arr[], int n) {
        recP(arr, 0, n - 1);
    }

    template <typename T>
    static bool compP(T* a, T* b) {
        return *a < *b;
    }

    template <typename T>
    void ordLibreria(T* arr[], int n) {
        sort(arr, arr + n, compP<T>);
    }

    template <typename T>
    void mostrar(T* arr[], int n) {
        for(int i=0; i<n; i++) cout << *arr[i] << " ";
        cout << "\n";
    }
};
#endif