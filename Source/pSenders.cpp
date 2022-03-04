/*
  ==============================================================================

    pSenders.cpp
    Created: 23 Feb 2022 11:17:53am
    Author:  Will Mixter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "pSenders.h"

//==============================================================================
pSenders::pSenders()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
           //==============================================================================
           senderLabelOne.attachToComponent(&rotaryKnobOne, false);
           addAndMakeVisible (senderLabelOne);

           rotaryKnobOne.setRange(0, 127);
           rotaryKnobOne.setSliderStyle(juce::Slider::RotaryVerticalDrag);
           rotaryKnobOne.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 150, 25);
           addAndMakeVisible(rotaryKnobOne);

           senderLabelTwo.attachToComponent(&rotaryKnobTwo, false);
           addAndMakeVisible(senderLabelTwo);

           rotaryKnobTwo.setRange(-70, 10);
           rotaryKnobTwo.setSliderStyle(juce::Slider::RotaryVerticalDrag);
           rotaryKnobTwo.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 150, 25);
           addAndMakeVisible(rotaryKnobTwo);

           senderLabelThree.attachToComponent(&rotaryKnobThree, false);
           addAndMakeVisible(senderLabelThree);

           rotaryKnobThree.setRange(0, 127);
           rotaryKnobThree.setSliderStyle(juce::Slider::RotaryVerticalDrag);
           rotaryKnobThree.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 150, 25);
           addAndMakeVisible(rotaryKnobThree);

           senderLabelFour.attachToComponent(&rotaryKnobFour, false);
           addAndMakeVisible(senderLabelFour);

           rotaryKnobFour.setRange(0, 127);
           rotaryKnobFour.setSliderStyle(juce::Slider::RotaryVerticalDrag);
           rotaryKnobFour.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 150, 25);
           addAndMakeVisible(rotaryKnobFour);
    
           addAndMakeVisible(senderIPLabel);
           addAndMakeVisible(senderMessageOne);
           addAndMakeVisible(senderMessageTwo);
           addAndMakeVisible(senderMessageThree);
           addAndMakeVisible(senderMessageFour);
    
           //==============================================================================

            rotaryKnobOne.onValueChange = [this]                                                    //OSC Message of Knob 1
                {
                if (!senderOne.send( message1))
                    showConnectionErrorMessage("Error: could not send OSC message.");
               
                };
                if (!senderOne.connect(targetIp, portNum))                                             //Target/Port of Knob 1 for TouchOSC
                    showConnectionErrorMessage("Error: could not connect to UDP port ");


           
            //==============================================================================

            rotaryKnobTwo.onValueChange = [this]                                                   //OSC Message of Knob 2
                {
                if (!senderTwo.send( message2, (float)rotaryKnobTwo.getValue()))
                    showConnectionErrorMessage("Error: could not send OSC message.");
                };

                if (!senderTwo.connect(targetIp, portNum))                                             //Target/Port of Knob 2
                showConnectionErrorMessage("Error: could not connect to UDP port ");

            //==============================================================================

            rotaryKnobThree.onValueChange = [this]                                                 //OSC Message of Knob 3
                {
                if (!senderThree.send( message3, (float)rotaryKnobThree.getValue()))
                    showConnectionErrorMessage("Error: could not send OSC message.");
                };

                if (!senderThree.connect(targetIp, portNum))                                           //Target/Port of Knob 3
                showConnectionErrorMessage("Error: could not connect to UDP port ");

            //==============================================================================

            rotaryKnobFour.onValueChange = [this]                                                  //OSC Message of Knob 4
                {
                if (!senderFour.send( message4, (float)rotaryKnobFour.getValue()))
                    showConnectionErrorMessage("Error: could not send OSC message.");
                };

                if (!senderFour.connect(targetIp, portNum))                                            //Target/Port of Knob 4
                showConnectionErrorMessage("Error: could not connect to UDP port ");
         

}

void pSenders::resized()
{
    rotaryKnobOne.setBoundsRelative(0.00, 0.10, 0.25, 0.80);
    rotaryKnobTwo.setBoundsRelative(0.25, 0.10, 0.25, 0.80);
    rotaryKnobThree.setBoundsRelative(0.50, 0.10, 0.25, 0.80);
    rotaryKnobFour.setBoundsRelative(0.75, 0.10, 0.25, 0.80);
    
    senderIPLabel.setBoundsRelative(0.01, 0.85, 0.25, 0.20);
    senderMessageOne.setBoundsRelative(0.08, 0.70, 0.25, 0.20);
    senderMessageTwo.setBoundsRelative(0.35, 0.70, 0.25, 0.20);
    senderMessageThree.setBoundsRelative(0.60, 0.70, 0.25, 0.20);
    senderMessageFour.setBoundsRelative(0.85, 0.70, 0.25, 0.20);

}
void pSenders::showConnectionErrorMessage(const juce::String &messageText)
{
    juce::AlertWindow::showMessageBoxAsync(juce::AlertWindow::WarningIcon,
          "Connection Error",
          messageText,
          "Ok");
}
