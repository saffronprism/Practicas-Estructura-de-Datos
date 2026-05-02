#ifndef ORD_H
#define ORD_H
#include <iostream>
#include <algorithm>
using namespace std;

class burbDinamica {
public:
    template <typename T>
    void ordPunter(T* arr[], int n) {
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(*arr[j] > *arr[j+1]){
                    T* temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    template <typename T>
    static bool compP(T* a, T* b) {
        return *a < *b;
    }

    template <typename T>
    void ordLibreria(T* arr[], int n) {
        sort(arr, arr+n, compP<T>);
    }

    template <typename T>
    void mostrar(T* arr[], int n) {
        for(int i=0; i<n; i++) cout << *arr[i] << " ";
        cout << "\n";
    }
};
#endif