#include "block.h"

void block::destroyAbove()
{
    a=aAir;
}

void block::addAbove(above ta)
{
    a=ta;
}

bool block::inable()
{
    return under.inable() && above.inable();
}

bool block::pushable()
{
    return above.pushable();
}

bool block::hidable()
{
    return under.s==tree;
}

bool block::haveAbove()
{
    return above!=air;
}

substance block::appearance()
{
    if(hidable())
        return substance(u.substance(),air);
    else
        return substance(u.substance(),a.substance());
}
