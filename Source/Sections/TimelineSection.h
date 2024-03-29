#pragma once
#include <Util/Juce_Header.h>

// Forward declaration
namespace Timeline
{

class TimeRulerSection;
class SequenceHeadersSection;
class DocumentSection;
class ZoomControlsSection;
class ZoomState;
class Document;



class TimelineSection : public juce::Component
, public juce::ScrollBar::Listener
{
public:
	TimelineSection();
	~TimelineSection() override;
	
	void paint(juce::Graphics& g) override;
	void resized() override;
	
	void scrollBarMoved(juce::ScrollBar* scrollBarThatMoved, double newRangeStart) override;
	
	/**
		CONTRACTED FUNCTIONS:
		I promise that these functions will resize the child components that are ZoomStateListeners correctly according to the current ZoomState.
		I promise these functions will update mZoomState (which promises to convert to pixPerSecond etc.)
	 */
	void setHorizontalZoomFactor(double zoomFactor);
	void setVerticalZoomFactor(double zoomFactor);
	
	void loadDocument(Timeline::Document& document);

private:
	std::unique_ptr<Timeline::ZoomState>				mZoomState;
	
	std::unique_ptr<Timeline::TimeRulerSection> 		mTimeRulerSection;
	std::unique_ptr<Timeline::SequenceHeadersSection> 	mSequenceHeadersSection;
	std::unique_ptr<Timeline::DocumentSection>			mDocumentSection;
	std::unique_ptr<Timeline::ZoomControlsSection> 		mZoomControlsSection;
	

	
	
	
};

}
