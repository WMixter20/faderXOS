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
class pRecievers  : public juce::Component,
                    private juce::OSCReceiver,
                    private juce::OSCReceiver::ListenerWithOSCAddress<juce::OSCReceiver::MessageLoopCallback>

{
public:
    pRecievers();
    //~hRecievers() override;
    //void paint (juce::Graphics&) override;
    void resized() override;
    
    void showConnectionErrorMessage(const juce::String& messageText);

    int portNum = 8000;
    juce::String recieverIp = "192.168.86.30";
    
    juce::String message1 = "/1/fader1";
    juce::String message2 = "/1/fader2";
    juce::String message3 = "/1/fader3";
    juce::String message4 = "/1/fader4";

    
private:
//==============================================================================
    void oscMessageReceived(const juce::OSCMessage& message) override;
    
    juce::Slider rotaryKnobOne,
                 rotaryKnobTwo,
                 rotaryKnobThree,
                 rotaryKnobFour;

    juce::Label receiverLabel1 { {}, "Recieving " + message1 },
                receiverLabel2{ {},  "Recieving " + message2 },
                receiverLabel3{ {},  "Recieving " + message3 },
                receiverLabel4{ {},  "Recieving " + message4 };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (pRecievers)
};
