#include <iostream>
#include <cstring>
using namespace std;

void PrintArr(int* a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void SelectionSort(int arr[], int n, long long& comparisons) {
    for (int i = 0; ++comparisons && i < n - 1; i++) {
        int min_indx = i;
        for (int j = i + 1; ++comparisons && j < n; j++) {
            if (++comparisons && arr[min_indx] > arr[j])
                min_indx = j;
        }
        swap(arr[min_indx], arr[i]);
    }
}

void InsertionSort(int a[], int n, long long& comparisons) {
    int key, j;
    for (int i = 1; ++comparisons && i < n; i++) {
        key = a[i];
        j = i - 1;
        while (++comparisons && j >= 0 && ++comparisons && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void BubbleSort(int a[], int n, long long& comparisons) {
    for (int i = 0; ++comparisons && i < n - 1; ++i) {
        for (int j = i + 1; ++comparisons && j < n; ++j) {
            if (++comparisons && a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void Heapify(int arr[], int n, int i, long long& comparisons) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    comparisons++; // Tăng số lần so sánh ở dòng if trên
    if (left < n) {
        comparisons++;  // Tăng số lần so sánh ở dòng if dưới
        if (arr[left] > arr[largest]) {
            largest = left;
        }
    }

    comparisons++; // Tăng số lần so sánh
    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest]) {
            largest = right;
        }
    }

    comparisons++;
    if (largest != i) {
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest, comparisons);
    }
}

void HeapSort(int arr[], int n, long long& comparisons) {
    for (int i = n / 2 - 1; i >= 0 && ++comparisons; i--)
        Heapify(arr, n, i, comparisons);

    for (int i = n - 1; i > 0 && ++comparisons; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0, comparisons);
    }
}

void Merge(int arr[], int l, int m, int r, long long& comparisons) {
    int length1 = m - l + 1;
    int length2 = r - m;

    int* leftArr = new int[length1];
    int* rightArr = new int[length2];

    for (int i = 0; ++comparisons && i < length1; i++)
        leftArr[i] = arr[l + i];

    for (int i = 0; ++comparisons && i < length2; i++)
        rightArr[i] = arr[m + i + 1];

    int indexOfArr1 = 0, indexOfArr2 = 0, i = l;

    while (++comparisons && indexOfArr1 < length1 && ++comparisons && indexOfArr2 < length2) {
        if (++comparisons && leftArr[indexOfArr1] < rightArr[indexOfArr2]) {
            arr[i] = leftArr[indexOfArr1++];
        }
        else if (++comparisons && leftArr[indexOfArr1] >= rightArr[indexOfArr2]) {
            arr[i] = rightArr[indexOfArr2++];
        }
        i++;
    }

    while (++comparisons && indexOfArr1 < length1) {
        arr[i++] = leftArr[indexOfArr1++];
    }
    while (++comparisons && indexOfArr2 < length2) {
        arr[i++] = rightArr[indexOfArr2++];
    }
    delete[] leftArr;
    delete[] rightArr;
}

void MergeSort(int arr[], int l, int r, long long& comparisons) {
    if (l >= r)
        return;
    int m = (r + l) / 2;
    MergeSort(arr, l, m, comparisons);
    MergeSort(arr, m + 1, r, comparisons);
    Merge(arr, l, m, r, comparisons);
}

int MedianOfThree(int arr[], int l, int r, long long& comparisons) {
    int mid = l + (r - l) / 2;
    if (++comparisons && arr[mid] < arr[l]) {
        swap(arr[mid], arr[l]);
    }
    if (++comparisons && arr[r] < arr[l]) {
        swap(arr[r], arr[l]);
    }
    if (++comparisons && arr[r] < arr[mid]) {
        swap(arr[r], arr[mid]);
    }
    return mid;
}

int Partition(int arr[], int l, int r, long long& comparisons) {
    int pivotIndex = MedianOfThree(arr, l, r, comparisons);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[r]);

    int i = l - 1;
    for (int j = l; ++comparisons && j < r; j++) {
        if (++comparisons && arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    i++;
    swap(arr[i], arr[r]);
    return i;
}

void QuickSort(int arr[], int l, int r, long long& comparisons) {
    if (++comparisons && l < r) {
        comparisons++;
        int pivot = Partition(arr, l, r, comparisons);
        QuickSort(arr, l, pivot - 1, comparisons);
        QuickSort(arr, pivot + 1, r, comparisons);
    }
}

int GetMax(int a[], int n, long long& comparisons) {
    int mx = a[0];
    for (int i = 0; i < n && ++comparisons; i++) {
        comparisons++; // Tăng số lần so sánh
        mx = std::max(mx, a[i]);
    }
    return mx;
}

void CountSort(int a[], int n, int exp, long long& comparisons) {
    int i, count[10] = { 0 };
    int* OutPutArray = new int[500000];

    for (i = 0; ++comparisons && i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }

    for (i = 1; ++comparisons && i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; ++comparisons && i >= 0; i--) {
        OutPutArray[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; ++comparisons && i < n; i++) {
        a[i] = OutPutArray[i];
    }
}

void RadixSort(int a[], int n, long long& comparisons) {
    int mx = GetMax(a, n, comparisons);
    for (int exp = 1; ++comparisons && mx / exp > 0; exp *= 10) {
        CountSort(a, n, exp, comparisons);
    }
}

void ShakerSort(int a[], int n, long long& comparisons) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // Reset the swapped flag on entering the loop
        // because it might be true from a previous iteration.
        swapped = false;

        // Loop from left to right, same as the bubble sort
        for (int i = start; i < end; ++i) {
            if (++comparisons && a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        // If nothing moved, then the array is sorted.
        if (!swapped)
            break;

        // Otherwise, reset the swapped flag for the next stage
        swapped = false;

        // Move the end point back by one because the item at the end
        // is in its rightful spot.
        --end;

        // From right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            if (++comparisons && a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        // Increase the starting point because the last stage
        // would have moved the next smallest number to its rightful spot.
        ++start;
    }
}
void ShellSort(int a[], int n, long long& comparisons) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1) {
            // Add a[i] to the elements that have been gap sorted
            // Save a[i] in temp and make a hole at position i
            int temp = a[i];

            // Shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && ++comparisons && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            // Put temp (the original a[i]) in its correct location
            a[j] = temp;
        }
    }
}

void CountingSort(int a[], int n, long long& comparisons) {
    // Finding the maximum element of array a[].
    int M = 0;

    for (int i = 0; i < n; i++)
        M = std::max(M, a[i]);

    // Initializing countArray[] with 0
    int* countArray = new int[M + 1]();

    // Mapping each element of array a[] as an index
    // of countArray[] array
    for (int i = 0; i < n; i++)
        countArray[a[i]]++;

    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    int* outputArray = new int [n];

    for (int i = n - 1; i >= 0; i--) {
        outputArray[countArray[a[i]] - 1] = a[i];
        countArray[a[i]]--;
    }

    // Copying the result back to the original array of pointers
    for (int i = 0; i < n; i++)
        a[i] = outputArray[i];

    // Freeing dynamically allocated memory
    delete[] countArray;
    delete[] outputArray;
}

void FlashSort(int a[], int n, long long& comparisons) {
    const int kMax = 300000;
    int* __L = new int[kMax];
    memset(__L, 0, sizeof(int) * kMax);

    if (n <= 1) {
        delete[] __L;
        return;
    }

    int m = static_cast<int>(n * 0.43);
    if (m <= 2)
        m = 2;

    for (int i = 0; i < m; ++i)
        __L[i] = 0;

    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; ++i) {
        if (Mx < a[i])
            Mx = a[i];
        if (Mn > a[i])
            Mn = a[i];
    }

    if (Mx == Mn) {
        delete[] __L;
        return;
    }

    auto getK = [Mn, Mx, m](int x) { return static_cast<int>(1ll * (m - 1) * (x - Mn) / (Mx - Mn)); };

    for (int i = 0; i < n; ++i)
        ++__L[getK(a[i])];

    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];

    // Step 2
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = getK(a[i]);
        while (i >= __L[k])
            k = getK(a[++i]);
        int z = a[i];
        while (i != __L[k]) {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }

    // Step 3
    for (int k = 1; k < m; ++k) {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i) {
            if (++comparisons && a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (++comparisons && t > a[j + 1]) {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }

    delete[] __L;
}