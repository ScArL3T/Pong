#include "Widget.hpp"

Widget::Widget()
	: selected(false)
	, active(true)
	, parent(nullptr)
{
}

void Widget::setName(const std::string &name)
{
	this->name = name;
}

void Widget::setParent(Container *parent)
{
	this->parent = parent;
}

const std::string &Widget::getName() const
{
	return name;
}

void Widget::select()
{
	selected = true;
}

void Widget::deselect()
{
	selected = false;
}

void Widget::activate()
{
	active = true;
}

void Widget::deactivate()
{
	active = false;
}

const bool Widget::isSelected() const
{
	return selected;
}

const bool Widget::isActive() const
{
	return active;
}