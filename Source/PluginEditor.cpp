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
    : AudioProcessorEditor (&p), processor (p)
{
    mLoadButton.onClick = [&]() { processor.loadFile();};
    addAndMakeVisible(mLoadButton);
    
    mAttackSlider.setSliderStyle (Slider::SliderStyle::RotaryVerticalDrag);
    mAttackSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    mAttackSlider.setColour(Slider::ColourIds::thumbColourId, Colours::red);
    mAttackSlider.setRange (0.0f, 5.0f,0.01f);
    mAttackSlider.addListener(this);
    addAndMakeVisible(mAttackSlider);
    
    mAttackLabel.setFont(10.0f);
    mAttackLabel.setText("Attack", NotificationType::dontSendNotification);
    mAttackLabel.setColour(Label::ColourIds::textColourId, Colours::green);
    mAttackLabel.setJustificationType(Justification::centredTop);
    mAttackLabel.attachToComponent(&mAttackSlider, false);
    
    mDecaySlider.setSliderStyle (Slider::SliderStyle::RotaryVerticalDrag);
    mDecaySlider.setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    mDecaySlider.setColour(Slider::ColourIds::thumbColourId, Colours::red);
    mDecaySlider.setRange (0.0f, 5.0f,0.01f);
    mDecaySlider.addListener(this);
    addAndMakeVisible(mDecaySlider);
    
    mDecayLabel.setFont(10.0f);
    mDecayLabel.setText("Decay", NotificationType::dontSendNotification);
    mDecayLabel.setColour(Label::ColourIds::textColourId, Colours::green);
    mDecayLabel.setJustificationType(Justification::centredTop);
    mDecayLabel.attachToComponent(&mDecaySlider, false);
    
    mSustainSlider.setSliderStyle (Slider::SliderStyle::RotaryVerticalDrag);
    mSustainSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    mSustainSlider.setColour(Slider::ColourIds::thumbColourId, Colours::red);
    mSustainSlider.setRange (0.0f, 1.0f,0.01f);
    mSustainSlider.addListener(this);
    addAndMakeVisible(mSustainSlider);
    
    mSustainLabel.setFont(10.0f);
    mSustainLabel.setText("Sustain", NotificationType::dontSendNotification);
    mSustainLabel.setColour(Label::ColourIds::textColourId, Colours::green);
    mSustainLabel.setJustificationType(Justification::centredTop);
    mSustainLabel.attachToComponent(&mSustainSlider, false);
    
    mReleaseSlider.setSliderStyle (Slider::SliderStyle::RotaryVerticalDrag);
    mReleaseSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 40, 20);
    mReleaseSlider.setColour(Slider::ColourIds::thumbColourId, Colours::red);
    mReleaseSlider.setRange (0.0f, 5.0f,0.01f);
    mReleaseSlider.addListener(this);
    addAndMakeVisible(mReleaseSlider);
    
    mReleaseLabel.setFont(10.0f);
    mReleaseLabel.setText("Release", NotificationType::dontSendNotification);
    mReleaseLabel.setColour(Label::ColourIds::textColourId, Colours::green);
    mReleaseLabel.setJustificationType(Justification::centredTop);
    mReleaseLabel.attachToComponent(&mReleaseSlider, false);
    
    setSize (600, 200);
}

HelloSamplerAudioProcessorEditor::~HelloSamplerAudioProcessorEditor()
{
}

//==============================================================================
void HelloSamplerAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colours::black);
    g.setColour(Colours::white);
    if(mShouldbePainting)
    {
        Path p;
        mAudioPoints.clear();
        auto waveform = processor.getWaveForm();
        auto ratio = waveform.getNumSamples()/getWidth();
        auto buffer = waveform.getReadPointer(0);
        for (int sample =0; sample < waveform.getNumSamples(); sample+= ratio)
        {
            mAudioPoints.push_back(buffer[sample]);
        }
        
        p.startNewSubPath(0, getHeight()/2);
        
        for (int sample = 0 ; sample< mAudioPoints.size(); ++sample)
        {
            auto point = jmap<float> (mAudioPoints[sample], -1.0f, 1.0f, 200, 0);
            p.lineTo(sample, point);
        }
        g.strokePath(p, PathStrokeType(2));
        mShouldbePainting = false;
    }
    
  
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
    const auto startX = 0.6f;
    const auto startY = 0.6f;
    const auto dialWidth = 0.1f;
    const auto dialHeight = 0.4f;
    
    mAttackSlider.setBoundsRelative(startX, startY, dialWidth, dialHeight);
    mDecaySlider.setBoundsRelative(startX + dialWidth, startY, dialWidth, dialHeight);
    mSustainSlider.setBoundsRelative(startX + 2 * dialWidth, startY, dialWidth, dialHeight);
    mReleaseSlider.setBoundsRelative(startX + 3 * dialWidth, startY, dialWidth, dialHeight);
}

bool HelloSamplerAudioProcessorEditor::isInterestedInFileDrag(const StringArray &files)
{
    for (auto file : files)
    {
        if(file.contains(".wav") || file.contains(".mp3") || file.contains(".aif"))
        {
            return true;
        }
    }
    
    return false;
}

void HelloSamplerAudioProcessorEditor::filesDropped(const StringArray& files, int x, int y)
{
    for (auto file : files) {
        if(isInterestedInFileDrag(file))
        {
            mShouldbePainting = true;
            processor.loadFile(file);
        }
    }
    repaint();
}

void HelloSamplerAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &mAttackSlider)
    {
        processor.getADSRParams().attack = mAttackSlider.getValue();
    }
    else if (slider == &mDecaySlider)
    {
        processor.getADSRParams().decay = mDecaySlider.getValue();
    }
    else if (slider ==  &mSustainSlider)
    {
        processor.getADSRParams().sustain = mSustainSlider.getValue();
    }
    else if (slider == &mReleaseSlider)
    {
        processor.getADSRParams().release = mReleaseSlider.getValue();
    }
    processor.updateADSRValue();
}
