#include "inc/herogroup.h"

HeroGroup::HeroGroup()
    : front1(nullptr), front2(nullptr), front3(nullptr),
      back1(nullptr), back2(nullptr), back3(nullptr)
{

}

Hero* HeroGroup::at(HeroPosition pos) const
{
    switch(pos)
    {
    case HeroPosition::NONE:
        return nullptr;
    case HeroPosition::front1:
        return front1;
    case HeroPosition::front2:
        return front2;
    case HeroPosition::front3:
        return front3;
    case HeroPosition::back1:
        return back1;
    case HeroPosition::back2:
        return back2;
    case HeroPosition::back3:
        return back3;
    default:
        return nullptr;
    }
}

HeroPosition HeroGroup::find(Hero *hero) const
{
    if(hero == nullptr)
        return HeroPosition::NONE;

    if(hero == front1)
        return HeroPosition::front1;

    if(hero == front2)
        return HeroPosition::front2;

    if(hero == front3)
        return HeroPosition::front3;

    if(hero == back1)
        return HeroPosition::back1;

    if(hero == back2)
        return HeroPosition::back2;

    if(hero == back3)
        return HeroPosition::back3;

    return HeroPosition::NONE;
}

void HeroGroup::set(HeroPosition pos, Hero *hero)
{
    switch(pos)
    {
    case HeroPosition::front1:
        front1 = hero;
    case HeroPosition::front2:
        front2 = hero;
    case HeroPosition::front3:
        front3 = hero;
    case HeroPosition::back1:
        back1 = hero;
    case HeroPosition::back2:
        back2 = hero;
    case HeroPosition::back3:
        back3 = hero;
    }
}

int HeroGroup::count()
{
    int num = 0;

    if(front1 != nullptr)
        ++num;

    if(front2 != nullptr)
        ++num;

    if(front3 != nullptr)
        ++num;

    if(back1 != nullptr)
        ++num;

    if(back2 != nullptr)
        ++num;

    if(back3 != nullptr)
        ++num;

    return num;
}

bool HeroGroup::isFull()
{
    return count() == 6;
}
