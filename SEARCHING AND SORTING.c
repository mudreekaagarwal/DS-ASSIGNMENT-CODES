#include <stdio.h>

struct Flower
{
    char name[20];
    char colour[20];
    int price;
    int quantity;
};

void display(struct Flower f[], int n)
{
    int i;

    printf("\nName\tColour\tPrice\tQuantity\n");

    for(i = 0; i < n; i++)
    {
        printf("%s\t%s\t%d\t%d\n",
               f[i].name,
               f[i].colour,
               f[i].price,
               f[i].quantity);
    }
}


void bubbleSort(struct Flower f[], int n)
{
    int i, j;
    struct Flower temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(f[j].price > f[j + 1].price)
            {
                temp = f[j];
                f[j] = f[j + 1];
                f[j + 1] = temp;
            }
        }
    }
}


void insertionSort(struct Flower f[], int n)
{
    int i, j;
    struct Flower temp;

    for(i = 1; i < n; i++)
    {
        temp = f[i];
        j = i - 1;

        while(j >= 0 && f[j].price > temp.price)
        {
            f[j + 1] = f[j];
            j--;
        }

        f[j + 1] = temp;
    }
}


void selectionSort(struct Flower f[], int n)
{
    int i, j, min;
    struct Flower temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(f[j].price < f[min].price)
            {
                min = j;
            }
        }

        temp = f[i];
        f[i] = f[min];
        f[min] = temp;
    }
}


void merge(struct Flower f[], int low, int mid, int high)
{
    struct Flower temp[50];

    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high)
    {
        if(f[i].price < f[j].price)
        {
            temp[k] = f[i];
            i++;
        }
        else
        {
            temp[k] = f[j];
            j++;
        }

        k++;
    }

    while(i <= mid)
    {
        temp[k] = f[i];
        i++;
        k++;
    }

    while(j <= high)
    {
        temp[k] = f[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++)
    {
        f[i] = temp[i];
    }
}


void mergeSort(struct Flower f[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(f, low, mid);
        mergeSort(f, mid + 1, high);

        merge(f, low, mid, high);
    }
}


/* SHELL SORT ADDED HERE */

void shellSort(struct Flower f[], int n)
{
    int gap, i, j;
    struct Flower temp;

    for(gap = n / 2; gap > 0; gap = gap / 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = f[i];
            j = i;

            while(j >= gap && f[j - gap].price > temp.price)
            {
                f[j] = f[j - gap];
                j = j - gap;
            }

            f[j] = temp;
        }
    }
}


int binarySearch(struct Flower f[], int n, int price)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(f[mid].price == price)
        {
            return mid;
        }
        else if(f[mid].price < price)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}


int recursiveBinarySearch(struct Flower f[],
                          int low, int high, int price)
{
    int mid;

    if(low > high)
    {
        return -1;
    }

    mid = (low + high) / 2;

    if(f[mid].price == price)
    {
        return mid;
    }
    else if(price < f[mid].price)
    {
        return recursiveBinarySearch(f, low, mid - 1, price);
    }
    else
    {
        return recursiveBinarySearch(f, mid + 1, high, price);
    }
}


int main()
{
    struct Flower f[50];

    int n, i;
    int choice;
    int price;
    int result;

    printf("Enter number of flowers: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Flower %d\n", i + 1);

        printf("Name: ");
        scanf("%s", f[i].name);

        printf("Colour: ");
        scanf("%s", f[i].colour);

        printf("Price: ");
        scanf("%d", &f[i].price);

        printf("Quantity: ");
        scanf("%d", &f[i].quantity);
    }


    do
    {
        printf("\n\n===== FLOWER MENU =====");
        printf("\n1. Exit");
        printf("\n2. Bubble Sort");
        printf("\n3. Insertion Sort");
        printf("\n4. Selection Sort");
        printf("\n5. Merge Sort");
        printf("\n6. Shell Sort");
        printf("\n7. Binary Search");
        printf("\n8. Recursive Binary Search");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nProgram Exited.");
                break;


            case 2:
                bubbleSort(f, n);

                printf("\nAfter Bubble Sort:");
                display(f, n);
                break;


            case 3:
                insertionSort(f, n);

                printf("\nAfter Insertion Sort:");
                display(f, n);
                break;


            case 4:
                selectionSort(f, n);

                printf("\nAfter Selection Sort:");
                display(f, n);
                break;


            case 5:
                mergeSort(f, 0, n - 1);

                printf("\nAfter Merge Sort:");
                display(f, n);
                break;


            case 6:
                shellSort(f, n);

                printf("\nAfter Shell Sort:");
                display(f, n);
                break;


            case 7:

                mergeSort(f, 0, n - 1);

                printf("\nEnter price to search: ");
                scanf("%d", &price);

                result = binarySearch(f, n, price);

                if(result != -1)
                {
                    printf("\nFlower Found!");
                    printf("\nName: %s", f[result].name);
                    printf("\nColour: %s", f[result].colour);
                    printf("\nPrice: %d", f[result].price);
                    printf("\nQuantity: %d", f[result].quantity);
                }
                else
                {
                    printf("\nFlower Not Found.");
                }

                break;


            case 8:

                mergeSort(f, 0, n - 1);

                printf("\nEnter price to search: ");
                scanf("%d", &price);

                result = recursiveBinarySearch(
                    f, 0, n - 1, price
                );

                if(result != -1)
                {
                    printf("\nFlower Found!");
                    printf("\nName: %s", f[result].name);
                    printf("\nColour: %s", f[result].colour);
                    printf("\nPrice: %d", f[result].price);
                    printf("\nQuantity: %d", f[result].quantity);
                }
                else
                {
                    printf("\nFlower Not Found.");
                }

                break;


            default:
                printf("\nInvalid Choice!");
        }

    } while(choice != 1);

    return 0;
}