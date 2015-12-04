//author:Nan Cheng
//to draw time series and bar graph and so on, I need some basic method to draw each element in the graph. And this file includes all the elements I need.

#ifndef POSTSCRIPT_HH_
#define POSTSCRIPT_HH_
#include <iostream>
#include <fstream>
using namespace std;

class Postscript {
private:
	ofstream file;
public:
	Postscript(const char filename[]) :file(filename) {}
	void circle(double x, double y) //to draw a circle point, and as a point, it has a default radius as 0.5.
	{
		file << x << ' ' << y << ' ' << 0.5 << ' ' << 0 << ' ' << 360 << ' ' << "arc" << ' ' << "stroke" <<' '<<"restore"<< '\n';

	}
	void rectangle(double x, double y) //to draw a square point, it has a default length of side as 1.
	{
		file << x - 0.5 << ' ' << y - 0.5 << ' ' << "moveto" << x - 0.5 << ' ' << y + 0.5 << ' ' << "lineto"
			<< x + 0.5 << ' ' << y + 0.5 << ' ' << "lineto" << x + 0.5 << ' ' << y - 0.5 << ' ' << "lineto"<< x - 0.5 << ' ' << y - 0.5 << ' '
			<< "closepath"<<' '<<"stroke" <<' '<<"restore"<< '\n';

	}
	void coordinate(double x, double y) //postscript has a default coordinate system, but it does not draw it on the page. 
		//I use this method to draw another default coordinate system,move origin and scale the x and y axises by a factor of a parameter corresponding to the max x and y.
//x,y means the max value of data set
	{
		file << 0.1*x << ' ' << 0.1*y << ' ' << "translate"//lower-left of images at (0.1x, 0.1y)
			<< 1.2*x<< ' ' <<1.2*y << ' ' << "scale"//size of rendered image is 1.2x points by 1.2y points
			<< 0 << ' ' << 0 << ' ' << "moveto" << 1.2*x << ' ' << 0 << ' ' << "lineto"<<' '<<"stroke"<<' '<<"gsave"//draw x axis and the "x" in "1.2*x" means the max value of a dataset.
			<< 0 << ' ' << 0 << ' ' << "move to" << 0 << ' ' << 1.2*y << ' ' << "lineto"<<' '<<"stroke"<<' '<<"grestroe"//using the same method to draw y axis
			<< 1.2*x << ' ' << 0.1*y<< ' ' << "moveto" << 1.2*x << ' ' << -0.1*y<< ' ' << "lineto" << 1.3*x<< ' ' << 0 << ' ' << " lineto" << ' ' << " fill"<<' '<<"grestore"
			<<0.1*x << ' ' << 1.2*y << ' ' << "moveto" << -0.1*x << ' ' << 1.3*y << ' ' << "lineto" << 0 << ' ' << 1.2*y + 1 << ' ' << "lineto" << ' ' << "fill" << ' ' <<"grestore"<<'\n';
		//fill a small triangle at the end of both axises.
	}
	void SetLineWidth(double w)//to set line width
	{
		file << w << ' ' << "setlinewidth" << '\n';
	}
	void line(double x1,double y1,double x2,double y2) //to draw a line to connect 2 points
	{
		file << x1 << ' ' << y1 << ' ' << "moveto" << x2 << ' ' << y2 << "lineto" << ' ' << "stroke" << ' ' << "restore" << '\n';

	}
	void Setdash(double dashsize)//to set a dash size, so I can draw a dash line.
	{
	
		file << '[' << dashsize << ' ' << dashsize << ']' << ' ' << 0 << ' ' << "setdash" << '\n';
	}
	
	void setcolor(int r,int g,int b)//to set color
	{
		file << r << " " << g << " " << b << " " << " setrgbcolor " << '\n';
	}
	void fillRect(double x, double y, double w, double h)//to fill a rectangle when I want to draw a bar graph
		
	{
		file << x << ' ' << y << " moveto " << x + w << ' ' << y << " lineto" <<
			x + w << ' ' << y + h << " lineto " << x << ' ' << y + h << " lineto " << " fill " <<' '<<"restore"<< '\n';
	}

};
#endif
#pragma once
