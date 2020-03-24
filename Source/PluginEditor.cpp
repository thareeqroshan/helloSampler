/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HelloSamplerAudioProcessorEditor::HelloSamplerAudioProcessorEditor (HelloSamplerAudioProcessor& p)
    : AudioProcessorEditor (&p),mADSR(p), mWaveThumbnail(p),processor (p)
{
    addAndMakeVisible(mADSR);
    addAndMakeVisible(mWaveThumbnail);
    
    setSize (600, 400);
}

HelloSamplerAudioProcessorEditor::~HelloSamplerAudioProcessorEditor()
{
}

//==============================================================================
void HelloSamplerAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::black);
  
//    g.setColour(Colours::white);
//    g.setFont(15.0f);
//    //if we have a sound "sound loaded"
//    if(processor.getNumSamplerSounds() > 0)
//    {
//        g.fillAll(Colours::green);
//        g.drawText("Sound Loaded", getWidth()/2 -50, getHeight()/2 - 10, 100, 20, Justification::centred);
//    }
//    else
//    {
//        g.fillAll(Colours::red);
//        g.drawText("Load a Sound", getWidth()/2 -50, getHeight()/2 - 10, 100, 20, Justification::centred);
//    }
//
//    //else "load a sound"
}

void HelloSamplerAudioProcessorEditor::resized()
{
    //mLoadButton.setBounds(getWidth()/2 - 50, getHeight()/2 - 50, 100, 100);
    //auto bounds = getLocalBounds().toFloat();
    mADSR.setBoundsRelative(0.0f, 0.75f, 1.0f, 0.25f);
    mWaveThumbnail.setBoundsRelative(0.0f, 0.25f, 1.0f, 0.5f);
    
}

Image HelloSamplerAudioProcessorEditor::loadImage()
{
    //auto image = File::getSpecialLocation(File::SpecialLocationType::userDesktopDirectory);
    
   // image.getChildFile (<#StringRef relativeOrAbsolutePath#>)
}

