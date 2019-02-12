#include <iostream>
#include <string>
using namespace std;

void print_array(int arr[], int SIZE){
    for(int i = 0; i < SIZE; ++i){
        cout << arr[i] << '\t';
    }   cout << endl;
}

// inc == true: increasing, inc == false: non-increasing
void bubble_sort(int arr[], int SIZE, bool inc){
    int temp;
    for (int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE - i - 1; ++j){
            if(inc){
                if(arr[j] > arr[j + 1]){
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            else{
                if(arr[j] < arr[j + 1]){
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

//
void insertion_sort(int arr[], int SIZE, bool inc){
    int temp, k;
    for(int i = 0; i < SIZE - 1; ++i){
        int j = i;
        while(j >= 0)
        {
            if ((arr[i + 1] < arr[j]) && (arr[i + 1] > arr[j - 1]))
            {
                temp = arr[i + 1];
                k = i;
                while(k >= j){
                    arr[k + 1] =  arr[k];
                    --k;
                }
                arr[j] = temp;
            }
        --j;
        }
    }
}


// selection sort
void selection_sort(int arr[], int SIZE){
    int min_value, temp;
    for (int i = 0; i < SIZE; ++i){
        min_value = arr[i];
        for (int j = i + 1; j < SIZE; ++j){
            if(arr[j] < min_value){
                temp = min_value;
                min_value = arr[j];
                arr[j] = temp;
            }
        }
        arr[i] = min_value;
    }
}


int main() {
    int arr[] = {24, -1, 2, 4, 1, -8, -12, 14, 5};
    int SIZE = sizeof(arr)/sizeof(*arr);

    cout << "Bubble sort: "<< endl;
    print_array(arr, SIZE);
    bubble_sort(arr, SIZE, true); // true for increasing
    print_array(arr, SIZE);

    int arr2[] = {24, -1, 2, 4, 1, -8, -12, 14, 5};
    int SIZE2 = sizeof(arr2)/sizeof(*arr2);
    cout << "Insertion sort: "<< endl;
    print_array(arr2, SIZE2);
    insertion_sort(arr2, SIZE2, true); // true for increasing
    print_array(arr2, SIZE2);

    int arr3[] = {24, -1, 2, 4, 1, -8, -12, 14, 5};
    int SIZE3 = sizeof(arr3)/sizeof(*arr3);
    cout << "Insertion sort: "<< endl;
    print_array(arr3, SIZE3);
    selection_sort(arr3, SIZE3); // true for increasing
    print_array(arr3, SIZE3);
    return 0;
}