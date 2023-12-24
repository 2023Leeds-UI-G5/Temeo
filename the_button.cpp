//
//
//

#include "the_button.h"


void TheButton::init(const TheButtonInfo *i)
{
    info = const_cast<TheButtonInfo*>(i);
    setIcon(*(info->icon));
}


void TheButton::clicked()
{
    emit jumpTo(info);
}
