#ifndef ORDDINAMICO_H
#define ORDDINAMICO_H
#include <iostream>
#include <algorithm>
using namespace std;

class mergeDinamico {
public:
    template <typename T>
    void fP(T** arr, int i, int m, int d) {
        int n1=m-i+1, n2=d-m;
        T** L = new T*[n1]; 
        T** R = new T*[n2];
        for(int x=0; x<n1; x++) L[x] = arr[i+x];
        for(int y=0; y<n2; y++) R[y] = arr[m+1+y];

        int x=0, y=0, k=i;
        while(x<n1 && y<n2){ 
            if(*L[x] <= *R[y]){ 
                arr[k] = L[x]; x++;
            }
            else{
                arr[k] = R[y]; 
                y++; 
            } 
            k++; 
        }
        while(x<n1){ 
            arr[k] = L[x]; 
            x++; 
            k++; }
        while(y<n2){ 
            arr[k] = R[y]; 
            y++; 
            k++; }
        delete[] L; delete[] R;
    }

    template <typename T>
    void recP(T** arr, int i, int d) {
        if(i>=d) return;
        int m = i+(d-i)/2;
        recP(arr, i, m);
        recP(arr, m+1, d);
        fP(arr, i, m, d);
    }

    template <typename T>
    void ordPunter(T** arr, int n) {
        recP(arr, 0, n-1);
    }

    template <typename T>
    static bool compP(T* a, T* b) {
        return *a < *b;
    }

    template <typename T>
    void ordLibreria(T** arr, int n) {
        sort(arr, arr + n, compP<T>);
    }

    template <typename T>
    void mostrar(T** arr, int n) {
        for(int i=0; i<n; i++) cout << *arr[i] << " ";
        cout << "\n";
    }
};
#endif