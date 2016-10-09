#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <SFML/Graphics.hpp>

#include <memory>

class Container;

class Widget : public sf::Drawable, public sf::Transformable
{
public:
	using Ptr = std::shared_ptr<Widget>;

	Widget();
	virtual ~Widget() = default;

	Widget(const Widget&) = default;
	Widget(Widget&&) = default;
	Widget& operator=(const Widget&) = default;
	Widget& operator=(Widget&&) = default;

	void setName(const std::string &name);
	void setParent(Container *parent);

	const std::string &getName() const;

	virtual void handleEvent(const sf::Event &event) = 0;
	virtual const bool isSelectable() const = 0;

	virtual void select();
	virtual void deselect();

	virtual void activate();
	virtual void deactivate();

	const bool isSelected() const;
	const bool isActive() const;

private:
	bool selected;
	bool active;
	std::string name;

	Container *parent;
};

#endif