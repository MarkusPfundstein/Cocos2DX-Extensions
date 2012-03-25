//
//  CCNumber.h
//  Jade Warrior
//
//  Created by Markus Pfundstein on 3/23/12.
//  Copyright (c) 2012 Eagerheads. All rights reserved.
//

#ifndef Jade_Warrior_CCNumber_h
#define Jade_Warrior_CCNumber_h

#include <sstream>
#include "cocos2d.h"

namespace cocos2d_extensions {
    
    template <class _typeT = int>
    class CCNumber : public cocos2d::CCObject
    {
    public:
        CCNumber() 
        : cocos2d::CCObject(),
        m_type(0)
        {
            _typeT _validate;
            validateType(_validate);
        }
        
        static CCNumber* numberWithValue(_typeT value)
        {
            CCNumber<_typeT> *newNumber = new CCNumber<_typeT>;
            if (newNumber && newNumber->initWithValue(value))
            {
                newNumber->autorelease();
                return newNumber;
            }
            CC_SAFE_RELEASE_NULL(newNumber);
            return NULL;
        }
        
        static CCNumber* numberWithNumber(const CCNumber<_typeT> *rhs)
        {
            return numberWithValue(rhs->m_type);
        }
        
        inline bool initWithValue(_typeT value)
        {
            m_type = value;
            return true;
        }
        
        inline bool initWithNumber(const CCNumber<_typeT> *rhs)
        {
            m_type = rhs->m_type;
            return true;
        }
        
        inline cocos2d::CCString *stringValue() const {
            std::ostringstream buf("");
            buf << m_type;
            
            cocos2d::CCString *pStr = new cocos2d::CCString(buf.str().c_str());
            return static_cast<cocos2d::CCString*>(pStr->autorelease());
        }
        
        inline int compare(const CCNumber<_typeT>* rhs)
        {
            return memcmp((void*)&m_type, (void*)&rhs->m_type, sizeof(_typeT));
        }
        
        inline bool isEqualToNumber(const CCNumber<_typeT>* rhs)
        {
            return compare(rhs) == 0 ? 1 : 0;
        }
        
        CC_SYNTHESIZE_READONLY(_typeT, m_type, Value);
        
    protected:
        ~CCNumber()
        {
            
        }
        
    private:
        // types allowed by the template class. 
        void validateType(bool   &b) const {};
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
