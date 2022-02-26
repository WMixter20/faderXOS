/*
  ==============================================================================

    sendersControl.cpp
    Created: 25 Feb 2022 5:15:46pm
    Author:  Will Mixter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "sendersControl.h"

//==============================================================================
sendersControl::sendersControl()
{
    addAndMakeVisible (connectToPort);
    connectToPort.setButtonText ("Check the time...");
    connectToPort.removeListener(this);

    addAndMakeVisible (timeLabel);
    timeLabel.setColour (juce::Label::backgroundColourId, juce::Colours::black);
    timeLabel.setColour (juce::Label::textColourId, juce::Colours::white);
    timeLabel.setJustificationType (juce::Justification::centred);

    setSize (600, 110);

}

void sendersControl::buttonClicked(juce::Button *button)
{
    if (button == &connectToPort)
            {
                juce::String cMessage1 = ("Hello");
                cSendersIP.messages(cMessage1);
            }
}

void sendersControl::resized()
{
    connectToPort.setBoundsRelative(0.00, 0.10, 0.25, 0.80);
}
