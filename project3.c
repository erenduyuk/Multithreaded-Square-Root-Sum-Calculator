// import libraries
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// Declare global variables
double global_sqrt_sum = 0;

long long int a;
long long int b;
int threadNumber;
int method;

// Declare mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void calculateSqrtSum(long long int a, long long int b);

// Method 1
void *threadFunction1(void *arg)
{
    long long int x;
    int threadID = *((int *)arg);
    // Split the range into equal parts
    long long int start = a + (b - a) * threadID / threadNumber;
    long long int end = a + (b - a) * (threadID + 1) / threadNumber - 1;

    // Calculate the sqrt sum
    for (x = start; x <= end; x++)
    {
        global_sqrt_sum += sqrt(x);
    }
    pthread_exit(NULL);
}

// Method 2
void *threadFunction2(void *arg)
{
    long long int x;
    int threadID = *((int *)arg);
    // Split the range into equal parts
    long long int start = a + (b - a) * threadID / threadNumber;
    long long int end = a + (b - a) * (threadID + 1) / threadNumber - 1;

    // Calculate the sqrt sum
    for (x = start; x <= end; x++)
    {
        pthread_mutex_lock(&mutex); // Lock the mutex
        global_sqrt_sum += sqrt(x);
        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }
    pthread_exit(NULL);
}

// Method 3
void *threadFunction3(void *arg)
{
    long long int x;
    double local_sqrt_sum = 0;
    int threadID = *((int *)arg);
    // Split the range into equal parts
    long long int start = a + (b - a) * threadID / threadNumber;
    long long int end = a + (b - a) * (threadID + 1) / threadNumber - 1;

    // Calculate the sqrt sum
    for (x = start; x <= end; x++)
    {
        local_sqrt_sum += sqrt(x);
    }

    pthread_mutex_lock(&mutex); // Lock the mutex
    global_sqrt_sum += local_sqrt_sum;
    pthread_mutex_unlock(&mutex);   // Unlock the mutex

    pthread_exit(NULL);
}

void main(int argc, char *argv[])
{

    // Check if the number of arguments is correct
    if (argc != 5)
    {
        printf("Invalid number of arguments\n");
        exit(0);
    }

    // Assign the arguments to variables
    a = atoll(argv[1]);
    b = atoll(argv[2]);
    threadNumber = atoi(argv[3]);
    method = atoi(argv[4]);


    pthread_t threads[threadNumber];
    int threadsIDs[threadNumber];

    // Determine which method to use
    if (method == 1)
    {
        // Create threads
        int i;
        for (i = 0; i < threadNumber; i++)
        {
            threadsIDs[i] = i;
            pthread_create(&threads[i], NULL, threadFunction1, &threadsIDs[i]);
        }
    }
    else if (method == 2)
    {
        // Create threads
        int i;
        for (i = 0; i < threadNumber; i++)
        {
            threadsIDs[i] = i;
            pthread_create(&threads[i], NULL, threadFunction2, &threadsIDs[i]);
        }
    }
    else if (method == 3)
    {
        // Create threads
        int i;
        for (i = 0; i < threadNumber; i++)
        {
            threadsIDs[i] = i;
            pthread_create(&threads[i], NULL, threadFunction3, &threadsIDs[i]);
        }
    }

    // Wait for all threads to finish
    int i;
    for (i = 0; i < threadNumber; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Start Range: %lld\n", a);
    printf("End Range: %lld\n", b);
    printf("Thread Number: %d\n", threadNumber);
    printf("Method: %d\n", method);
    printf("Global Sqrt Sum: %.5e\n", global_sqrt_sum);

    pthread_mutex_destroy(&mutex); // Destroy the mutex
}
