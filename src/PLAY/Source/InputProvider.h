/*
  ==============================================================================

    InputProvider.h
    Created: 22 Oct 2023 2:14:41pm
    Author:  Hongshuo Fan

  ==============================================================================
*/

#pragma once
#include <array>
#include <functional>
#include <string>
#include <cstring>
//#include <JuceHeader.h>

static const juce::uint32 DeviceIdTypeCount = 6;
typedef std::array<juce::uint32, DeviceIdTypeCount> DeviceIdType;
