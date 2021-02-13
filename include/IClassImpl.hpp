#ifndef ICLASS_IMPL_HPP
#define ICLASS_IMPL_HPP

#include "IClass.hpp"
#include "TypeEnum.hpp"

namespace fruit_issue_130
{

    class IClassImpl : public IClass
    {
    public:
        IClassImpl(TypeEnum typeEnum);

        virtual ~IClassImpl();

        virtual void say();

    private:
        TypeEnum typeEnum_;
    };

} // namespace fruit_issue_130

#endif // ICLASS_IMPL_HPP
