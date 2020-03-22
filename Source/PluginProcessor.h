/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class HelloSamplerAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    HelloSamplerAudioProcessor();
    ~HelloSamplerAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void loadFile();
    void loadFile(const String& path);
    
    int getNumSamplerSounds() {return mSampler.getNumSounds();}
    AudioBuffer<float>& getWaveForm() {return mWaveForm;}
    
    void updateADSRValue();
    
    ADSR::Parameters& getADSRParams(){return mADSRParams;}
    
    float attack {0.0f};
    float decay {0.0f};
    float sustain {0.0f};
    float release {0.0f};
private:
    Synthesiser mSampler;
    const int mNumVoices {3};
    AudioBuffer<float> mWaveForm;
    
    ADSR::Parameters mADSRParams;
    
    AudioFormatManager mFormatManager;
    AudioFormatReader* mFormatReader { nullptr};
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelloSamplerAudioProcessor)
};
