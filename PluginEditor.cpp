/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LowPassFilterAudioProcessorEditor::LowPassFilterAudioProcessorEditor (LowPassFilterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
   
	setSize(600, 200);
	

	cutoffDial.setSliderStyle(Slider::Rotary);
	cutoffDial.setRange(30.0f, 15000.0f, 1.0f);
	cutoffDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	cutoffDial.setTextValueSuffix(" Hz");
	cutoffDial.setValue(15000.0f);
	cutoffDial.setColour(Slider::rotarySliderOutlineColourId, Colours::white);
	cutoffDial.setColour(Slider::rotarySliderFillColourId, Colours::white);
	cutoffDial.setSkewFactor(0.5);
	addAndMakeVisible(&cutoffDial);
	cutoffDial.addListener(this);

	cutoffLabel.setText("Cutoff", dontSendNotification);
	cutoffLabel.attachToComponent(&cutoffDial, true);
	cutoffLabel.setColour(Label::textColourId, Colours::white);
	addAndMakeVisible(cutoffLabel);

	resDial.setSliderStyle(Slider::Rotary);
	resDial.setRange(0.0f, 5.0f, 0.01f);
	resDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	resDial.setValue(0.0f);
	resDial.setColour(Slider::rotarySliderOutlineColourId, Colours::white);
	resDial.setColour(Slider::rotarySliderFillColourId, Colours::white);
	addAndMakeVisible(&resDial);
	resDial.addListener(this);

	resLabel.setText("Resonance", dontSendNotification);
	resLabel.attachToComponent(&resDial, true);
	addAndMakeVisible(resLabel);

	
	//addAndMakeVisible(&filterTypeDropDown);
	filterTypeDropDown.addItem("Two-pole low-pass", 1);
	filterTypeDropDown.addItem("Four-pole low-pass", 2);
	filterTypeDropDown.addItem("Two-pole high-pass", 3);
	filterTypeDropDown.addItem("Four-pole high-pass", 4);
	filterTypeDropDown.setColour(ComboBox::outlineColourId, Colours::white);
	filterTypeDropDown.setColour(ComboBox::backgroundColourId, Colours::black);
	filterTypeDropDown.setColour(ComboBox::textColourId, Colours::white);
	filterTypeDropDown.setColour(ComboBox::buttonColourId, Colours::white);
	filterTypeDropDown.setSelectedId(1);

	
}

LowPassFilterAudioProcessorEditor::~LowPassFilterAudioProcessorEditor()
{
}

//==============================================================================
void LowPassFilterAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(Colours::black);

	
}

void LowPassFilterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	//cutoffDial.setBounds(50, 30, 20, getHeight() - 60);
	//resDial.setBounds(150, 30, 20, getHeight() - 60);

	cutoffLabel.setBounds(85, 358, 130, 20);
	cutoffDial.setBounds(50, 25, 135, 105);
	cutoffDial.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 75, 20);

	filterTypeDropDown.setBounds(210, 25, 150, 30);

	resLabel.setBounds(415, 85, 130, 20);
	resDial.setBounds(210, 25, 135, 105);
	resDial.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, true, 75, 20);
}

void LowPassFilterAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	if (slider == &cutoffDial)
	{
		processor.updateFilterFreq(cutoffDial.getValue());
	}
	else if (slider == &resDial)
	{
		processor.updateFilterRes(resDial.getValue());
	}
}

/*void LowPassFilterAudioProcessorEditor::ComboBoxChanged(ComboBox* comboBox)
{
	if (comboBox == &filterTypeDropDown)
		processor.setFilterType(filterTypeDropDown.getSelectedId());
}*/
