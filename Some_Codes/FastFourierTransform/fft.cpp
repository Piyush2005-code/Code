#include<iostream>
#include<vector>
#include<cmath>
#include<complex>

using namespace std;

const double PI = acos(-1);

void fft(vector<complex<double>>& a, bool invert){
    int n = a.size();
    if(n == 1) return;

    vector<complex<double>> a0(n / 2), a1(n / 2);

    for(int i = 0; i < n / 2; i++){
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    complex<double> w(1), wn(cos(ang), sin(ang));
    for(int i = 0; i < n / 2; i++){
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if(invert){
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}



void printVect(const vector<complex<double>>& a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    } cout << endl;
}

int main(){

    int n; cout << "By god's grace, please add an even number in this particular size of the array : ";
    cin >> n;
    vector<complex<double>> a(n);

    for(int i = 0; i < n; i++){
        double real, imag;
        cin >> real >> imag;
        complex<double> cd(real, imag);
        a[i] = cd;
    }

    fft(a, false);
    printVect(a);

    fft(a, true);
    printVect(a);

}
