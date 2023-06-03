
#pragma once
#include <Util/Juce_Header.h>

namespace Timeline
{


class SequenceHeaderView : public juce::Component
{
public:
	SequenceHeaderView();
	~SequenceHeaderView();
	
	void paint(juce::Graphics& g) override;
	void resized() override;
private:
	
};

}
