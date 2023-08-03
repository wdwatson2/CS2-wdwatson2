#include <iostream>
#include <iomanip>
#include <random>
#include <fstream>
#include <chrono>
#include "bubbleSort.h"
#include "insertionSort.h"
#include "quickSort.h"
#include "kthSmallest.h"

using namespace std;

// #define DEBUG

const double RANDNUM_MAX = 937017.0;
const double RANDNUM_MIN = 237.0;

const int LISTSIZE = 50000;
int main(int argc, char *argv[])
{   
#ifdef DEBUG
    double * test = new double[] {8,1,6,5,4,3,2,7, -4};

    cout << kthSmallestElement(test, 0, 8, 1) << endl;
#endif


    fstream fileError;
    fileError.open("ERROR-LOG.txt", ios::out);
    streambuf* stream_buffer_ERRORLOG = fileError.rdbuf();
    streambuf* stream_buffer_cout = cout.rdbuf();

    cout.rdbuf(stream_buffer_ERRORLOG);
    try{
    long executionTime = 0;
    //generating lists of random doubles
    double * list1 = new double[LISTSIZE];
    double * list2 = new double[LISTSIZE];
    double * list3 = new double[LISTSIZE];
    double * list4 = new double[LISTSIZE];
    double * list5 = new double[LISTSIZE];
    double * list6 = new double[LISTSIZE];


    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> dis(RANDNUM_MIN, RANDNUM_MAX);
    for (int n = 0; n < LISTSIZE; n++) {
        // Use dis to transform the random unsigned int generated by gen into a 
        // double in [1, 2). Each call to dis(gen) generates a new random double
        double f = dis(gen);
        list1[n] = f;
        list2[n] = f;
        list3[n] = f;
        list4[n] = f;
        list5[n] = f;
        list6[n] = f;
    }

//===================================================================================================
    fstream file, file1, file2, file3;
    file.open("OriginalData.txt", ios::out);
    file1.open("QuickSort.txt", ios::out);
    file3.open("BubbleSort.txt", ios::out);
    file2.open("InsertionSort.txt", ios::out);


    streambuf* stream_buffer_cerr = cerr.rdbuf();
    streambuf* stream_buffer_Original = file.rdbuf();
    streambuf* stream_buffer_QuickSort = file1.rdbuf();
    streambuf* stream_buffer_InsertionSort = file2.rdbuf();
    streambuf* stream_buffer_BubbleSort = file3.rdbuf();

    cerr.rdbuf(stream_buffer_Original);

    for(int i = 0; i < LISTSIZE; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cerr << list1[i] << '\t';
            i++;
        }
        cerr << list1[i] << endl;
    }
    file.close();

//===================================================================================================

    //All QuickSort Variants

    auto start = chrono::high_resolution_clock::now(); //start timer

    quickSortMedian(list1,0,LISTSIZE-1,true);

    auto stop = chrono::high_resolution_clock::now();//end timer
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); //find difference 
    executionTime = duration.count();

    cerr.rdbuf(stream_buffer_QuickSort);

    for(int i = 0; i < LISTSIZE; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cerr << list1[i] << '\t';
            i++;
        }
        cerr << list1[i] << endl;
    }

    delete[] list1;
    cerr << endl;
    cerr << "Quick Sort - Median as Pivot" << endl;
    cerr << "Execution Time: " << executionTime << " microseconds" << endl;
    cerr << "Number of Comparisons: " << numComparisonsQuickSort << endl;
    cerr << "Number of Exchanges: " << numExchangesQuickSort << endl << endl;
    numComparisonsQuickSort=0;
    numExchangesQuickSort=0;


    start = chrono::high_resolution_clock::now(); //start timer

    quickSortMedianInsertionSort(list2,0,LISTSIZE-1,true);

    stop = chrono::high_resolution_clock::now();//end timer
    duration = chrono::duration_cast<chrono::microseconds>(stop - start); //find difference 
    executionTime = duration.count();

    for(int i = 0; i < LISTSIZE; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cerr << list2[i] << '\t';
            i++;
        }
        cerr << list2[i] << endl;
    }
    delete[] list2;
    cerr << endl;
    cerr << "Quick Sort Insertion Sort Hybrid - Median as Pivot with Insertion Sort" << endl;
    cerr << "Execution Time: " << executionTime << " microseconds" << endl;
    cerr << "Number of Comparisons: " << numComparisonsQuickSort << endl;
    cerr << "Number of Exchanges: " << numExchangesQuickSort << endl << endl;
    numComparisonsQuickSort=0;
    numExchangesQuickSort=0;


    start = chrono::high_resolution_clock::now(); //start timer

    quickSortMiddle(list3,0,LISTSIZE-1,true);

    stop = chrono::high_resolution_clock::now();//end timer
    duration = chrono::duration_cast<chrono::microseconds>(stop - start); //find difference 
    executionTime = duration.count();

    for(int i = 0; i < LISTSIZE; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cerr << list3[i] << '\t';
            i++;
        }
        cerr << list3[i] << endl;
    }
    delete[] list3;
    cerr << endl;
    cerr << "Quick Sort - Middle as pivot" << endl;
    cerr << "Execution Time: " << executionTime << " microseconds" << endl;
    cerr << "Number of Comparisons: " << numComparisonsQuickSort << endl;
    cerr << "Number of Exchanges: " << numExchangesQuickSort << endl << endl;
    numComparisonsQuickSort=0;
    numExchangesQuickSort=0;


    start = chrono::high_resolution_clock::now(); //start timer

    quickSortMiddleInsertionSort(list4,0,LISTSIZE-1,true);

    stop = chrono::high_resolution_clock::now();//end timer
    duration = chrono::duration_cast<chrono::microseconds>(stop - start); //find difference 
    executionTime = duration.count();

    for(int i = 0; i < LISTSIZE; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cerr << list4[i] << '\t';
            i++;
        }
        cerr << list4[i] << endl;
    }
    delete[] list4;
    cerr << endl;
    cerr << "Quick Sort Insertion Sort Hybrid - Middle as Pivot with Insertion Sort" << endl;
    cerr << "Execution Time: " << executionTime << " microseconds" << endl;
    cerr << "Number of Comparisons: " << numComparisonsQuickSort << endl;
    cerr << "Number of Exchanges: " << numExchangesQuickSort << endl << endl;

    cerr.rdbuf(stream_buffer_cerr); 
    file1.close();

