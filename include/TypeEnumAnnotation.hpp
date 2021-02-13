#ifndef TYPE_ENUM_ANNOTATION_HPP
#define TYPE_ENUM_ANNOTATION_HPP

#include "TypeEnum.hpp"

namespace fruit_issue_130
{

    /**
     * @brief For fruit Annotated injection
     *
     * @tparam TYPE annotation type enum.
     */
    template <TypeEnum TYPE>
    struct TypeEnumAnnotation
    {
    };

    using TypeEnumAnnotationA = TypeEnumAnnotation<TypeEnum::A>;
    using TypeEnumAnnotationB = TypeEnumAnnotation<TypeEnum::B>;
    using TypeEnumAnnotationC = TypeEnumAnnotation<TypeEnum::C>;

} // namespace fruit_issue_130

#endif // TYPE_ENUM_ANNOTATION_HPP
