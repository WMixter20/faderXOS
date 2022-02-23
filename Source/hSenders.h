/*
  ==============================================================================

    hSenders.h
    Created: 23 Feb 2022 11:17:25am
    Author:  Will Mixter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class hSenders  : public juce::Component
{
public:
    hSenders();
    ~hSenders() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (hSenders)
};
