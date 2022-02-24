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
class cRecievers  : public juce::Component,
                    private juce::OSCReceiver,
                    private juce::OSCReceiver::ListenerWithOSCAddress<juce::OSCReceiver::MessageLoopCallback>

{
public:
    cRecievers();
    //~cRecievers() override;

    //void paint (juce::Graphics&) override;
    void resized() override;
    
    void showConnectionErrorMessage(const juce::String& messageText);

    int portNum = 9000;
    juce::String recieverIp = "192.168.86.31";
    
    juce::String message1 = "/1/fader1";
    juce::String message2 = "/1/fader2";
    juce::String message3 = "/1/fader3";
    juce::String message4 = "/1/fader4";

private:
    
    void oscMessageReceived(const juce::OSCMessage& message) override;
    
    juce::Slider rotaryKnobOne,
                 rotaryKnobTwo,
                 rotaryKnobThree,
                 rotaryKnobFour;

    juce::Label receiverLabel1 { {}, "Receiver 1" },
                receiverLabel2{ {}, "Receiver 2" },
                receiverLabel3{ {}, "Receiver 3" },
                receiverLabel4{ {}, "Receiver 4" };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (cRecievers)
};
