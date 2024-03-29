#include "SequenceHeadersSection.h"
#include "Util/Colors.h"
#include "../Views/SequenceHeaderView.h"
#include "../ZoomState/ZoomState.h"


using namespace Timeline;

SequenceHeadersSection::SequenceHeadersSection(Timeline::ZoomState& zoomState)
: Timeline::ViewportSection(zoomState)
{
	mSequenceHeaderView = std::make_unique<SequenceHeaderView>();
	mSequenceHeaderView->setSize(100, 1000);
	
	mViewport->setViewedComponent(mSequenceHeaderView.get());
	mViewport->setScrollBarsShown(false, false);
	addAndMakeVisible(mViewport.get());
}

SequenceHeadersSection::~SequenceHeadersSection()
{

}

void SequenceHeadersSection::paint(juce::Graphics& g)
{
	g.fillAll(Colors::getColor(Colors::ColorID::emptySectionBkgd));
	
	g.setColour(Colors::getColor(Colors::ColorID::emptySectionOutline));
	g.drawRect(this->getLocalBounds());
}

void SequenceHeadersSection::resized()
{
	auto bounds = this->getLocalBounds();
	mViewport->setBounds(bounds);
}

//============
void SequenceHeadersSection::setViewPosition(int x, int y)
{
	mViewport->setViewPosition(x, y);
}
