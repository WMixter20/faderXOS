/*
  ==============================================================================

    cSenders.cpp
    Created: 23 Feb 2022 11:16:54am
    Author:  Will Mixter

  ==============================================================================
*/

#include <JuceHeader.h>
#include "cSenders.h"

//==============================================================================
cSenders::cSenders()
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

           rotaryKnobTwo.setRange(0, 127);
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
           //==============================================================================


}

cSenders::~cSenders()
{
}

void cSenders::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("cSenders", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void cSenders::resized()
{
    rotaryKnobOne.setBoundsRelative(0.00, 0.10, 0.25, 0.80);
    rotaryKnobTwo.setBoundsRelative(0.25, 0.10, 0.25, 0.80);
    rotaryKnobThree.setBoundsRelative(0.50, 0.10, 0.25, 0.80);
    rotaryKnobFour.setBoundsRelative(0.75, 0.10, 0.25, 0.80);

}
