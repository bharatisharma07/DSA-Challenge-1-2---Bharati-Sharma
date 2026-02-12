#include <stdio.h>

// ----------- Bubble Sort Function -----------
void sortArray(int arr[], int size)
{
	int i, j, temp;
	
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ----------- Merge Function -----------
void merge(int nums1[], int m, int nums2[], int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

// ----------- Main Function -----------
int main()
{
    int m, n;
	int i;
	
    printf("Enter number of elements in nums1: ");
    scanf("%d", &m);

    printf("Enter number of elements in nums2: ");
    scanf("%d", &n);

    int nums1[m + n];
    int nums2[n];

    printf("Enter %d elements for nums1:\n", m);
    for (i = 0; i < m; i++)
        scanf("%d", &nums1[i]);

    printf("Enter %d elements for nums2:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &nums2[i]);

    // Step 1: Sort both arrays
    sortArray(nums1, m);
    sortArray(nums2, n);

    // Fill empty space in nums1
    for (i = m; i < m + n; i++)
        nums1[i] = 0;

    // Step 2: Merge arrays
    merge(nums1, m, nums2, n);

    printf("\nFinal Merged Sorted Array:\n");
    for (i = 0; i < m + n; i++)
        printf("%d ", nums1[i]);

    return 0;
}

