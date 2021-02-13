#include "OuterClass.hpp"

#include <utility>

namespace fruit_issue_130
{

    OuterClass::OuterClass(std::shared_ptr<IClass> iclass)
        : iclass_(std::move(iclass))
    {
    }

    void OuterClass::callSay()
    {
        this->iclass_->say();
    }

} // namespace fruit_issue_130
