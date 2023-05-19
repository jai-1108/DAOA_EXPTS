#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int beg, int mid, int end) {
    int i = beg, j = mid + 1, k = 0;
    int *temp = malloc(sizeof(int) * (end - beg + 1));

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= end)
        temp[k++] = arr[j++];

    for (i = 0; i < k; i++)
        arr[beg + i] = temp[i];

    free(temp);
}

void merge_sort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, n - 1);

    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