//===============================================================================================

    //Insertion Sort
    cerr.rdbuf(stream_buffer_InsertionSort);

    start = chrono::high_resolution_clock::now(); //start timer

    insertionSort(list5,0,LISTSIZE-1);

    stop = chrono::high_resolution_clock::now();//end timer
    duration = chrono::duration_cast<chrono::microseconds>(stop - start); //find difference 
    executionTime = duration.count();

    for(int i = 0; i < LISTSIZE; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cerr << list5[i] << '\t';
            i++;
        }
        cerr << list5[i] << endl;
    }
    delete[] list5;
    cerr << endl;
    cerr << "Insertion Sort" << endl;
    cerr << "Execution Time: " << executionTime << " microseconds" << endl;
    cerr << "Number of Comparisons: " << numComparisonsQuickSort << endl;
    cerr << "Number of Exchanges: " << numExchangesQuickSort << endl << endl;

    cerr.rdbuf(stream_buffer_cerr); 
    file2.close();
//=============================================================================================

    //Bubble Sort
    cerr.rdbuf(stream_buffer_BubbleSort);

    start = chrono::high_resolution_clock::now(); //start timer

    bubbleSort(list6, LISTSIZE);

    stop = chrono::high_resolution_clock::now();//end timer
    duration = chrono::duration_cast<chrono::microseconds>(stop - start); //find difference 
    executionTime = duration.count();

    for(int i = 0; i < LISTSIZE; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cerr << list6[i] << '\t';
            i++;
        }
        cerr << list6[i] << endl;
    }
    cerr << endl;
    cerr << "Bubble Sort" << endl;
    cerr << "Execution Time: " << executionTime << " microseconds" << endl;
    cerr << "Number of Comparisons: " << numComparisonsQuickSort << endl;
    cerr << "Number of Exchanges: " << numExchangesQuickSort << endl << endl;

    cerr.rdbuf(stream_buffer_cerr); 
    file3.close();
//============================================================================================================
    //kth smallest element
    if(argc == 2)
    {
        //command line prompt was given
        if(atoi(argv[1]) <= 0 || atoi(argv[1]) >= 50000)
            throw invalid_argument("Not a valid kth smallest value. KthSmallestElement.txt will not have anything in it.");
        else
        {
        fstream file4;
        file4.open("KthSmallestElement.txt", ios::out);
        streambuf* stream_buffer_KthSmallest = file4.rdbuf();
        cerr.rdbuf(stream_buffer_KthSmallest);

        cerr << "The " << atoi(argv[1]) << "th smallest element in the list is: " << kthSmallestElement(list6, 0, LISTSIZE-1, atoi(argv[1])) << endl;

        cerr.rdbuf(stream_buffer_cerr);
        file4.close();
        }
    }
    delete[] list6;
    }   
    catch(bad_alloc & ba)
    {
        cout << ba.what() << endl;
    }
    catch(invalid_argument & ia)
    {
        cout << ia.what() << endl;
    }
    catch(...)
    {
        cout << "More errors occured" << endl;
    }
    cout.rdbuf(stream_buffer_cout);
    fileError.close();
    return 0;
}