#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
string can[50];

int numCandy(){
    int result;
    int tmp;
    result=1;
    for(int i=0;i<N;i++){
        tmp=1;
        for(int j=1;j<N;j++){
            if(can[i][j-1]==can[i][j])
            {
                tmp++;

            }
            else{
                result=max(result,tmp);
                tmp=1;

            }

        }
        result=max(result,tmp);
    }
     for(int i=0;i<N;i++){
                tmp=1;
        for(int j=1;j<N;j++){
            if(can[j-1][i]==can[j][i])
            {
                tmp++;

            }
            else{
                result=max(result,tmp);
                tmp=1;

            }
        }
        result=max(result,tmp);
    }

    return result;
}




int main()
{
    cin >>N;
    int fin;
    fin=1;
    for(int i=0;i<N;i++)
    {
        cin >> can[i];
    }

    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            swap(can[i][j-1],can[i][j]);
            fin=max(fin,numCandy());
            swap(can[i][j-1],can[i][j]);

        }
        for(int j=0;j<N;j++){
            if(i==N-1) break;
            swap(can[i][j],can[i+1][j]);
            fin=max(fin,numCandy());
            swap(can[i][j],can[i+1][j]);

        }
    }
    cout<<fin;

}
