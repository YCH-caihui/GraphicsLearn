#include "Reaster.h"
namespace CELL
{

	Reaster::Reaster(int w, int h, void* buffer)
	{
		_width = w;
		_height = h;
		_buffer = (Rgba*)buffer;
	}


	void Reaster::clear()
	{
		memset(_buffer, 0, _width * _height * sizeof(CELL::Rgba));
	}


	void Reaster::drawPoint(int x, int y, Rgba color, int ptSize)
	{

		switch (ptSize)
		{
		case 1:
			setPixel(x, y, color);
			break;
		case 2:
			setPixel(x + 0, y + 0, color);
			setPixel(x + 1, y + 0, color);
			setPixel(x + 0, y + 1, color);
			setPixel(x + 1, y + 1, color);
			break;
		case 3:
			setPixel(x - 1, y - 1, color);
			setPixel(x + 0, y - 1, color);
			setPixel(x + 1, y - 1, color);

			setPixel(x - 1, y + 0, color);
			setPixel(x + 0, y + 0, color);
			setPixel(x + 1, y + 0, color);

			setPixel(x - 1, y + 1, color);
			setPixel(x + 0, y + 1, color);
			setPixel(x + 1, y + 1, color);


			break;
		default:
			break;
		}

	}

	void Reaster::drawLine(float2 pt1, float2 pt2, Rgba color)
	{

		float xOffet = pt1.x - pt2.x;
		float yOffet = pt1.y - pt2.y;

		if (xOffet == 0) 
		{
			for (float y = pt1.y; y <= pt2.y; y += 1.0f)
			{
				setPixel(pt2.x, y, color);
			}
		}
		else if (yOffet == 0) 
		{
			for (float x = pt1.x; x <= pt2.x; x += 1.0f)
			{
				setPixel(x, pt2.y, color);
			}
		}
		else
		{
			float slope = yOffet / xOffet;
			for (float x = pt1.x; x <= pt2.x; x += 1.0f)
			{
				float y = pt1.y + (x - pt1.x) * slope;
				setPixel(x, y, color);
			}
		}


	
	}

	Reaster::~Reaster()
	{

	}




}