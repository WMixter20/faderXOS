/*
  ==============================================================================

    pRecievers.h
    Created: 23 Feb 2022 11:20:45am
    Author:  Will Mixter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class pRecievers  : public juce::Component
{
public:
    pRecievers();
    ~pRecievers() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pRecievers)
};
