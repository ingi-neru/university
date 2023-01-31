#include<iostream>
using namespace std;
    double topFour[5];
    long indexes[5];
void in ( long &n, string athletes[], double start_time[], double relay_time[] ){
    cin >> n;
    for( long i = 1; i <= n; i++ ){
        cin >> athletes[i] >> start_time[i] >> relay_time[i];    
    }
}

void minselection ( long n, double relay_time[], bool selected[], double minim, long j ){
    long index = 1;
    while ( selected[index] ) index++;
    minim = relay_time[index];
    
    for ( int i = 2; i <= n ;i++ ){
        if ( minim > relay_time[i] && !selected[i] ) {
            minim = relay_time[i];
            index = i;
        }
    }
    selected[index] = true;
    topFour[j] = minim;
    indexes[j] = index;
}

double calculateTime ( bool selected[], long j, double sum ){
    long num = 0;
        for ( long i = 1; i <= 4 && num < 3; i++ ){
            if ( indexes[i] != j ){
                sum += topFour[i];
                num++;
            }
        }
    return sum;
}

void outputTopFour ( string athletes[], long index, string topStarter ){
    long num = 1;
    for ( long i = 1; i <= 4 && num < 4; i++ ){
        if ( athletes[indexes[i]] != topStarter ){
            cout << athletes[indexes[i]] << endl;
            num++;
        }
    }
}

void selectTopFour ( long n, string athletes[], double start_time[], double relay_time[], bool selected[] ){
    double solution = 10000000;
    long index;
    for ( long i = 1; i <= 4; i++ ){
        minselection(n, relay_time, selected, 0, i);
    }
    string topStarter;
    for ( long i = 1; i <= n; i++ ){
        double sum = start_time[i];
        sum = calculateTime(selected, i, sum);
        if ( solution > sum ){
            solution = sum;
            topStarter = athletes[i];
            index = i;
        }
    }
    cout << solution << endl << topStarter << endl; 
    outputTopFour(athletes, index, topStarter);
}



int main(){
    long n;
    bool selected[501];
    string athletes[501];
    double start_time[501], relay_time[501];
    in(n, athletes, start_time, relay_time);
    selectTopFour(n, athletes, start_time, relay_time, selected);
    cout << endl;

    return 0;
}