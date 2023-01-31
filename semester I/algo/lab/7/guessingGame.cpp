// Laszlo Kazmer
// 512
// Lab7/1
// Legyen a következő játék: az egyik játékos (Játékos1) gondol egy 1 és 1000 közötti természetes számra.
// A másik játékosnak (Játékos2) ki kell találnia ezt a számot minél kevesebb próbálgatással. 
// A titkos szám „birtokosa” (Játékos1) egy-egy találgatásra csak annyit válaszol, hogy a titkos szám kisebb vagy nagyobb mint a másik játékos (Játékos2) által feltételezett szám.
// Írjunk programot amely a fenti játékot szimulálja, úgy, hogy a programunk a Játékos2, azaz ő találja ki a felhasználó titkos számát.
#include <iostream>
using namespace std;

void takeAGuess ( long guess, long tries, long first, long last ){
    if ( tries <= 10 && guess ){
        long middle = ( first + last ) / 2;
        cout << middle << endl << endl;
        cin >> guess;
        cout << endl;
        if ( guess == -1 ) takeAGuess(guess, tries + 1, first, middle - 1);
        else takeAGuess(guess, tries + 1, middle + 1, last);
    }
}

int main()
{
    takeAGuess(1, 1, 1, 1000);
    return 0;
}