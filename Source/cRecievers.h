/*
  ==============================================================================

    cRecievers.h
    Created: 23 Feb 2022 11:20:14am
    Author:  Will Mixter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class cRecievers  : public juce::Component
{
public:
    cRecievers();
    ~cRecievers() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (cRecievers)
};
