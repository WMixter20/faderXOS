/*
  ==============================================================================

    cSenders.h
    Created: 23 Feb 2022 11:16:54am
    Author:  Will Mixter

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class cSenders  : public juce::Component
{
public:
    cSenders();
    ~cSenders() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider rotaryKnobOne,
                 rotaryKnobTwo,
                 rotaryKnobThree,
                 rotaryKnobFour;

   juce::Label senderLabelOne { {}, "Sender 1" },
               senderLabelTwo{ {}, "Sender 2" },
               senderLabelThree{ {}, "Sender 2" },
               senderLabelFour{ {}, "Sender 2" };


    juce::OSCSender senderOne,
                    senderTwo,
                    senderThree,
                    senderFour;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (cSenders)
};
