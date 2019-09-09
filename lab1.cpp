/******************************************************************

  CIS 22B

    Lab1: This program reads an input file containing test scores
          and prints the final scores sorted ascendingly, the
          class average and the class median.

  Author: Ryan Chan Kin Hon

  Date:01/10/2019

*******************************************************************/

#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

const int numScores = 10;

void printInfo(void);
void readScores(ifstream &inFile, vector<int> &scores);
double calcAverage(const vector<int> scores);
double calcMedian(const vector<int> scores);
void printResults(const vector<int> scores, double average, double median);

int main(){
    double average, median;
    vector<int> scores;
    ifstream inFile;

    // Print welcome message
    printInfo();

    // Calculate final scores and read them into vector
    readScores(inFile, scores);

    // Sort the vector
    sort(scores.begin(), scores.end());

    // Calculate the average of the scores
    average = calcAverage(scores);

    // Calculate the average of the scores
    median = calcMedian(scores);

    // Display scores, average and median
    printResults(scores, average, median);

    return 0;
}

/******************************************************************
This function welcomes the user and prints
the purpose of this program.
*******************************************************************/
void printInfo()
{
    cout << "Welcome! I can sort your test scores ascendingly \n"
         << "and calculate the class average and class median.\n\n";
}

/******************************************************************
This function reads the scores from the input file, calculates
the average score of each student and reads them into a vector.
*******************************************************************/
void readScores(ifstream &inFile, vector<int> &scores)
{
    string fileName;
    bool failed;
    // Prompt user for input file name + validate
    do
    {
        cout << "Please input file name: ";
        cin >> fileName;
        inFile.open(fileName.c_str());
        if (inFile.fail())
        {
            cout << "Input file open failure! Try again.\n\n";
            failed=true;
        }
        else failed=false;
    } while(failed);
    int score;

    while(inFile)
    {
        int sum=0, n=numScores;
        double avg;
        bool isEndOfFile = false;
        while(n--)
        {
            inFile >> score;
            if(inFile.eof()){
              isEndOfFile = true;
              n = 0;
              break;
            }
            cout << score << ' ';
            sum+=score;

        }
        if(!isEndOfFile){
          avg = sum/numScores;
          cout << "\t" << avg << endl;
          scores.push_back(avg);
        }


    }
    inFile.close();
}

/******************************************************************
This function takes a vector of scores as an argument and
calculates the average test score.
*******************************************************************/
double calcAverage(const vector<int> scores)
{
    double total=0, average;
    for(int n:scores)
        total+=n;
    average = total/scores.size();
    return average;
}

/******************************************************************
This function takes a vector of scores as an argument and
calculates the median of the test scores.
*******************************************************************/
double calcMedian(const vector<int> scores)
{
    double median;
    if(scores.size()%2 ==0)
    {
        median = (scores[scores.size()/2 -1] + scores[scores.size()/2])/2;
    }
    else
        median = scores[scores.size()/2];
    return median;
}


/******************************************************************
This function takes a vector of scores as an argument and
calculates the median of the test scores.
*******************************************************************/
void printResults(const vector<int> scores, double average, double median)
{
    cout << "\nScores: ";
    for(int i:scores)
        cout << i << ", ";
    cout << "\nAverage: " << average;
    cout << "\nMedian: " << median;
    cout << "\n\n\t ~~*~~ The END ~~*~~\n";
}

/********************* OUTPUT ***********************

Welcome! I can sort your test scores ascendingly
and calculate the class average and class median.

Please input file name: lab1.txt

Scores: 66, 71, 73, 78, 81, 82, 84, 86, 91, 93, 95,
Average: 81.8182
Median: 82

         ~~*~~ The END ~~*~~

Process returned 0 (0x0)   execution time : 3.007 s
Press any key to continue.

*****************************************************/
