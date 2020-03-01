#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SineDistortionAudioProcessor : public AudioProcessor {
public:
	SineDistortionAudioProcessor();
	~SineDistortionAudioProcessor();

	void prepareToPlay(double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
#endif

	void processBlock(AudioBuffer<float>&, MidiBuffer&) override;

	AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override;

	const String getName() const override;

	bool acceptsMidi() const override;
	bool producesMidi() const override;
	bool isMidiEffect() const override;
	double getTailLengthSeconds() const override;

	int getNumPrograms() override;
	int getCurrentProgram() override;
	void setCurrentProgram(int index) override;
	const String getProgramName(int index) override;
	void changeProgramName(int index, const String& newName) override;

	void getStateInformation(MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

	LinearSmoothedValue<float> knobGain;
	LinearSmoothedValue<float> knobDryWet;

	AudioProcessorValueTreeState apvts;
	AudioProcessorValueTreeState::ParameterLayout createParameters();

private:
	float gain;
	float dryWet;
	float temporarySound;
	float originalSound;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SineDistortionAudioProcessor)
};