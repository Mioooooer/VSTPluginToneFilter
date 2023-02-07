/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

//==============================================================================
/**
*/
class ToneFilterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ToneFilterAudioProcessorEditor (ToneFilterAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~ToneFilterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ToneFilterAudioProcessor& audioProcessor;

    juce::AudioProcessorValueTreeState& valueTreeState;

    juce::Label mixLabel;
    juce::Slider mixSlider;
    std::unique_ptr<SliderAttachment> mixAttachment;

    ToneFilterAudioProcessor* getProcessor() const
    {
        return static_cast <ToneFilterAudioProcessor*> (getAudioProcessor());
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneFilterAudioProcessorEditor)
};
