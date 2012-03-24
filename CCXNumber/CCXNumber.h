//
//  CCXNumber.h
//  Jade Warrior
//
//  Created by Markus Pfundstein on 3/23/12.
//  Copyright (c) 2012 The Saints. All rights reserved.
//

#ifndef Jade_Warrior_CCXNumber_h
#define Jade_Warrior_CCXNumber_h

#include "cocos2d.h"

namespace cocos2d_extensions {
    
    template <class _typeT = int>
    class CCXNumber : public cocos2d::CCObject
    {
    public:
        CCXNumber() 
        : cocos2d::CCObject(),
        m_type(0)
        {
            
        }
        
        static CCXNumber* numberWithValue(_typeT value)
        {
            CCXNumber<_typeT> *newNumber = new CCXNumber<_typeT>;
            newNumber->initWithValue(value);
            newNumber->autorelease();
            return newNumber;
        }
        
        virtual bool initWithValue(_typeT value)
        {
            m_type = value;
            return true;
        }
        
        CC_SYNTHESIZE_READONLY(_typeT, m_type, Value);
        
    protected:
        virtual ~CCXNumber()
        {
            
        }
        
    private:
        
    };
    
}   // namespace

#endif
