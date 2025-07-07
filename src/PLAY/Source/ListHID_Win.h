/*
  ==============================================================================

    ListHID_Win.h
    Created: 7 Jul 2025 1:04:00pm
    Author:  hs_remote

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <windows.h>
#include <hidsdi.h>
#include <setupapi.h>
#include <set>
#include <map>
#include <string>

#pragma comment(lib, "hid.lib")
#pragma comment(lib, "setupapi.lib")

//==============================================================================
// Windows version of ListHID
class ListHID : public juce::Component
{
public:
    ListHID() = default;
    ~ListHID() override
    {
        // Close all open handles
        for (auto& entry : devicesMap)
        {
            if (entry.second)
                CloseHandle(entry.second);
        }
    }

    // Enumerate HID devices and fill devicesMap
    void get_hid_list();

    // Set of unique device names (juce::String)
    std::set<juce::String> uniqueDevices;
    // Map of device name to HANDLE
    std::map<juce::String, HANDLE> devicesMap;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ListHID)
};
