#include "dimension_proxy.h"

DimensionProxy::DimensionProxy(float& ref) : ref(ref){}

DimensionProxy::operator float() const {
	return ref;
}