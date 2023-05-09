#pragma once
template <typename T>
int Compare1(const T& val1, const T& val2)
{
    if (val1 > val2)
        return 1;
    return 0;
}
class Compare

{

public:

    virtual int CompareElements(void* e1, void* e2) = 0;

};
   template<typename T>
   class CompareGreater : public Compare
   {
       int CompareElements(void* e1, void* e2)override final {
           if ((T*)e1 > (T*)e2)
               return true;
           return false;
       }
   };

template <typename T>
class CompareEqual :public Compare
{
    int CompareElements(void* e1, void* e2)override final {
        if ((T*)e1 ==(T*) e2)
            return true;
        return false;
    }
};

template <typename T>
class CompareNotEqual :public Compare
{
    int CompareElements(void* e1, void* e2)override final {
        if ((T*)e1 != (T*)e2)
            return true;
        return false;
    }
};