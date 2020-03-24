/*
  ==============================================================================

    WaveThumbnail.h
    Created: 25 Mar 2020 12:57:21am
    Author:  thareeqRoshsn

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
    
    //File Drag and Drop target
    bool isInterestedInFileDrag (const StringArray& files) override;
    void filesDropped (const StringArray& files, int x, int y) override;

private:
    TextButton mLoadButton {"Load"};
    std::vector<float> mAudioPoints;
    
    HelloSamplerAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveThumbnail)
};
