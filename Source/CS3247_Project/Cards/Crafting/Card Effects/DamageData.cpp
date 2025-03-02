#include "DamageData.h"
FDamageData FDamageData::operator+(const double Offset) const {
	return FDamageData(this->DamageType, this->DamageValue + Offset);
}

FDamageData FDamageData::operator-(const double Offset) const {
	return *this + (-Offset);
}

FDamageData FDamageData::operator*(const double Factor) const {
	return FDamageData(this->DamageType, this->DamageValue * Factor);
}

FDamageData FDamageData::operator+=(const double Value) const {
	return *this + Value;
}

FDamageData FDamageData::operator-=(const double Value) const {
	return *this - Value;
}

FDamageData FDamageData::operator*=(const double Value) const {
	return *this * Value;
}
