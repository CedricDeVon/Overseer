#include <Arduino.h>

#include "HCSR04UltrasonicDistanceCalculator.h"

HCSR04UltrasonicDistanceCalculator::HCSR04UltrasonicDistanceCalculator(unsigned int maximumDistance, byte measurementIndex)
{
    if (_isIndexInvalid(measurementIndex))
    {
        measurementIndex = 0;
    }

    _maximumDistance = maximumDistance;
    _measurementIndex = measurementIndex;
}

HCSR04UltrasonicDistanceCalculator::HCSR04UltrasonicDistanceCalculator(unsigned int maximumDistance)
{
    _maximumDistance = maximumDistance;
    _measurementIndex = 0;
}

HCSR04UltrasonicDistanceCalculator::HCSR04UltrasonicDistanceCalculator(byte measurementIndex)
{
    _maximumDistance = 1000000;
    _measurementIndex = measurementIndex;
}

unsigned int HCSR04UltrasonicDistanceCalculator::getIntegerConversion(unsigned int analogInput)
{
    unsigned int output = analogInput / _measurementValues[_measurementIndex];
    return (output >= _maximumDistance) ? _maximumDistance : output;
}

unsigned int HCSR04UltrasonicDistanceCalculator::getMaximumDistance()
{
    return _maximumDistance;
}

byte HCSR04UltrasonicDistanceCalculator::getMeasurementIndex()
{
    return _measurementIndex;
}

char *HCSR04UltrasonicDistanceCalculator::getMeasurementName()
{
    return _measurementNames[_measurementIndex];
}

int HCSR04UltrasonicDistanceCalculator::getMeasurementNameSize()
{
    return _measurementNameSizes[_measurementIndex];
}

bool HCSR04UltrasonicDistanceCalculator::_isIndexInvalid(byte index)
{
    return index < 0 || index >= sizeof(_measurementNames) / sizeof(_measurementNames[0]);
}
