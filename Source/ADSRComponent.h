/*
  ==============================================================================

    ADSRComponent.h
    Created: 25 Mar 2020 12:31:32am
    Author:  thareeqRoshsn

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class ADSRComponent    : public Component
{
public:
    ADSRComponent(HelloSamplerAudioProcessor&);
    ~ADSRComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    Slider mAttackSlider, mDecaySlider, mSustainSlider, mReleaseSlider;
    Label mAttackLabel, mDecayLabel, mSustainLabel, mReleaseLabel;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mAttackAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mDecayAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mSustainAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mReleaseAttachment;
    
    HelloSamplerAudioProcessor& processor;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};
