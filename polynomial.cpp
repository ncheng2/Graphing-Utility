/*
 * polynomial.cpp
 *
 *  Created on: Dec 4, 2015
 *  Author: Zhen Qiu
 */

#include <cmath>
#include <vector>

using namespace std;

typedef double (*graphic_value)[2];
inline double index_mutiplication(const double dot_xvalue,const int index);

class Polynomial{
private:
	vector<int> index;
	vector<double> coefficient;
public:
	Polynomial(const vector<int>& index, const vector<double>& coefficient):index(index),coefficient(coefficient){}
	~Polynomial(){
		index.clear();
		coefficient.clear();
	}
	friend graphic_value polynomial_to_graphic(Polynomial& pol,int dot_num, double xscale){
        double graphic_dot[dot_num][2];
        double (*p)[2]=graphic_dot;
        double sum=0;
        for(int i=0; i<dot_num; i++){
        	 double x=xscale/dot_num*i;
        	 for(unsigned int j=0;j<pol.coefficient.size();j++){
        		 sum+=pol.coefficient[j]*index_mutiplication(x,pol.index[j]);
        	 }
             **(graphic_dot+i)=x;
             *(*(graphic_dot+i)+1)=sum;
             sum=0;
        }
        return p;
	}
};

inline double index_mutiplication(const double dot_xvalue,const int index){
	int i=index;
	double mul=1.;
	while(i>0){
		mul*=dot_xvalue;
		i--;
	}
	return mul;
}




