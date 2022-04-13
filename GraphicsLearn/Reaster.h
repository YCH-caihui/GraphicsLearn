#pragma once


#include "CELLMath.h"

namespace CELL
{

	class Reaster
	{
	public:
		Rgba * _buffer;
		int _width;
		int _height;

		Reaster(int w , int h, void * buffer);


		void clear();


		void drawPoint(int x, int y, Rgba color, int ptSize);

		void drawLine(float2 pt1, float2 pt2, Rgba color);

		void setPixel(int x, int y, Rgba color)
		{
			if (x < 0 || y < 0 || x >= _width || y >= _height) 
			{
				return;
			}
			_buffer[y * _width + x] = color;
		}

		~Reaster();

	
	};



}
