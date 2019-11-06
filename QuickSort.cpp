#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &,int,int);
void QS(vector<int> &,int,int); // QS -> QuickSort

int main(int argc, char const *argv[])
{
    vector<int> input_list;
    int input;
    while((cin >> input) && input!='\n')
    {
	input_list.push_back(input);
    }
    QS(input_list,0,input_list.size()-1);
    
    for(auto i=input_list.begin(); i!=input_list.end(); i++)
        cout << *i << endl;
    return 0;
}

//put element at A[end] into its appropriate place, and return that index
//An element is at its appropriate position if all values to its left are smaller
//and all elements to right of it are larger
int partition(vector<int> &A,int start,int end)
{
    int i=start-1, j=start, temp;
    
    if (start>=end) {
        return end;                         // No partitioning possible (end is the correct pos of last element)
    }
    while(j<end)
    {
        if(A[j]<=A[end])
        {
            temp = A[++i];
            A[i]=A[j];
            A[j]=temp;
        }
        j++;
    }
    temp = A[++i];
    A[i]=A[end];
    A[end]=temp;
    
    return i;
    
}

void QS(vector<int> &A,int start,int end)
{
    if(start<end)
    {
        int pos = partition(A,start,end);
        QS(A,start,pos-1);
        QS(A,pos+1,end);
    }
}

//See QuickSort By RavindraBabu on YouTube