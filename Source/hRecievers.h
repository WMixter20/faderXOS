/*
  ==============================================================================

    hRecievers.h
    Created: 23 Feb 2022 11:20:30am
    Author:  Will Mixter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class hRecievers  : public juce::Component
{
public:
    hRecievers();
    ~hRecievers() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (hRecievers)
};
