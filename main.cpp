#include <iostream>
using namespace std;

int d[100][100], r[10], a[10], a2[10], a3[10], n, k = 0, ans;

void base16();
void base8();
void base11();
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        r[i] = 0;
        for(int j = 0; j < n-1; ++j){
            cin >> d[i][j];
            r[i] = d[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        cout << endl;
        for(int j = 0; j < n-1; ++j){
            if(r[i] == 16){
                k = 0;
                ans = d[i][j-1];
                while(ans > 0){
                    a[k] = ans % 16;
                    ans /= 16;
                    ++k;
                }
                base16();
            } else if(r[i] == 8){
                k = 0;
                ans = d[i][j-1];
                while(ans > 0){
                    a2[k] = ans % 8;
                    ans /= 8;
                    ++k;
                }
                base8();
            } else if(r[i] == 11){
                k = 0;
                ans = d[i][j-1];
                while(ans > 0){
                    a3[k] = ans % 11;
                    ans /= 11;
                    ++k;
                }
                base11();
            }
        }
    }
    return 0;
}
void base16(){
    for(int i = k - 1; i >= 0; --i){
        if(a[i] == 10){
            cout << 'A';
            continue;
        } else if(a[i] == 11){
            cout << 'B';
            continue;
        } else if(a[i] == 12){
            cout << 'C';
            continue;
        } else if(a[i] == 13){
            cout << 'D';
            continue;
        } else if(a[i] == 14){
            cout << 'E';
            continue;
        } else if(a[i] == 15){
            cout << 'F';
            continue;
        }
        cout << a[i];
    }
}
void base8(){
    for(int i = k - 1; i >= 0; --i){
        cout << a2[i];
    }
}
void base11(){
    for(int i = k - 1; i >= 0; --i){
        if(a3[i] == 10){
            cout << 'A';
            continue;
        }else if(a3[i] == 0){
            continue;
        }
        cout << a3[i];
    }
}
