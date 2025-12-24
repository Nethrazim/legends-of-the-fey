#pragma once
class DimensionProxy
{
private:
	float& ref;
public:
	DimensionProxy(float& ref);
	operator float() const;

	DimensionProxy& operator=(float value);

	DimensionProxy& operator+=(float v);
	
	DimensionProxy& operator-=(float v);
	
	DimensionProxy& operator*=(float v);
	
	DimensionProxy& operator/=(float v);
};