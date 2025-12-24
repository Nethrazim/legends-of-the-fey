#include "dimension_proxy.h"

DimensionProxy::DimensionProxy(float& ref) : ref(ref){}

DimensionProxy::operator float() const {
	return ref;
}

DimensionProxy& DimensionProxy::operator=(float value) {
	ref = value;
	return *this;
}

DimensionProxy& DimensionProxy::operator+=(float v) {
	ref += v;
	return *this;
}

DimensionProxy& DimensionProxy::operator-=(float v) {
	ref -= v;
	return *this;
}

DimensionProxy& DimensionProxy::operator*=(float v) {
	ref *= v;
	return *this;
}

DimensionProxy& DimensionProxy::operator/=(float v) {
	ref /= v;
	return *this;
}