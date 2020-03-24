/*
  ==============================================================================

    WaveThumbnail.cpp
    Created: 25 Mar 2020 12:57:21am
    Author:  thareeqRoshsn

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WaveThumbnail.h"

//==============================================================================
WaveThumbnail::WaveThumbnail(HelloSamplerAudioProcessor& p): processor(p)
{
    mLoadButton.onClick = [&]() { processor.loadFile();};
    addAndMakeVisible(mLoadButton);
}

WaveThumbnail::~WaveThumbnail()
{
}

void WaveThumbnail::paint (Graphics& g)
{
    g.fillAll(Colours::red);

        g.setColour(Colours::white);
        
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
            auto point = jmap<float> (mAudioPoints[sample], -1.0f, 1.0f, getHeight(), 0);
            p.lineTo(sample, point);
        }
        g.strokePath(p, PathStrokeType(2));

}

void WaveThumbnail::resized()
{

}
bool WaveThumbnail::isInterestedInFileDrag(const StringArray &files)
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

void WaveThumbnail::filesDropped(const StringArray& files, int x, int y)
{
    for (auto file : files) {
        if(isInterestedInFileDrag(file))
        {
            processor.loadFile(file);
        }
    }
    repaint();
}

