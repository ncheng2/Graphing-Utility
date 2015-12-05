//author:Nan Cheng
//by myself
#include<iostream>
#include<fstream>
#include<vector>
#include"POSTSCRIPT.h"
#include<string>
#include<sstream>
using namespace std;
void Timeseries(string a)// a function to read in a file with time and corresponding data and draw a timeseries script
{
	Postscript A("Timeseries");//construct a Postscript.
	ifstream in(a);//read in a file.
	vector<double> array;
	double buffer = 0;
	while (in >> buffer)
	     array.push_back(buffer);//read in every number in this file.
	int n = array.size;//consider the first half of this array means defferent timings and the second half is corresponding data.
	double MaxX=array[0], MaxY=array[n/2];//to find max x and max y so that I can draw an appropriate coordinate system.
	for (int i = 0; i < n / 2-1; i++)
	{
		if (array[i] < array[i + 1])
			MaxX = array[i + 1];
	}
	for (int i = n / 2; i < n - 1; i++)
	{if(array[i] < array[i + 1])
		MaxY = array[i + 1];
	}
	A.coordinate(MaxX, MaxY);//draw coordinate system.
    cout << "choose script type:1.solid line and circle points 2.dash line and square points";
	int choice;//defferent kinds of script
	cin >> choice;
	cout << "Please set line width";
	double w;//set line width
	cin >> w;
	if (choice == 1)
	{
		for (int i = 0; i < n / 2; i++)
		{
			A.circle(array[i], array[i + n / 2]);// draw points
		}
		for (int i = 0; i < n / 2 - 1; i++)// draw lines
		{
			A.line(array[i], array[i + n / 2], array[i + 1], array[i + 1 + n / 2]);
		}
	}
	else 
	{
		cout << "set dash size";//set dash size
		double size;
		cin >> size;
		A.Setdash(size);
		for (int i = 0; i < n / 2; i++)
		{
			A.rectangle(array[i], array[i + n / 2]);//draw points
		}
		for (int i = 0; i < n / 2 - 1; i++)
		{
			A.line(array[i], array[i + n / 2], array[i + 1], array[i + 1 + n / 2]);//draw lines
		}
		
	}


}
void Bargraph(string a)//read in a file with different kinds of data.
{
	Postscript A("Bargraph");//construct a Postscript.
	ifstream in(a);//read in a file.
	vector<string> array;
	string buffer;
	while (in >> buffer)
		array.push_back(buffer);//read in terms or numbers in this file.
	int n = array.size;
	string* type = new string[n / 2];//restore each term which shows kinds like 'basketball' 'socker''volleyball' or something
	for (int i = 0; i < n / 2; i++)
	{
		type[i] = array[i];
	}
	double b;
	stringstream buffer1;
	double* data = new double[n / 2];//restore each number
	for (int i = n / 2; i < n; i++)
	{
		buffer1 << array[i];
		buffer1 >> b;//convert data type from string to double.
		buffer1.clear();
		data[i - n / 2] = b;

	}
	double MaxY;
	for (int i = 0; i < n / 2 - 1; i++)
	{
		if (data[i] < data[i + 1])
			MaxY = data[i + 1];
	}//find the max number so I can draw appropriate coordinate system.
	cout << "set bar width";
	double w;
	cin >> w;//set bar width
	A.coordinate(w*(n / 2 + 1), MaxY);//draw coordinate system
	for (int i = 0; i < n / 2; i++)
	{
		A.fillRect((i + 1)*w, 0, w, data[i]);//draw each bar
	}


}
void main()
{
	cout << "please enter file name";
	string a;
	cin >> a;
	cout << "1.Timeseries 2.Bargraph";
	int choice;
	cin >> choice;
	if (choice == 1)
		Timeseries(a);
	else Bargraph(a);


}
