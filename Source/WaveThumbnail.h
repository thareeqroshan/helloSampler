/*
  ==============================================================================

    WaveThumbnail.h
    Created: 23 May 2020 4:12:11pm
    Author:  thare

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class WaveThumbnail    : public Component,
                         public FileDragAndDropTarget
{
public:
    WaveThumbnail(HelloSamplerAudioProcessor&);
    ~WaveThumbnail();

    void paint (Graphics&) override;
    void resized() override;
    bool isInterestedInFileDrag(const StringArray& files) override;
    void filesDropped(const StringArray& files, int x, int y) override;

private:
    std::vector<float> mAudioPoints;
    bool mShouldbePainting{ false };
    String mFileName { "" };

    HelloSamplerAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveThumbnail)
};
