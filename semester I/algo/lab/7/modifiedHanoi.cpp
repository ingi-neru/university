// Laszlo Kazmer
// 512
// Lab7/6
// Adott a Hanoi-tornyok feladata, ahol az 1-es rúdról kell a 3-as rúdra át- pakoljunk 𝑛 korongot, a 2-es rúd segítségével.
// Oldjuk meg a feladatot abban az esetben, ha a 2-es és 3-as rudak között nem szabad korongot mozgatni, vagyis minden mozgatásban szerepelnie kell az 1-es rúdnak.
#include<iostream>
using namespace std;

void tower_of_hanoi(long num, string source, string dest, string helper) {
    if ( (source != "2" || dest != "3") && (source != "3" || dest != "2") ){
    if (num == 1) {
    cout << source << " " << dest << endl;
    return;
    }
    tower_of_hanoi(num - 1, source, helper, dest);
    cout << source << " " << dest << endl;
    tower_of_hanoi(num - 1, helper, dest, source);
    }
    else{
        cout << source << " 1" << endl;
        tower_of_hanoi(num, helper, dest, source);
    }
}
int main() {
  long num;
  cin >> num;
  tower_of_hanoi(num, "1", "3", "2");
  return 0;
}
