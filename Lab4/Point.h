#pragma once

namespace lab4
{
	class Point
	{
	public:
		Point();
		Point(float x, float y);
		Point(const Point& other);

		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;

		Point operator*(float operand) const;
		Point& operator=(const Point& other);

		float GetX() const;
		float GetY() const;
		

	private:
		float mPointX;
		float mPointY;
	};

	Point operator* (int value, Point& other);
	Point operator* (float value, Point& other);
}