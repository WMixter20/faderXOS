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

    //~cSenders() override;

    //void paint (juce::Graphics&) override;
    void resized() override;
    void showConnectionErrorMessage(const juce::String& messageText);
    
    int portNum = 12321;
    //"192.168.86.30"
    juce::String targetIp = "127.0.0.1";
    
    juce::String message1 = "/style/text/1/18";
    juce::String message2 = "/1/fader2";
    juce::String message3 = "/1/fader3";
    juce::String message4 = "/1/fader4";
    
    

private:
    juce::Slider rotaryKnobOne,
                 rotaryKnobTwo,
                 rotaryKnobThree,
                 rotaryKnobFour;

   juce::Label senderLabelOne { {},  "Sender 1"},
               senderLabelTwo{ {},   "Sender 2" },
               senderLabelThree{ {}, "Sender 3" },
               senderLabelFour{ {},  "Sender 4" },
               senderIPLabel { {}, targetIp},
               senderMessageOne{ {}, message1},
               senderMessageTwo{ {}, message2},
               senderMessageThree{ {}, message3},
               senderMessageFour{ {}, message4};


    juce::OSCSender senderOne,
                    senderTwo,
                    senderThree,
                    senderFour;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pSenders)
};
