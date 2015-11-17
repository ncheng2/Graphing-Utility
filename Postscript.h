#ifndef POSTSCRIPT_HH
#define POSTSCRIPT_HH
#include <iostream>
#include <fstream>
using namespace std;

class Postscript {
private:
    ofstream file;
public:
    Postscript(const char filename[]) : file(filename) {
    }
    void fillRect(double x, double y, double w, double h) {
        file << x << ' ' << y << " moveto " ;
        file << w << ' ' << y << " lineto " ;
        file << w << ' ' << h << " lineto " ;
        file << x << ' ' << h << " lineto " << "fill ";
    }
    void fillTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        file << x1 << ' ' << y1 << " moveto " ;
        file << x2 << ' ' << y2 << " lineto " ;
        file << x3 << ' ' << y3 << " lineto " << "fill ";
    }
    void setColor(double a,double b,double c)
    {
        file << a << ' ' << b << ' ' << c << ' '<<"setrgbcolor ";
    }
    void rect(double x, double y, double w, double h) {
        file << x << ' ' << y << " moveto " ;
        file << w << ' ' << y << " lineto " ;
        file << w << ' ' << h << " lineto " ;
        file << x << ' ' << h << " lineto " << "closepath " <<"stroke ";
    }
    void triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        file << x1 << ' ' << y1 << " moveto " ;
        file << x2 << ' ' << y2 << " lineto " ;
        file << x3 << ' ' << y3 << " lineto " << "closepath " <<"stroke " << "showpage ";
    }
    // complete!
};

int main() {
    Postscript p("test.ps");
    p.fillRect(0,0, 100, 100);  // 0 0 moveto 100 0 lineto 100 100 lineto 0 100 lineto fill

    //0 200 moveto 200 200 lineto 100 400 lineto fill
    p.fillTriangle(0,200,  200,200, 100, 400);
    p.setColor(1,0,0); // 1 0 0  setrgbcolor

    p.rect(0,0, 100, 100);  // 0 0 moveto 100 0 lineto 100 100 lineto 0 100 lineto stroke
    p.triangle(0,200,  200,200, 100, 400); // same as fillTriangle but stroke instead of fill
}
#endif
