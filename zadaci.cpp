//Размещение с повторением
#include <iostream>
#include <cmath>
using namespace std;
long long numberOfPlacementWithRepetitions(int n, int k)
{
    return pow(k, n);
}
int main() {
   int a, b;
    cin >> a >> b;
    cout << numberOfPlacementWithRepetitions(a,b);
    return 0;
}

//Размещение без повторения
#include <iostream>
using namespace std;
int fac(int a) {
int s;
if(a==1) return 1;

return fac(a-1) * a;
}
int main() {
    int n, k;
    cin >> n >> k;
    cout << fac(k)/fac((k-n));
    return 0;
}

//Число перестановок
#include <iostream>
using namespace std;

int fac(int a) {
int s;
if(a==1) return 1;

return fac(a-1) * a;
}

int P(int n) {
    return fac(n);
}

int main() {
    unsigned int n;
    cin >> n;
    cout << P(n);
    return 0;
}

//Размещение с повторениями
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    char c1 = s[0];
    char c2 = s[1];
    if (c2 < c1){
        char tmp = c1;
        c1 = c2;
        c2 = tmp;
    }
    cout << c1 << c1 << endl << c1 << c2 << endl << c2 << c1 << endl << c2 << c2; 
        
}

//Размещение с повторениями
#include<iostream>
#include<vector>
using namespace std;


vector <char> sortVector(vector <char> mass){
    int temp;
    for (int i = 0; i < mass.size() - 1; i++) {
        for (int j = 0; j < mass.size() - i - 1; j++) {
            if (mass[j] > mass[j + 1]) {
                temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
    return(mass);
}



int main() {
    vector <char> mass(3);
    string n;
    cin >> n;
    for (int i = 0; i < 3; i++)
        mass[i] = n[i];
    mass = sortVector(mass);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                cout << mass[i] << mass[j] << mass[k] << endl;
            }
        }
    }
}

//Размещение с повторением (базовый)
#include <iostream>
#include <vector>
using namespace std;
void print_lst(vector<int> lst){
    cout << '[';
    for (int i = 0; i < lst.size() - 1; i++){
        cout <<  lst[i] << ',' << ' ';
    }
    cout << lst[lst.size() - 1] << ']' << endl;
}
void next_gen(vector<int> &lst, int k, int n){
    int p = k -1;
    while (lst[p] >=n)
        p--;
    lst[p]++;
    for ( int i = p+1; i <k;i++)
        lst[i] = 1;
}
int main() {
    int n, k;
    cin >> k >> n;
    vector<int> lst_start(k,1);
    vector<int> lst_end(k,n);
    print_lst(lst_start);
    while(lst_start != lst_end){
        next_gen(lst_start, k, n);
        print_lst(lst_start);
        
    }
    return 0;
}

//Размещение с повторением (базовый)
#include <iostream>
#include <vector>
using namespace std;
void print_lst(vector<int> lst){
    for (int i = 0; i < lst.size() - 1; i++){
        cout <<  lst[i] << ' ';
    }
    cout << lst[lst.size() - 1] << endl;
}
void next_gen(vector<int> &lst, int k, int n){
    int p = k -1;
    while (lst[p] >=n)
        p--;
    lst[p]++;
    for ( int i = p+1; i <k;i++)
        lst[i] = 1;
}
int main() {
    int i = 1, r, n, k;
    cin >> r >> k >> n;
    vector<int> lst_start(k,1);
    vector<int> lst_end(k,n);
    while(r != i){
        next_gen(lst_start, k, n);
        i++;
    }
    print_lst(lst_start);
    return 0;
}
