/*
 * bar_graph.hpp
 *
 *  Created on: Dec 4, 2015
 *  Author: Zhen Qiu
 */
/*
 * author:Zhen Qiu
 *
 */
#ifndef BAR_GRAPH_HPP
#define BAR_GRAPH_HPP

#include <vector>

using namespace std;

typedef double (*rectangle_four_dot)[4][2];

template<class T>
class Bar_graph{
private:
	vector<T> x_value;
	vector<T> y_value;
public:
	Bar_graph(vector<T> x_value, vector<T> y_value):x_value(x_value),y_value(y_value){}
	~Bar_graph(){
		x_value.clear();
		y_value.clear();
	}
    rectangle_four_dot rectangle_reslove(T x_scale,T y_scale){
    	rectangle_four_dot p=new T[this->x_value.size()][4][2];
    	T x_division=x_scale/(x_value.size()*2+1);
    	T y_limit_factor=y_value[0];
    	for(T i:y_value){
    		if(i>y_limit_factor){
    			y_limit_factor=i;
    		}
    	}
    	y_limit_factor=y_scale/y_limit_factor;
    	for(int i=0;i<x_value.size();i++){
    		***(p+i)=x_division*i;                           //first dot
    		*(**(p+i)+1)=0;
    		**(*(p+i)+1)=x_division*i;                       //second dot
    		*(*(*(p+i)+1)+1)=y_value[i]*y_limit_factor;
    		**(*(p+i)+2)=x_division*(i+1);                   //third dot
    		*(*(*(p+i)+2)+1)=y_value[i]*y_limit_factor;
    		**(*(p+i)+3)=x_division*(i+1);                   //fourth dot
    		*(*(*(p+i)+3)+1)=0;
    	}
    	return p;
    }



};
