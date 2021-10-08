
#include "../JuceLibraryCode/JuceHeader.h"
#include "moog.h"
#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================

Moog::~Moog()
{
}

void Moog::updateFreq(float freq)
{
	frequency = freq;
	calc();
}

void Moog::updateRes(float resonance)
{
	res = resonance;
	calc();
}

float Moog::process4pHighPass(float in)
{
	A = 1.0f;
	B = -4.0f;
	C = 6.0f;
	D = -4.0f;
	E = 1.0f;

	input = tanh(in - (4.0f * gRes) * (oldY[3] - (gComp * in)));
	inputA = A * input;

	for (int i = 0; i < 3; ++i)
	{
		output = (((input * b + oldX[i] * c - oldY[i]) * g) + oldY[i]);
		oldX[i] = input;
		oldY[i] = output;
		input = output;
	}

	output += inputA + (oldY[0] * B) + (oldY[1] * C) + (oldY[2] * D) + (oldY[3] * E);

	return output;
}

float Moog::process2pHighPass(float in)
{
	A = 1.0f;
	B = -2.0f;
	C = 1.0f;

	input = tanh(in - (4.0f * gRes) * (oldY[1] - (gComp * in)));
	inputA = A * input;

	for (int i = 0; i < 1; ++i)
	{
		output = (((input * b + oldX[i] * c - oldY[i]) * g) + oldY[i]);
		oldX[i] = input;
		oldY[i] = output;
		input = output;
	}

	output += inputA + (oldY[0] * B) + (oldY[1] * C);

	return output;
}

float Moog::process4pLowPass(float in)
{
	A = 0.0f;
	B = 0.0f;
	C = 0.0f;
	D = 0.0f;
	E = 1.0f;

	input = tanh(in - (4.0f * gRes) * (oldY[3] - (gComp * in)));
	inputA = A * input;

	for (int i = 0; i < 3; ++i)
	{
		output = (((input * b + oldX[i] * c - oldY[i]) * g) + oldY[i]);
		oldX[i] = input;
		oldY[i] = output;
		input = output;
	}

	output += inputA + (oldY[0] * B) + (oldY[1] * C) + (oldY[2] * D) + (oldY[3] * E);

	return output;
}

float Moog::process2pLowPass(float in)
{
	A = 0.0f;
	B = 0.0f;
	C = 1.0f;

	input = tanh(in - (4.0f * gRes) * (oldY[1] - (gComp * in)));
	inputA = A * input;

	for (int i = 0; i < 1; ++i)
	{
		output = (((input * b + oldX[i] * c - oldY[i]) * g) + oldY[i]);
		oldX[i] = input;
		oldY[i] = output;
		input = output;
	}

	output += inputA + (oldY[0] * B) + (oldY[1] * C);

	return output;
}

void Moog::init(double sRate)
{
	sampleRate = sRate;
	calc();
}

void Moog::calc()
{
	b = 1.0f / 1.3f;
	c = 0.3f / 1.3f;
	omega = ((2.0f * float_Pi) * frequency) / sampleRate;
	g = (0.9892f * omega) - (0.4342f * omega * omega) + (0.1381f * omega * omega * omega) - (0.0202f * omega * omega * omega * omega);
	gComp = 0.5;
	gRes = res * (1.0029f + (0.0526f * omega) - (0.0926f * omega * omega) + (0.0218f * omega * omega * omega));
}