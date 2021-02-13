#ifndef OUTER_CLASS_HPP
#define OUTER_CLASS_HPP

#include "IClass.hpp"

#include <memory>

namespace fruit_issue_130
{

    class OuterClass
    {
    private:
        std::shared_ptr<IClass> iclass_;

    public:
        OuterClass(std::shared_ptr<IClass> iclass);

        void callSay();
    };

} // namespace fruit_issue_130

#endif // OUTER_CLASS_HPP
