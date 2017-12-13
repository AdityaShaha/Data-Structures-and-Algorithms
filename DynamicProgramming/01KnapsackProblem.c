#include<stdio.h>
#include<stdlib.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

struct Knapsack{
    int value;
    int weight;
};

int main()
{
    int numberOfItems,maxWeight,i,j;
    printf("Enter the number of items\n");
    scanf("%d",&numberOfItems);
    printf("Enter the max weight of the sack\n");
    scanf("%d",&maxWeight);
    struct Knapsack Sack[numberOfItems+1];
    printf("Enter the value and the weight of the items\n");
    for(i=1;i<numberOfItems+1;i++){
        scanf("%d",&Sack[i].value);
        scanf("%d",&Sack[i].weight);
    }
    for(i=1;i<numberOfItems+1;i++){
        printf(" %d ",Sack[i].value);
    }
    printf("\n");
    for(i=1;i<numberOfItems+1;i++){
        printf(" %d ",Sack[i].weight);
    }
    printf("\n");
    int SackMatrix[numberOfItems+1][maxWeight+1];

    for(i=0;i<numberOfItems+1;i++){
        for(j=0;j<maxWeight+1;j++){
            if(i==0 || j==0){
                SackMatrix[i][j]=0;
            }else if(Sack[i].weight>j){
                SackMatrix[i][j] = SackMatrix[i-1][j];

            }else{
                SackMatrix[i][j] = MAX(Sack[i].value + SackMatrix[i-1][j-Sack[i].weight],SackMatrix[i-1][j]);
            }
        }
    }
    for(i=0;i<numberOfItems+1;i++){
        for(j=0;j<maxWeight+1;j++){
            printf("  %d  ",SackMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
