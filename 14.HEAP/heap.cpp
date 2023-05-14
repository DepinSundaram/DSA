#include <iostream>

using namespace std;


class heap
{
    public:
        heap() {
            size = 0;
            arr[0] = -1;
        }
        int arr[100];
        int size ;
            // insert O(logn)
        void insert(int val) {
            size = size + 1;
            int idx = size;
            arr[idx] = val;


            while (idx > 1) {
                int parent =  idx/2;
                if (arr[parent] < arr[idx]) {
                    std::swap(arr[parent], arr[idx]);
                    idx = parent;
                } else {
                    return;
                }
            }
        }

        void print() {
            for (int i = 1; i <= size; i++) {
                cout << arr[i] << " ";
            }cout << endl;
        }

            // deletion O(logn)

        void DeleteRootfromHeap() {
            if (size == 0) {
                return;
            }
            // place last element to first idx
            arr[1] = arr[size];
            // remove last indx
            size--;

            int i = 1;
            // take root node to its correct posistion
            while (i < size) {
                int leftIdx = 2*i;
                int rightIdx = 2*i + 1;

                if (leftIdx < size && arr[i] < arr[leftIdx]) {
                    std::swap(arr[i], arr[leftIdx]);
                    i = leftIdx;
                } else 
                if (rightIdx < size && arr[i] < arr[rightIdx]) {
                    std::swap(arr[i], arr[leftIdx]);
                    i = rightIdx;
                } else {
                    return;
                }
            }
        }


        void heapify(int arr[], int n , int i) {
            int largest = i;
            int leftIdx = 2*i;
            int rightIdx = 2*i + 1;

            if (leftIdx < n && arr[largest] < arr[leftIdx]) {
                    largest = leftIdx;
            }  
            if (rightIdx < n && arr[largest] < arr[rightIdx]) {
                largest = rightIdx;
            }

            if (largest !=i) {
                swap(arr[largest], arr[i]);
                heapify(arr, n, largest);
            }
        }
};


        void heapify(int arr[], int n , int i) {
            int largest = i;
            int leftIdx = 2*i;
            int rightIdx = 2*i + 1;

            if (leftIdx < n && arr[largest] < arr[leftIdx]) {
                    largest = leftIdx;
            }  
            if (rightIdx < n && arr[largest] < arr[rightIdx]) {
                largest = rightIdx;
            }

            if (largest !=i) {
                swap(arr[largest], arr[i]);
                heapify(arr, n, largest);
            }
        }
int main()
{

    heap hp;
    hp.insert(50);
    hp.insert(55);
    hp.insert(53);
    hp.insert(52);
    hp.insert(54);
    hp.print();
    hp.DeleteRootfromHeap();
    hp.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};

    int n = 5;
    // n/2 + 1 are leafs which follows heaps hence 0 till n/2
    for (int i = n/2 ; i > 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = 1 ; i <= 5; i++) {
        cout << arr[i] << " ";

    }
    return 0;
}