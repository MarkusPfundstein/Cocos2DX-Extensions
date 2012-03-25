//
//  CCValue.h
//  CCX
//
//  Created by Markus Pfundstein on 3/25/12.
//  Copyright (c) 2012 Eagerheads. All rights reserved.
//

#ifndef cocos2dx_extensions_CCValue_h
#define cocos2dx_extensions_CCValue_h

#include "cocos2d.h"

namespace cocos2d_extensions {
    
    template <class _typeT>
    class CCValue : public cocos2d::CCObject
    {
    public:
        CCValue() 
        : cocos2d::CCObject()
        {
            memset(&m_type, 0, sizeof(_typeT));
        }
        
        static CCValue* valueWithValue(const _typeT &value)
        {
            CCValue<_typeT> *newValue = new CCValue<_typeT>;
            if (newValue && newValue->initWithValue(value))
            {
                newValue->autorelease();
                return newValue;
            }
            CC_SAFE_RELEASE_NULL(newValue);
            return NULL;
        }
        
        static CCValue* valueWithValue(const CCValue<_typeT> *rhs)
        {
            return valueWithValue(rhs->getValue());
        }
        
        inline bool initWithValue(const _typeT &value)
        {
            memcpy(&m_type, &value, sizeof(_typeT));
            return true;
        }
        
        inline int compare(const CCValue<_typeT> *rhs)
        {
            return memcmp((void*)&m_type, (void*)&rhs->m_type, sizeof(_typeT));
        }
        
        inline bool isEqualToValue(const CCValue<_typeT> *rhs)
        {
            return compare(rhs) == 0 ? 1 : 0;
        }
        
        inline bool isEqualToValue(const CCValue<_typeT> *rhs, int fpCmp(const _typeT &t1, const _typeT &t2))
        {
            return fpCmp(m_type, rhs->m_type) == 0 ? 1 : 0;
        }
        
        CC_SYNTHESIZE_READONLY_PASS_BY_REF(_typeT, m_type, Value);
        
    protected:
        ~CCValue()
        {
            
        }
    private:
        
    };
    
    
}   // namespace

#endif
