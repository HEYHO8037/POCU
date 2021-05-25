#include "Point.h"

namespace lab4
{
	Point::Point()
		: mPointX(0), mPointY(0)
	{
	}

	Point::Point(float x, float y)
		: mPointX(x), mPointY(y)
	{
	}

	Point::Point(const Point& other)
		: mPointX(other.GetX()), mPointY(other.GetY())
	{
	}

	Point::~Point()
	{
		mPointX = 0;
		mPointY = 0;
	}

	Point Point::operator+(const Point& other) const
	{
		float plusX = mPointX + other.mPointX;
		float plusY = mPointY + other.mPointY;

		return Point(plusX, plusY);
	}

	Point Point::operator-(const Point& other) const
	{
		float minusX = mPointX - other.mPointX;
		float minusY = mPointY - other.mPointY;
		return Point(minusX, minusY);
	}

	float Point::Dot(const Point& other) const
	{
		float dotProduct = (mPointX * other.mPointX) + (mPointY * other.mPointY);
		return dotProduct;
	}

	Point Point::operator*(float operand) const
	{
		float operandX = mPointX * operand;
		float operandY = mPointY * operand;

		return Point(operandX, operandY);
	}

	Point& Point::operator=(const Point& other)
	{
		mPointX = other.GetX();
		mPointY = other.GetY();

		return *this;
	}

	float Point::GetX() const
	{
		return mPointX;
	}

	float Point::GetY() const
	{
		return mPointY;
	}

	Point operator*(int value, Point& other)
	{
		float changeValue = value;
		return other * changeValue;
	}

	Point operator*(float value, Point& other)
	{
		return other * value;
	}

}