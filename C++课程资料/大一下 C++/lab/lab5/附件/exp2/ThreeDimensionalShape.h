#ifndef THREEDIMENSIONAL_H
#define THREEDIMENSIONAL_H
#include<string>
#include"Shape.h"
using namespace std;
class ThreeDimensionalShape :public Shape
{
private:
	string SortShape;
	void setDimensionalShape(const DimensionalShape a = THREE)
	{
		Shape::setDimensionalShape(a);
	}
public:
	ThreeDimensionalShape();
	~ThreeDimensionalShape();
	virtual double getArea()const = 0;
	virtual double getVolume()const = 0;
	virtual void print()const = 0;
	DimensionalShape getDimensionalShape()const
	{
		return Shape::getDimensionalShape();
	}
	void setSortShape(const string x)     //Ϊ�˼��ٺ������õĴ��� ����inline��ʽ
	{
		SortShape = x;
	}
	string getSortShape()const
	{
		return SortShape;
	}

};
#endif