/*
  ==============================================================================

    cRecievers.cpp
    Created: 23 Feb 2022 11:20:14am
    Author:  Will Mixter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "cRecievers.h"

//==============================================================================
cRecievers::cRecievers()
{
            receiverLabel1.attachToComponent(&rotaryKnobOne, false);                            //Drawing Knob 1 and Label
            addAndMakeVisible(receiverLabel1);

            rotaryKnobOne.setRange(0, 127);
            rotaryKnobOne.setSliderStyle(juce::Slider::RotaryVerticalDrag);
            rotaryKnobOne.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 150, 25);
            addAndMakeVisible(rotaryKnobOne);

            receiverLabel2.attachToComponent(&rotaryKnobTwo, false);                            //Drawing Knob 2 and Label
            addAndMakeVisible(receiverLabel2);

            rotaryKnobTwo.setRange(0, 127);
            rotaryKnobTwo.setSliderStyle(juce::Slider::RotaryVerticalDrag);
            rotaryKnobTwo.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 150, 25);
            addAndMakeVisible(rotaryKnobTwo);

            receiverLabel3.attachToComponent(&rotaryKnobThree, false);                            //Drawing Knob 3 and Label
            addAndMakeVisible(receiverLabel3);

            rotaryKnobThree.setRange(0, 127);
            rotaryKnobThree.setSliderStyle(juce::Slider::RotaryVerticalDrag);
            rotaryKnobThree.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 150, 25);
            addAndMakeVisible(rotaryKnobThree);

            receiverLabel4.attachToComponent(&rotaryKnobFour, false);                            //Drawing Knob 4 and Label
            addAndMakeVisible(receiverLabel4);

            rotaryKnobFour.setRange(0, 127);
            rotaryKnobFour.setSliderStyle(juce::Slider::RotaryVerticalDrag);
            rotaryKnobFour.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 150, 25);
            addAndMakeVisible(rotaryKnobFour);

            //==============================================================================
            if(!connect(portNum))
               showConnectionErrorMessage("Error: could not connect to UDP port");
            
            addListener(this, message1);
            addListener(this, message2);
            addListener(this, message3);
            addListener(this, message4);
    
}
void cRecievers::oscMessageReceived(const juce::OSCMessage &message)
{
    if (message.getAddressPattern() == message1 && message.size() == 1 && message[0].isFloat32())
           {
               rotaryKnobOne.setValue(juce::jlimit(0.0f, 127.0f, message[0].getFloat32()));
           };

           if (message.getAddressPattern() == message2 && message.size() == 1 && message[0].isFloat32())
           {
               rotaryKnobTwo.setValue(juce::jlimit(0.0f, 127.0f, message[0].getFloat32()));
           };

           if (message.getAddressPattern() == message3 && message.size() == 1 && message[0].isFloat32())
           {
               rotaryKnobThree.setValue(juce::jlimit(0.0f, 127.0f, message[0].getFloat32()));
           };

           if (message.getAddressPattern() == message4 && message.size() == 1 && message[0].isFloat32())
           {
               rotaryKnobFour.setValue(juce::jlimit(0.0f, 127.0f, message[0].getFloat32()));
           };
}

void cRecievers::resized()
{
    rotaryKnobOne.setBoundsRelative(0.00, 0.10, 0.25, 0.80);
    rotaryKnobTwo.setBoundsRelative(0.25, 0.10, 0.25, 0.80);
    rotaryKnobThree.setBoundsRelative(0.50, 0.10, 0.25, 0.80);
    rotaryKnobFour.setBoundsRelative(0.75, 0.10, 0.25, 0.80);
}

void cRecievers::showConnectionErrorMessage(const juce::String &messageText)
{
    juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
          "Connection Error",
          messageText,
          "Ok");
}
