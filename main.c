#include <stdio.h>
#include <time.h>

#define SIZE 10
#define HASH_SIZE 20

int linearSearch(int arr[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[], int low, int high, int key)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            return mid;
        }

        else if(arr[mid] < key)
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

int hashTable[HASH_SIZE];

void initializeHash()
{
    int i;

    for(i = 0; i < HASH_SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

int hashFunction(int key)
{
    return key % HASH_SIZE;
}

void insertHash(int key)
{
    int index = hashFunction(key);

    while(hashTable[index] != -1)
    {
        index = (index + 1) % HASH_SIZE;
    }

    hashTable[index] = key;
}

int searchHash(int key)
{
    int index = hashFunction(key);
    int start = index;

    while(hashTable[index] != -1)
    {
        if(hashTable[index] == key)
        {
            return index;
        }

        index = (index + 1) % HASH_SIZE;

        if(index == start)
        {
            break;
        }
    }

    return -1;
}

int main()
{
    int arr[SIZE] = {2,4,6,8,10,12,14,16,18,20};

    int choice;
    int key;
    int result;

    clock_t time1, time2;

    double linearTime = 0;
    double binaryTime = 0;
    double hashTime = 0;

    initializeHash();

    for(int i = 0; i < SIZE; i++)
    {
        insertHash(arr[i]);
    }

    do
    {
        printf("\n===== SEARCH MENU =====\n");

        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Hashing Search\n");
        printf("4. Compare Time Taken\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 3)
        {
            printf("Enter element to search: ");
            scanf("%d", &key);
        }

        switch(choice)
        {
            case 1:

                time1 = clock();

                result = linearSearch(arr, SIZE, key);

                time2 = clock();

                linearTime =
                ((double)(time2 - time1)) / CLOCKS_PER_SEC;

                if(result != -1)
                {
                    printf("Element found at index %d\n",
                    result);
                }

                else
                {
                    printf("Element not found\n");
                }

                printf("Linear Search Time = %f seconds\n",
                linearTime);

                break;

            case 2:

                time1 = clock();

                result = binarySearch(arr, 0,
                SIZE - 1, key);

                time2 = clock();

                binaryTime =
                ((double)(time2 - time1)) / CLOCKS_PER_SEC;

                if(result != -1)
                {
                    printf("Element found at index %d\n",
                    result);
                }

                else
                {
                    printf("Element not found\n");
                }

                printf("Binary Search Time = %f seconds\n",
                binaryTime);

                break;

            case 3:

                time1 = clock();

                result = searchHash(key);

                time2 = clock();

                hashTime =
                ((double)(time2 - time1)) / CLOCKS_PER_SEC;

                if(result != -1)
                {
                    printf("Element found in hash table at index %d\n",
                    result);
                }

                else
                {
                    printf("Element not found\n");
                }

                printf("Hashing Time = %f seconds\n",
                hashTime);

                break;

            case 4:

                printf("\n===== TIME COMPARISON =====\n");

                printf("Linear Search Time = %f seconds\n",
                linearTime);

                printf("Binary Search Time = %f seconds\n",
                binaryTime);

                printf("Hashing Time = %f seconds\n",
                hashTime);

                if(linearTime < binaryTime &&
                   linearTime < hashTime)
                {
                    printf("Linear Search is fastest\n");
                }

                else if(binaryTime < linearTime &&
                        binaryTime < hashTime)
                {
                    printf("Binary Search is fastest\n");
                }

                else
                {
                    printf("Hashing is fastest\n");
                }

                break;

            case 5:

                printf("Program Ended\n");

                break;

            default:

                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}
