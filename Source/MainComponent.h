#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component

{
public:
    //==============================================================================
    MainComponent()
    {
        setSize (600, 400);
    }

    ~MainComponent() override
    {
    }

    //==============================================================================
    void paint (juce::Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

        g.setFont (juce::Font (16.0f));
        g.setColour (juce::Colours::white);
        g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
    }

    void resized() override
    {
        // This is called when the MainComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
    }


private:
    //==============================================================================
    // Your private member variables go here...
    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
