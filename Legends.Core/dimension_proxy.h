#pragma once
class DimensionProxy
{
private:
	float& ref;
public:
	DimensionProxy(float& ref);
	operator float() const;
};