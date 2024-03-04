#include <stdio.h>
#include <stdlib.h>

int* readInput(int* num_count)
{
    int go[1025];
    int input;
    int count = 0;
    int *nums;

    printf(": ");
    for(count = 0; count < 1025; count++)
    {
        scanf("%d", &input);
        if(input == 0)
        {
            break;
        }
        go[count] = input;
    }
    num_count[0] = count;
    nums = (int*)malloc(sizeof(int)*count);

    for(int i = 0; i < count; i++)
    {
        nums[i] = go[i];
    }
    return nums;
}

void printStep(int* nums_, int* pos)
{
    printf("\nStep %d: ", pos[2]+1);
    for(int i = 0; i < pos[0]; i++)
    {
        if(i == pos[1])
        {
            printf("[");
        }
        if(i == pos[2])
        {
            printf("(");
        }
        printf("%d", nums_[i]);
        if(i == pos[2])
        {
            printf(")");
        }
        if (i == pos[1])
        {
            printf("]");
        }
        printf(" ");
    }
}

void selection_sort(int* a, int *pos)
{
    int i, j, k = 0;
    
    for(pos[2] = 0; pos[2] < pos[0]-1; pos[2]++)
    {
        pos[1] = pos[2];
        for(i = pos[2]+1; i < pos[0]; i++)
        {
            k++;
            if(a[i] < a[pos[1]])
            {
                pos[1] = i;
            }
        }
        printStep(a, pos);
        j = a[pos[1]];
        a[pos[1]] = a[pos[2]];
        a[pos[2]] = j;
    }
    pos[3] = k;
}

int main()
{
    int pos[4] = {0};
    int* nums = readInput(pos);
    selection_sort(nums, pos);
    printf("\nResult: ");
    for(int i = 0; i < pos[0]; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("\nNumber of comparisons: %d", pos[3]);
    printf("\nNumber of swaps: %d\n", pos[0]-1);
    free(nums);

    return 0;
}