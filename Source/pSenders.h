/*
  ==============================================================================

    pSenders.h
    Created: 23 Feb 2022 11:17:53am
    Author:  Will Mixter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class pSenders  : public juce::Component
{
public:
    pSenders();
    ~pSenders() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pSenders)
};
