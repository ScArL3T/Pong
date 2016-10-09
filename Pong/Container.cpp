#include "Container.hpp"

Container::Container()
	: widgets()
	, selectedWidget(-1)
{
}

void Container::handleKeyboard(const sf::Event &event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
		{
			selectPrevious();
		}
		else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
		{
			selectNext();
		}
		else if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
		{
			if (hasSelection())
				widgets[selectedWidget]->activate();
		}
	}
}

void Container::handleEvent(const sf::Event &event)
{
	for (const Widget::Ptr &w : widgets)
		w->handleEvent(event);
}

const bool Container::isSelectable() const
{
	return false;
}

Widget &Container::getWidget(const std::string &name) const
{
	for (const auto &w : widgets)
		if (w->getName() == name)
			return *w;
}

void Container::addWidget(Widget::Ptr widget)
{
	widgets.push_back(widget);
	widgets.back()->setParent(this);

	if (!hasSelection() && widget->isSelectable())
		select(widgets.size() - 1);
}

void Container::removeWidget(Widget::Ptr widget)
{
	for (unsigned int i = 0; i<widgets.size(); ++i)
	{
		if (widgets[i] == widget)
		{
			if (selectedWidget == i)
			{
				widgets[i]->deselect();
				if (widgets.size() > 1)
					selectNext();
				else selectedWidget = -1;
			}
			else if (selectedWidget > static_cast<int>(i))
				selectedWidget--;

			widgets.erase(widgets.begin() + i);
			return;
		}
	}
}

void Container::clear()
{
	if (hasSelection())
		widgets[selectedWidget]->deselect();

	widgets.clear();
	selectedWidget = -1;
}

void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	for (const Widget::Ptr &w : widgets)
		target.draw(*w, states);
}

const bool Container::hasSelection() const
{
	return selectedWidget >= 0;
}

void Container::select(unsigned int index)
{
	if (widgets[index]->isSelectable())
	{
		if (hasSelection())
			widgets[selectedWidget]->deselect();

		widgets[index]->select();
		selectedWidget = index;
	}
}

void Container::selectNext()
{
	if (!hasSelection())
		return;
	
	int next = selectedWidget;
	do
		next = (next + 1) % widgets.size();
	while (!widgets[next]->isSelectable());

	select(next);
}

void Container::selectPrevious()
{
	if (!hasSelection())
		return;

	int prev = selectedWidget;
	do
		prev = (prev + widgets.size() - 1) % widgets.size();
	while (!widgets[prev]->isSelectable());

	select(prev);
}