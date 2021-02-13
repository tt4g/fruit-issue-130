#include "IClassImpl.hpp"
#include <iostream>

namespace fruit_issue_130
{

    IClassImpl::IClassImpl(TypeEnum typeEnum)
        : typeEnum_(typeEnum)
    {
    }

    IClassImpl::~IClassImpl()
    {
    }

    void IClassImpl::say()
    {
        switch (this->typeEnum_)
        {
        case TypeEnum::A:
            std::cout << "I'm TypeEnum::A\n";
            break;

        case TypeEnum::B:
            std::cout << "I'm TypeEnum::B\n";
            break;

        case TypeEnum::C:
            std::cout << "I'm TypeEnum::C\n";
            break;
        }
    }

} // namespace fruit_issue_130
