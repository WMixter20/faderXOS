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
class hRecievers  : public juce::Component,
                    private juce::OSCReceiver,
                    private juce::OSCReceiver::ListenerWithOSCAddress<juce::OSCReceiver::MessageLoopCallback>

{
public:
    hRecievers();
    //~hRecievers() override;
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
//==============================================================================
    void oscMessageReceived(const juce::OSCMessage& message) override;
    
    juce::Slider rotaryKnobOne,
                 rotaryKnobTwo,
                 rotaryKnobThree,
                 rotaryKnobFour;

    juce::Label receiverLabel1 { {}, "Listening to " + message1 },
                receiverLabel2{ {},  "Listening to " + message2 },
                receiverLabel3{ {},  "Listening to " + message3 },
                receiverLabel4{ {},  "Listening to " + message4 };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (hRecievers)
};
