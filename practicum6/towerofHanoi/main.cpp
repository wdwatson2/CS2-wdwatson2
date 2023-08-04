#include <iostream>
#include <cmath>

using namespace std;

/*
void towers(int n, int source, int destn, int transfer)
{
    if (n > 1)
        towers(n-1,source,transfer,destn);
    cout << "Move ring " << n << " from peg " << source <<
        " to peg " << destn <<".\n";
    if (n > 1)
        towers(n-1,transfer,destn,source);
}
*/


/*
The goal is to move top n-1 from pega to pegb using pegc. move biggest n from pega to pegc.

then move top n-2 from pegb to pega using pegc. move biggest n from pegb to pegc.
then move top n-3 from pega to peg b using pegc. move biggest n from pega to pegc.
so on and so forth
until 
*/


void printMove(int ring, int fromTower, int toTower)
{
    cout << "Move ring " << ring << " from tower " << fromTower << " to " << toTower << "." << endl;
}

void towersIter(int n)
{
    int fromTower, toTower; //numbers representing towers

    int * ringPos = new int[n]; //creating array to hold the position (what peg) each ring is on
    for(int ring = 0; ring < n; ring++) //initiallizing every position to 1 (first peg)
    {
        ringPos[ring] = 1;
    }

    cout << "Tower with " << n << " rings solved in " << pow(2, n)-1 << " moves." << endl;

    for(int i = 1; i <= pow(2, n)-1; i++)
    {
        for(int j = pow(2,n); j >= 2;)//starting from the highest power of 2
        {
            int currentRing = (int)log2(j);
            if(i%j == j/2)
            {
                //its the log_2(j) rings turn to move
                //two cases:
                //1. total number of rings even implies even rings move forward while odd move backward
                //2. total number of rings odd implies even rings move backwards while odd move forward
                if(n%2 == 0) //total number of rings is even
                {
                    if(currentRing%2 == 0) //even ring
                    {
                        fromTower = ringPos[currentRing-1];
                        //move this ring backwards one
                        if(ringPos[currentRing-1] == 1)//meaning its on peg 1
                        {
                            //must jump to peg3
                            ringPos[currentRing-1] = 3;
                            toTower = ringPos[currentRing-1];
                        }
                        else //its not on peg 1 so just decrement its value 
                        {
                            ringPos[currentRing-1]--;
                            toTower = ringPos[currentRing-1];
                        }

                    }
                    else //odd ring
                    {
                        fromTower = ringPos[currentRing-1];
                        //move this ring forwards one
                        if(ringPos[currentRing-1] == 3)//meaning its on peg3
                        {
                            //must jump to peg1
                            ringPos[currentRing-1] = 1;
                            toTower = ringPos[currentRing-1];
                        }
                        else //its not on peg 1 so just increment its value 
                        {
                            ringPos[currentRing-1]++;
                            toTower = ringPos[currentRing-1];
                        }
                    }
                }
                else //total number of rings is odd
                {
                    if(currentRing%2 == 0) //even ring
                    {
                        fromTower = ringPos[currentRing-1];
                        //move this ring forwards one
                        if(ringPos[currentRing-1] == 3)//meaning its on peg3
                        {
                            //must jump to peg1
                            ringPos[currentRing-1] = 1;
                            toTower = ringPos[currentRing-1];
                        }
                        else //its not on peg 1 so just increment its value 
                        {
                            ringPos[currentRing-1]++;
                            toTower = ringPos[currentRing-1];
                        }
                    }
                    else //odd ring
                    {
                        fromTower = ringPos[currentRing-1];
                        //move this ring backwards one
                        if(ringPos[currentRing-1] == 1)//meaning its on peg 1
                        {
                            //must jump to peg3
                            ringPos[currentRing-1] = 3;
                            toTower = ringPos[currentRing-1];
                        }
                        else //its not on peg 1 so just decrement its value 
                        {
                            ringPos[currentRing-1]--;
                            toTower = ringPos[currentRing-1];
                        }
                    }
                }

                printMove(currentRing, fromTower, toTower);
                break; //move has been made so time to make the next turn

            }
            else
            {
                j = j/2; //divide j by two and check again until right rings move is found
            }
        }
    }

    delete[] ringPos;
    
}

int main()
{
    towersIter(7);
    return 0;
}