#include<iostream>
#include<ctime>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectsort(int arr[],int n)
{
    int min;
    for(int i = 0; i < n; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i) 
            swap(arr[i], arr[min]);
    }
}
void bubblesort(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void insertsort(int arr[],int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void heapify(int arr[], int n, int i) {
    int largest = i;    
    int l = 2 * i + 1;   
    int r = 2 * i + 2;   
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);  
        heapify(arr, n, largest); 
    }
}
void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0);   
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void getdata(int arr[], int n){
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
}
int main(){
    for (int i = 5; i<=20;i+=5){
        cout << "\nEnter " << i << " elements:";
        int arr[i],arr1[i],arr2[i],arr3[i],arr4[i];
        getdata(arr,i);
        for(int j = 0;j < i;j++)
        {
            arr1[j] = arr[j];
            arr2[j] = arr[j];
            arr3[j] = arr[j];
            arr4[j] = arr[j];
        }
        cout << "Heapsort:" << endl;
        clock_t start = clock();
        heapsort(arr1, i);
        clock_t end = clock();
        cout << " Start time: " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << " End time: " << double(end) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << " Elapsed time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << "Sorted elements:";
        display(arr1,i);
        cout << "Insertion sort:" << endl;
        start = clock();
        insertsort(arr2, i);
        end = clock();
        cout << " Start time: " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << " End time: " << double(end) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << " Elapsed time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << "Sorted elements:";
        display(arr2,i);
        cout << "Bubble sort:" << endl;
        start = clock();
        bubblesort(arr3, i);
        end = clock();
        cout << " Start time: " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << " End time: " << double(end) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << " Elapsed time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << "Sorted elements:";
        display(arr3,i);
        cout << "Selection sort:" << endl;
        start = clock();
        selectsort(arr4, i);
        end = clock();
        cout << " Start time: " << double(start) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << " End time: " << double(end) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << " Elapsed time: " << double(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
        cout << "Sorted elements:";
        display(arr4,i);
    }
    return 0;
}