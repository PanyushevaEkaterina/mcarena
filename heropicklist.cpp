#include "inc/heropicklist.h"
#include "inc/selectiongui.h"
#include "inc/selectionmodel.h"

HeroPicklist::HeroPicklist(HeroVector *heroVector) :
    pendingImage(sfg::Image::Create()),
    pendingImage2(sfg::Image::Create()),
    activeHeroNumber(-1)
{
    int i=0;
    for(auto it = heroVector->begin(), end = heroVector->end(); it != end; it++)
    {
        sfg::Image::Ptr newImage = sfg::Image::Create((*it)->getResources().getImage());
        this->Attach(newImage,sf::Rect<sf::Uint32>( i%2, floor(i/2+0.5), 1, 1),sfg::Table::FILL, sfg::Table::FILL);
        i++;
    }
}
