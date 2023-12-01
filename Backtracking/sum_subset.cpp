#include <stdio.h>
void generateSubsetsAndSum(int inputSet[], int subset[], int n, int index, int targetSum) {
    
    if (index == n) {
        // Check if the current subset sums to the targetSum
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (subset[i]) {
                sum += inputSet[i];
            }
        }
        
        if (sum == targetSum) {
            // Process the subset here (e.g., print or use it)
            printf("Subset: ");
            for (int i = 0; i < n; i++) {
                if (subset[i]) {
                    printf("%d ", inputSet[i]);
                }
            }
            printf("Sum: %d\n", targetSum);
        }
        return;
    }

    // Include the current element in the subset
    subset[index] = 1;
    generateSubsetsAndSum(inputSet, subset, n, index + 1, targetSum);

    // Exclude the current element from the subset
    subset[index] = 0;
    generateSubsetsAndSum(inputSet, subset, n, index + 1, targetSum);
}


void generate(int input[] , int subset[], int n , int index , int target)
{
    if(index == n)
    {
        int sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(subset[i])
            {
                sum = sum + input[i];
            }
        }

        if(sum == target)
        {
            printf("Subset \n");
            for(int i=0 ; i<n ; i++)
            {
                if(subset[i])
                printf("%d ",input[i]);
            }
            printf("Sum : %d ",target);
        }
        return ;
    }

    subset[index] = 1;
    generate(input,subset,n,index+1,target);

    subset[index] = 0;
    generate(input,subset,n,index+1,target);
}



int main() {
    int inputSet[] = {1, 2, 3, 4 };
    int n = sizeof(inputSet)/ sizeof(inputSet[0]);
    int subset[n];
    int targetSum = 5; // Change this to the desired target sum

    generateSubsetsAndSum(inputSet, subset, n, 0, targetSum);

    printf("My try\n");
    generate(inputSet , subset , n , 0 , targetSum);

    return 0;
}
