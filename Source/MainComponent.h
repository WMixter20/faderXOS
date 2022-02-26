#pragma once

#include <JuceHeader.h>

#include "cSenders.h"
#include "hSenders.h"
#include "pSenders.h"

#include "cRecievers.h"
#include "hRecievers.h"
#include "pRecievers.h"

#include "sendersControl.h"

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
        setSize (1200, 800);
        
        addAndMakeVisible(cSenders);
        addAndMakeVisible(hSenders);
        addAndMakeVisible(pSenders);
        
        addAndMakeVisible(cRecievers);
        addAndMakeVisible(hRecievers);
        addAndMakeVisible(pRecievers);

        addAndMakeVisible(TopTabs);
        addAndMakeVisible(BottomTabs);
        
        TopTabs.setTitle("Test 1");
        BottomTabs.setTitle("Test2");
        
        const auto tabColour1 = getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId).darker(0.1f);
        const auto tabColour2 = getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId).darker(0.1f);
        
        TopTabs.addTab("Senders Control", tabColour1, &sControl, false);
        
        TopTabs.addTab("Companion Senders", tabColour1, &cSenders, false);
        TopTabs.addTab("Hardware Senders", tabColour1, &hSenders, false);
        TopTabs.addTab("Program Senders", tabColour1, &pSenders, false);
        
        BottomTabs.addTab("Companion Recievers", tabColour2, &cRecievers, false);
        BottomTabs.addTab("Hardware Recievers", tabColour2, &hRecievers, false);
        BottomTabs.addTab("Program Recievers", tabColour2, &pRecievers, false);
        
        
    }
    //==============================================================================
    void paint (juce::Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    }

    void resized() override
    {
        auto bounds = getLocalBounds();
        auto lowerbounds = bounds.removeFromBottom(getHeight() / 2);
        
        TopTabs.setBounds(bounds);
        BottomTabs.setBounds(lowerbounds);
    }


private:
    //==============================================================================
    // Your private member variables go here...
    
    juce::TabbedComponent TopTabs{ juce::TabbedButtonBar::Orientation::TabsAtTop};
    juce::TabbedComponent BottomTabs{ juce::TabbedButtonBar::Orientation::TabsAtTop};
    
    cSenders cSenders;
    hSenders hSenders;
    pSenders pSenders;
    
    cRecievers cRecievers;
    hRecievers hRecievers;
    pRecievers pRecievers;

    sendersControl sControl;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
