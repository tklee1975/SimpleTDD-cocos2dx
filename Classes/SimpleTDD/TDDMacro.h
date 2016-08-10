//
//  TDDMacro.h
//  SimpleTDD
//
//  Created by Ken Lee on 11/8/2016.
//
//

#ifndef TDDMacro_h
#define TDDMacro_h

#define CREATE_FUNC_WITH_SIZE(__TYPE__) \
static __TYPE__* create(const Size &size) \
{ \
__TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
if (pRet && pRet->initWithSize(size)) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = nullptr; \
return nullptr; \
} \
}


#endif /* TDDMacro_h */
