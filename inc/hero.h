#pragma once

#include "herotemplate.h"
#include "stats.h"

class Hero
{
private:
    HeroTemplate *heroTemplate;
    Stats *stats;

public:
    Hero(HeroTemplate *_templ = nullptr);
    ~Hero();

    Stats& getStats();  // return stats
    Stats& getTemplateStats();  // return heroTemplate->getStats
    Resources& getResources();
};
