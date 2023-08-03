// #include "BinaryTree.h"
#include "bSearchTreeType.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>

using namespace std;

// #define DEBUG

const int LOWERBOUND = 100;
const int UPPERBOUND = 100000000;

int main(int argc, char * argv[])
{
#ifdef DEBUG


    bSearchTreeType<int> test;

    //testing isEmpty while empty
    cout << test.isEmpty() << endl;

    //inserting elements into tree
    test.insert(0);
    test.insert(3);
    test.insert(-1);
    test.insert(2);

    //testing isEmpty while not empty
    cout << test.isEmpty() << endl;

    //traversing and displaying elements inorder
    test.inOrderTraverse();
    cout << endl;

    //leaf count
    cout << test.leafCount() << endl;

    //node count
    cout << test.treeNodeCount() << endl;

    //tree height
    cout << test.treeHeight() << endl;

    //testing remove
    test.remove(3);
    test.inOrderTraverse();
    cout << endl;

    test.insert(1);
    test.insert(3);
    test.insert(6);
    test.insert(5);

    test.inOrderTraverse();
    cout << endl;
#endif
    auto start = chrono::high_resolution_clock::now(); //start timer

    bSearchTreeType<long int> numList; //instance of binary search tree class
    long int num;
    srand(9351); //seeding rand with last 4 of 700 number
    for(int i = 0; i < 100000; i++)
    {
        //rand() mod UPPERBOUND is a number between 0 and UPPERBOUND-1. 
        //Adding 1 and LOWERBOUND insures the number is between LOWERBOUND and UPPERBOUND.
        num = rand() % UPPERBOUND + 1 + LOWERBOUND; 
        numList.insert(num); //inserting number into binary search tree
    }

    //collecting users commmand line prompt
    if(argc == 2) //if user does not enter a file name program ends and nothing happens
    {    
        fstream fout;
        fout.open(argv[1], ios::out);
        if(fout.fail())
            exit(1);

        //testing the 11 functions in order

        //EMPTY FUNCTION
        fout << "isEmpty() TEST:" << endl;
        if(numList.isEmpty())
            fout << "Binary Search Tree is empty" << endl << endl;
        else
            fout << "Binary Search Tree is not Empty" << endl << endl;

        //SEARCH FUNCTION
        fout << ".locate(98700) TEST:" << endl;
        if(numList.locate(98700))
            fout << "98,700 is in the Binary Search Tree" << endl<< endl;
        else
            fout << "98,700 is not in the Binary Search Tree" << endl<< endl;

        //INSERT FUNCTION
        fout << ".insert(98700) TEST:" << endl;
        numList.insert(98700);
        fout << "98700 inserted successfuly" << endl << endl;

        //DELETE FUNCTION
        fout << ".remove(98700) TEST:" << endl;
        numList.remove(98700);
        fout << "98700 removed successfully" << endl << endl;

        //HEIGHT FUNCTION
        fout << ".treeHeight() TEST:" << endl;
        fout << "Height: " << numList.treeHeight() << endl<< endl;

        //ELEMENT COUNT FUNCTION
        fout << ".treeNodeCount() TEST: " << endl;
        fout << "Number of Nodes: " << numList.treeNodeCount() << endl << endl;

        //LEAF COUNT FUNCTION
        fout << ".leafCount() TEST:" << endl;
        fout << "Number of leaves: " << numList.leafCount() << endl << endl;

        //INORDER TRAVERSAL
        numList.inOrderTraverse(fout);
        fout << endl<< endl;

        //PREORDER TRAVERSAL
        numList.preOrderTraverse(fout);
        fout << endl<< endl;

        //POSTORDER TRAVERSAL
        numList.postOrderTraverse(fout);
        fout << endl<< endl;

        //COPY FUNCTION
        fout << "COPY CONSTRUCTOR TEST:" << endl;
        bSearchTreeType<long int> copyguy(numList);
        fout << "COPY WAS SUCCESSFUL" << endl << endl;

        numList.~bSearchTreeType();
        copyguy.~bSearchTreeType();

        auto stop = chrono::high_resolution_clock::now();//end timer
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); //find difference 
        long executionTime = duration.count();

        fout << "EXECUTION TIME FOR PROGRAM: "<< executionTime << " microseconds."<<endl;

        fout.close();
    }   


    return 0;
}