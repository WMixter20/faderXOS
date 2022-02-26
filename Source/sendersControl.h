/*
  ==============================================================================

    sendersControl.h
    Created: 25 Feb 2022 5:15:46pm
    Author:  Will Mixter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "cSenders.h"


//==============================================================================
/*
*/
class sendersControl  : public juce::Component,
                        public juce::Button::Listener
{
public:
    sendersControl();
    //~sendersControl() override;

    //void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked (juce::Button* button) override;

private:
    
    juce::TextButton connectToPort;
    juce::Label timeLabel;
    juce::String cSendersIP;
    
    //cSenders cSender;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (sendersControl)
};
