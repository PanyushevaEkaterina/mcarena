#pragma once
#include "herovector.h"

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/Box.hpp>
#include <SFGUI/Button.hpp>
#include <SFGUI/Window.hpp>
#include <SFML/Graphics.hpp>

class HeroPicklist : public sfg::Table
{
private:
    int activeHeroNumber;
    sfg::Image::Ptr pendingImage, pendingImage2;

    void heroChosen(int);
public:
    HeroPicklist(HeroVector*);
    void highlight();
    void getActiveNum();
};

