/*
  ==============================================================================

    WaveThumbnail.cpp
    Created: 23 May 2020 4:12:11pm
    Author:  thare

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WaveThumbnail.h"

//==============================================================================
WaveThumbnail::WaveThumbnail(HelloSamplerAudioProcessor& p) : processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

WaveThumbnail::~WaveThumbnail()
{
}

void WaveThumbnail::paint (Graphics& g)
{
    g.fillAll(Colours::cadetblue.darker());
    auto waveform = processor.getWaveForm();

    if (waveform.getNumSamples() > 0)
    {
        Path p;
        mAudioPoints.clear();
        auto ratio = waveform.getNumSamples() / getWidth();
        auto buffer = waveform.getReadPointer(0);
        for (int sample = 0; sample < waveform.getNumSamples(); sample += ratio)
        {
            mAudioPoints.push_back(buffer[sample]);
        }
        g.setColour(Colours::yellow);

        p.startNewSubPath(0, getHeight() / 2);

        for (int sample = 0; sample < mAudioPoints.size(); ++sample)
        {
            auto point = jmap<float>(mAudioPoints[sample], -1.0f, 1.0f, getHeight(), 0);
            p.lineTo(sample, point);
        }
        g.strokePath(p, PathStrokeType(2));
        g.setColour(Colours::white);
        g.setFont(15.0f);
        auto textBounds = getLocalBounds().reduced(10, 10);
        g.drawFittedText(mFileName, textBounds, Justification::topRight, 1);
    }
    else {
        g.setColour(Colours::white);
        g.setFont(40.0f);
        g.drawFittedText("Drop an audio file to load", getLocalBounds(), Justification::centred, 1);
    }

}

void WaveThumbnail::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

bool WaveThumbnail::isInterestedInFileDrag(const StringArray& files)
{
    for (auto file : files)
    {
        if (file.contains(".wav") || file.contains(".mp3") || file.contains(".aif"))
        {
            return true;
        }
    }

    return false;
}

void WaveThumbnail::filesDropped(const StringArray& files, int x, int y)
{
    for (auto file : files) {
        if (isInterestedInFileDrag(file))
        {
            auto myFile = std::make_unique<File>(file);
            mFileName = myFile->getFileNameWithoutExtension();

            processor.loadFile(file);
        }
    }
    repaint();
}
