
/////////////////////////////////////////////////////////////////////   
//Fraction.   
/////////////////////////////////////////////////////////////////////   
using namespace std;   
   
typedef long long Num;   
   
Num gcd(Num a, Num b) {   
    Num temp;   
    if (a < b) {   
        temp = a;   
        a = b;   
        b = temp;   
    }   
    do {   
        temp = a % b;   
        a = b;   
        b = temp;   
    } while (b != 0);   
    return a;   
}   
   
struct Fraction {   
    Num up;   
    Num down;   
   
    Fraction(Num _up = 1, Num _down = 1) {   
        up = _up;   
        down = _down;   
    }   
       
    void reduce() {   
        if (up != 0) {   
            Num div = up > 0? gcd(up, down): gcd(-up, down);   
            up /= div;   
            down /= div;   
        }   
        else {   
            down = 1;   
        }   
    }   
   
    Fraction operator + (const Fraction& add) const {   
        Fraction result(up * add.down + down * add.up, down * add.down);   
        result.reduce();   
        return result;   
    }   
   
    Fraction operator - (const Fraction& sub) const {   
        Fraction result(up * sub.down - down * sub.up, down * sub.down);   
        result.reduce();   
        return result;   
    }   
   
    Fraction operator * (const Fraction& mul) const {   
        Fraction result(up * mul.up, down * mul.down);   
        result.reduce();   
        return result;   
    }   
   
    Fraction operator / (const Fraction& div) const {   
        Fraction result(up * div.down, down * div.up);   
        result.reduce();   
        return result;   
    }   
   
    bool operator == (Num i) const {   
        return up % down == 0 && up / down == i;   
    }   
   
    bool operator != (Num i) const {   
        return !(*this == i);   
    }   
   
    void operator = (Num i) {   
        up = i;   
        down = 1;   
    }   
};   
   
//Test suite.   
#include <iostream>   
   
ostream& operator << (ostream& os, const Fraction& f) {   
    if (f.down != 1) {   
        os << f.up << "/" << f.down;   
    }   
    else {   
        os << f.up;   
    }   
    return os;   
}   
   
int main () {   
    typedef Fraction F;   
    Fraction f[] = {F(2, 3), F(5, 7), F(9, 6), F(3, 4), F(125, 63)};   
    Fraction result = (f[0] + f[1] * f[2]) / f[3];   
    cout << result << " ";   
    result = result - f[4];   
    cout << result << " " << (result == 1) << " " << (result != 0) << endl;   
    //Correct output: 146/63 1/3 0 1;   
    return 0;   
}   
