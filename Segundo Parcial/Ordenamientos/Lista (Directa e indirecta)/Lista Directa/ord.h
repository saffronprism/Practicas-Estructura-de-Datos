#ifndef ORD_H
#define ORD_H
#include <iostream>
#include <algorithm>
using namespace std;

class mergeEst {
public:
    template <typename T>
    void f(T arr[], int i, int m, int d) {
        int n1=m-i+1, n2=d-m;
        T* L = new T[n1];
        T* R = new T[n2];
        for(int x=0; x<n1; x++) L[x] = arr[i+x];
        for(int y=0; y<n2; y++) R[y] = arr[m+1+y];

        int x=0, y=0, k=i;
        while(x<n1 && y<n2){
            if(L[x] <= R[y]){
                arr[k] = L[x]; x++;
            }
            else{
                arr[k] = R[y]; y++;
            }
            k++; }
        while(x<n1){
            arr[k] = L[x]; 
            x++;
            k++;
        }
        while(y<n2){
            arr[k] = R[y];
            y++; 
            k++; }
        delete[] L; delete[] R;
    }

    template <typename T>
    void rec(T arr[], int i, int d) {
        if(i>=d) return;
        int m = i+(d-i)/2;
        rec(arr, i, m);
        rec(arr, m+1, d);
        f(arr, i, m, d);
    }

    template <typename T>
    void ordArreglo(T arr[], int n) {
        rec(arr, 0, n-1);
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