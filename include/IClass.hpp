#ifndef ICLASS_HPP
#define ICLASS_HPP

namespace fruit_issue_130
{

    class IClass
    {
    public:
        virtual ~IClass();

        virtual void say() = 0;
    };

} // namespace fruit_issue_130

#endif // ICLASS_HPP
