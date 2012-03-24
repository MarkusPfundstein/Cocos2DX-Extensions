//
//  CCXNumber.h
//  cocos2d - CCXExtensions
//
//  Created by Markus Pfundstein on 3/23/12.
//  Copyright (c) 2012 Eagerheads. All rights reserved.
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
            _typeT _validate;
            validateType(_validate);
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
        // types allowed by the template class. 
        void validateType(short  &s) const {};
        void validateType(int    &i) const {};
        void validateType(long   &l) const {};
        void validateType(double &d) const {};
        void validateType(float  &f) const {};
        void validateType(unsigned short &us) const {};
        void validateType(unsigned int &ui) const {};
        void validateType(unsigned long &ul) const {};
        void validateType(unsigned long long &ull) const {};
    };
    
}   // namespace

#endif
