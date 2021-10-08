/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"



//==============================================================================
/**
*/
class LowPassFilterAudioProcessorEditor  : public AudioProcessorEditor, private Slider::Listener
	
{
public:
    LowPassFilterAudioProcessorEditor (LowPassFilterAudioProcessor&);
	//LowPassFilterAudioProcessorEditor(LowPassFilterAudioProcessor & p, AudioProcessorValueTreeState & vts);
	~LowPassFilterAudioProcessorEditor();
	//typedef AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void sliderValueChanged(Slider* slider);
	//virtual void comboBoxChanged(ComboBox* comboBoxThatHasChanged) = 0;

private:
	//AudioProcessorValueTreeState& valueTreeState;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    LowPassFilterAudioProcessor& processor;
	Slider cutoffDial;
	Slider resDial;
	Label cutoffLabel;
	Label resLabel;
	ComboBox filterTypeDropDown;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LowPassFilterAudioProcessorEditor)
};
