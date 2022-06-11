#include <stdio.h>

void mergesort(int arr[], int start_index, int end_index);
void merge(int arr[], int start_index, int mid_index, int end_index);
void printsorted(int arr[], int length);

int main(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int arr_length = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, arr_length - 1);

    printsorted(arr, arr_length);
}

void mergesort(int arr[], int start_index, int end_index)
{
    if (start_index < end_index)
    {
        // Get the mid-point of the array
        int mid_index = start_index + (end_index - 1) / 2;

        // Sort left array
        mergesort(arr, start_index, mid_index);

        // Sort right array
        mergesort(arr, mid_index + 1, end_index);

        // Merge sorted halves
        merge(arr, start_index, mid_index, end_index);
    }

}

void merge(int arr[], int start_index, int mid_index, int end_index)
{
    // Compute length of left and right arrays
    int left_length = mid_index - start_index + 1;
    int right_length = end_index - mid_index;

    // Initialize left and right arrays
    int left[left_length];
    int right[right_length];

    for (int i = 0; i < left_length; i++)
    {
        left[i] = arr[start_index + i];
    }

    for (int i = 0; i < right_length; i++)
    {
        right[i] = arr[mid_index + 1 + i];
    }

    // Keep track of indices for left, right and combined arrays
    int left_index = 0;
    int right_index = 0;
    int arr_index = start_index;

    // Compare corresponding elements in the left and right arrays,
    // picking whichever is smaller
    while (left_index < left_length && right_index < right_length)
    {
        if (left[left_index] <= right[right_index])
        {
            arr[arr_index] = left[left_index];
            left_index++;
        }
        else
        {
            arr[arr_index] = right[right_index];
            right_index++;
        }
        arr_index++;
    }

    // Add the leftover elements of the left and right arrays to the combined array
    while (left_index < left_length)
    {
        arr[arr_index] = left[left_index];
        left_index++;
        arr_index++;
    }

    while (right_index < right_length)
    {
        arr[arr_index] = right[right_index];
        right_index++;
        arr_index++;
    }
}

void printsorted(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}