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

//Сочетание (базовый)
#include <iostream> 
#include <vector> 
#include <string> 
using namespace std; 
 
int len(string str){ 
    int len = 0; 
    for(int i = 0; str[i] != '\0'; i++){ 
        len++; 
    } 
    return len; 
} 
 
void print(const vector<char> &mass){ 
    cout << "["; 
    for(int i = 0; i < mass.size(); i++){ 
        if(i != mass.size() - 1){ 
            cout << mass[i] << ", "; 
        } 
        else{ 
            cout << mass[i]; 
        } 
    } 
    cout << "]"; 
} 
 
void re_zero(vector<char> &mass, vector<char> &mass2, int len, char max, char min){ 
    int p = len - 1, count = 0; 
    while(mass[p] == max or mass[p - 1] >= max){ 
        p--; 
    } 
    for(int i = 0; i < mass2.size(); i++){ 
        if(mass[p] < mass2[i] and count == 0 and i + 1 <= mass2.size()){ 
            mass[p] = mass2[i]; 
            mass[p + 1] = mass2[i + 1]; 
            count++; 
        } 
    } 
} 
 
bool check(vector<char> &mass){ 
    int count = 0; 
    for(int i = 0; i < mass.size(); i++){ 
        for(int j = 0; j < mass.size(); j++){ 
            if(mass[i] == mass[j] and j != i){ 
                count++; 
            } 
        } 
        if(mass[i] == NULL){ 
            count++; 
        } 
        if(mass[i] > mass[i + 1] and i + 1 < mass.size()){ 
            count++; 
        } 
    } 
    if(count == 0){ 
        return true; 
    } 
    return false; 
} 
 
void sortv(vector<char> &mass){ 
    char point; 
    int count = mass.size(); 
    for(int i = 0; i < count - 1; i++){ 
        for(int j = 0; j < count - 1 - i; j++){ 
            if(mass[j] > mass[j + 1]){ 
                point = mass[j]; 
                mass[j] = mass[j + 1]; 
                mass[j + 1] = point; 
            } 
        } 
    } 
} 
 
string itc_ToString(int num){ 
    string res = "", result = ""; 
    int point; 
    if(num == 0){ 
        return "0"; 
    } 
    while(num > 0){ 
        point = num % 10; 
        res += '0' + point; 
        num = num / 10; 
    } 
    for(int i = len(res) - 1; i >= 0; i--){ 
        result += res[i]; 
    } 
    return result; 
} 
 
int main() { 
    vector<char> mass; 
    int n, k; 
    string str; 
    cin >> k; 
    cin >> n; 
    for(int i = 1; i <= k; i++){ 
        str += itc_ToString(i); 
    } 
    int count = len(str); 
    for(int i = 0; i < count; i++){ 
        mass.push_back(str[i]); 
    } 
    sortv(mass); 
    char max = mass[mass.size() - 1], sec_max = max - n + 1; 
    char min = mass[0]; 
    vector<char> mass2; 
    vector<char> mass3(n, min); 
    for(int i = 0; i < n; i++){ 
        mass2.push_back(sec_max); 
        sec_max++; 
    } 
    while(mass3 != mass2){ 
        if(check(mass3) == true){ 
            print(mass3); 
            cout << endl; 
        } 
        re_zero(mass3, mass, n, max, min); 
    } 
    print(mass3); 
    return 0; 
}
