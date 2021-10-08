/*
  ==============================================================================

    moog.h
    Created: 4 Dec 2018 6:58:29pm
    Author:  Levi

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Moog 
{
public:
	Moog()
	{

		frequency = 500.0f;
		res = 0.707f;
		/*
		filterMenu.addItem("Two-pole low-pass", 1);
		filterMenu.addItem("Four-pole low-pass", 2);
		filterMenu.addItem("Two-pole high-pass", 3);
		filterMenu.addItem("Four-pole high-pass", 4);
		filterMenu.setJustificationType(Justification::centred);
		*/
	}
    ~Moog();

	float process4pLowPass(float in);
	float process2pLowPass(float in);
	float process4pHighPass(float in);
	float process2pHighPass(float in);
	void init(double sampleRate);
	void calc();
	void updateFreq(float freq);
	void updateRes(float resonance);
	void updateFilterType(int ID);

    //void paint (Graphics&) override;
   // void resized() override;

private:
	double sampleRate;
	float b, c, g, omega, gg, out, gRes, gComp = 0.0f;
	float frequency, res, input, inputA, output;
	float A, B, C, D, E;
	float oldX[3];
	float oldY[3];
	float x[3];
	int filterID;
	//ComboBox filterMenu;

    //JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Moog)
};
