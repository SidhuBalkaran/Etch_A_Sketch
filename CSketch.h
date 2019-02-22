
#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <conio.h>
#include <istream>
#include "Client.h"
#include "Server.h"
#include "Serial.h"
#include "opencv.hpp"
#include "CBase4618.h"


/**
*
* @brief C++ object used draw usnig MSP432 JOTSTICK
*
* This class inherits methods and objects from CBase class.
* this class is overloaded to get joystick data in method update
* and used method draw to draw on a Open cv object
*
* @author Balkaran Sidhu
*
*/
class CSketch :public CBase4618{



public:

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	CSketch();

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	CSketch(cv::Size d,int);

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	~CSketch();

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	void update() override; 

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	void draw() override;

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	//void run();

	/** @brief Sets the desired COM port.
	*
	* @param COM port string.
	* @return nothing to return
	*/
	void color_button();

	int x_pos; ///< X value JoYSTICK
	int y_pos; ///< Y value JoYSTICK
	int flag; ///< BUTTON FLAG value JoYSTICK
	int high; ///< canvas height
	int wide; ///< canvas width 
	char color[3] = { 'R','G','B' }; ///< array or ink colors
	int count = 0; ///< array index
	int x_new; ///<new x point
	int y_new; ///<new y point

};

