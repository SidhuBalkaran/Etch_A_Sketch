#include "stdafx.h"
#include "CSketch.h"
using namespace cv;


CSketch::CSketch()
{
}
CSketch::CSketch(cv::Size d,int com)
{
	control.init_com(com);
	_canvas=cv::Mat::zeros(d, CV_8UC3);
	high = d.height;
	wide = d.width;
	y_new = high / 2;
	x_new = wide / 2;
}
void CSketch:: update()
{
	color_button();
	int y, x;
	int read = control.get_button();
		 if (read == 0)
	 {
		 flag = 1;
	 }
		 else
	{
	    control.get_data("G", "1", "9", y);
		control.get_data("G", "1", "15", x);
		y_pos = (high / 60)*(control.get_analog(y) - 15); //(control.get_analog(y) * high)/100;
		x_pos = (wide/ 60)*(control.get_analog(x) - 15);//(control.get_analog(x)*wide)/100;
		 if (x_pos > wide)
			 x_pos = wide-1;
		 if (y_pos <= 0)
			 y_pos = 1;
		 if(y_pos>high)
			 y_pos = high - 1;
		 if (x_pos <= 0)
			 x_pos = 1;
	}
 }
void CSketch::draw()
{
	if (flag == 1)
	{
		//_canvas = cv::Mat::zeros(high, wide, CV_8UC3);
		_canvas = cv::Mat::zeros(_canvas.size(), _canvas.type());
		flag = 0;
	}
	else
	{
		if (color[count] == 'R')
		{
			control.set_data("0", "38", "1");
			control.set_data("0", "37", "0");
			control.set_data("0", "39", "0");
			line(_canvas, Point(x_new,high-y_new),Point(x_pos, high-y_pos), Scalar(0,255 ,0 ), 1, 8, 0);
		}
		
		else if (color[count] == 'G')
		{
			control.set_data("0", "39", "1");
			control.set_data("0", "37", "0");
			control.set_data("0", "38", "0");
			
			line(_canvas, Point(x_new, high-y_new), Point(x_pos, high-y_pos), Scalar(0, 0, 255), 2, 8, 0);
		}
		else if (color[count] == 'B')
		{
			control.set_data("0", "37", "1");
			control.set_data("0", "38", "0");
			control.set_data("0", "39", "0");
			line(_canvas, Point(x_new,high- y_new), Point(x_pos,high- y_pos), Scalar(255, 0, 0), 50, 8, 0);
		}
		x_new = x_pos;
		y_new = y_pos;
		imshow("Image", _canvas);
	}	
}
void CSketch::color_button()
{
	int lastp = 1;
	int p;
	control.get_data("G", "0", "33", p);
	if (p != lastp)
	{
		while (p == 0)
		{
			control.get_data("G", "0", "33", p);
		}
		count++;
	}
	if (count > 2)
		count =0;
	lastp = p;
		
}
CSketch::~CSketch()
{
	control.set_data("0", "39", "0");
	control.set_data("0", "37", "0");
	control.set_data("0", "38", "0");
}
