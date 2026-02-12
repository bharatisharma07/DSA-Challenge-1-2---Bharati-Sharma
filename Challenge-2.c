#include <stdio.h>

#define SIZE 100000
#define MAXN 10000   

int value[SIZE];
int index[SIZE];

// reset hash table
void reset()
{
    int i;
    for(i = 0; i < SIZE; i++)
        value[i] = -1;
}

// hash function
int hash(int num)
{
    if(num < 0) num = -num;
    return num % SIZE;
}

// main logic
void twosum(int numbers[], int n, int target)
{
    int i;
    reset();
    
    for(i = 0; i < n; i++)
    {
        int need = target - numbers[i];
        int pos = hash(need);

        if(value[pos] != -1 && numbers[index[pos]] == need)
        {
            printf("\nIndices found: [%d, %d]", index[pos], i);
            return;
        }

        int pos2 = hash(numbers[i]);
        value[pos2] = numbers[i];
        index[pos2] = i;
    }
}

int main()
{
    int n, target;
    int numbers[MAXN];   
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    twosum(numbers, n, target);

    return 0;
}

