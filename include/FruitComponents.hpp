#ifndef FRUIT_COMPONENTS_HPP
#define FRUIT_COMPONENTS_HPP

#include "IClass.hpp"
#include "IClassImpl.hpp"
#include "OuterClass.hpp"
#include "TypeEnum.hpp"
#include "TypeEnumAnnotation.hpp"

#include "fruit/fruit.h"

namespace fruit_issue_130
{
    using IClassComponentAnnotationA =
        fruit::Annotated<TypeEnumAnnotationA, IClass>;

    fruit::Component<IClassComponentAnnotationA> getIClassA();

    using IClassComponentAnnotationB =
        fruit::Annotated<TypeEnumAnnotationB, IClass>;

    fruit::Component<IClassComponentAnnotationB> getIClassB();

    using IClassComponentAnnotationC =
        fruit::Annotated<TypeEnumAnnotationC, IClass>;

    fruit::Component<IClassComponentAnnotationC> getIClassC();

////////////////////////////////////////////////////////////////////////////////

    using OuterClassComponentAnnotationA =
        fruit::Annotated<TypeEnumAnnotationA, OuterClass>;
    using OuterClassSharedPtrAnnotationA =
        fruit::Annotated<TypeEnumAnnotationA, std::shared_ptr<OuterClass>>;

    fruit::Component<
        fruit::Required<IClassComponentAnnotationA>,
        OuterClassComponentAnnotationA>
    getOuterClassA();

    using OuterClassComponentAnnotationB =
        fruit::Annotated<TypeEnumAnnotationB, OuterClass>;
    using OuterClassSharedPtrAnnotationB =
        fruit::Annotated<TypeEnumAnnotationB, std::shared_ptr<OuterClass>>;

    fruit::Component<
        fruit::Required<IClassComponentAnnotationB>,
        OuterClassComponentAnnotationB>
    getOuterClassB();

    using OuterClassComponentAnnotationC =
        fruit::Annotated<TypeEnumAnnotationC, OuterClass>;
    using OuterClassSharedPtrAnnotationC =
        fruit::Annotated<TypeEnumAnnotationC, std::shared_ptr<OuterClass>>;

    fruit::Component<
        fruit::Required<IClassComponentAnnotationC>,
        OuterClassComponentAnnotationC>
    getOuterClassC();
    ////////////////////////////////////////////////////////////////////////////////

    fruit::Component<
        OuterClassComponentAnnotationA,
        OuterClassComponentAnnotationB,
        OuterClassComponentAnnotationC>
    getRootComponent();

} // namespace fruit_issue_130

#endif // FRUIT_COMPONENTS_HPP
