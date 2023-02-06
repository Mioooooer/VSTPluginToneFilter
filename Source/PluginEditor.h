/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ToneFilterAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                        private juce::Slider::Listener
{
public:
    ToneFilterAudioProcessorEditor (ToneFilterAudioProcessor&);
    ~ToneFilterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ToneFilterAudioProcessor& audioProcessor;
    juce::Label mixLabel;
    juce::Slider mixSlider;

    ToneFilterAudioProcessor* getProcessor() const
    {
        return static_cast <ToneFilterAudioProcessor*> (getAudioProcessor());
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneFilterAudioProcessorEditor)
};
