#include "FruitComponents.hpp"

#include <memory>

namespace fruit_issue_130
{

    using IClassSharedPtrAnnotationA =
        fruit::Annotated<TypeEnumAnnotationA, std::shared_ptr<IClass>>;

    fruit::Component<IClassComponentAnnotationA> getIClassA()
    {
        using IClassImplAnnotationA =
            fruit::Annotated<TypeEnumAnnotationA, IClassImpl>;

        return fruit::createComponent()
            // NOTE: We need to tell fruit that the annotation implementation
            //  for `IClassComponentAnnotationA`
            //  (alias of `fruit::Annotated<TypeEnumAnnotationA, IClass>`)
            //  is `IClassImplAnnotationA`
            //  (alias of `fruit::Annotated<TypeEnumAnnotationA, IClassImpl>`)
            //  in `bind()` template parameter.
            .bind<IClassComponentAnnotationA, IClassImplAnnotationA>()
            // NOTE: Specify `IClassImplAnnotationA()` as the template parameter
            //  for `registerProvider()`.
            //  That is, `IClassImplAnnotationA` is the type of the return value
            //  and `()` is the argument list of the function.
            .registerProvider<IClassImplAnnotationA()>([]() {
                return IClassImpl(TypeEnum::A);
            });
    }

    using IClassSharedPtrAnnotationB =
        fruit::Annotated<TypeEnumAnnotationB, std::shared_ptr<IClass>>;

    fruit::Component<IClassComponentAnnotationB> getIClassB()
    {
        using IClassImplAnnotationB =
            fruit::Annotated<TypeEnumAnnotationB, IClassImpl>;

        return fruit::createComponent()
            .bind<IClassComponentAnnotationB, IClassImplAnnotationB>()
            .registerProvider<IClassImplAnnotationB()>([]() {
                return IClassImpl(TypeEnum::B);
            });
    }

    using IClassSharedPtrAnnotationC =
        fruit::Annotated<TypeEnumAnnotationC, std::shared_ptr<IClass>>;

    fruit::Component<IClassComponentAnnotationC> getIClassC()
    {
        using IClassImplAnnotationC =
            fruit::Annotated<TypeEnumAnnotationC, IClassImpl>;

        return fruit::createComponent()
            .bind<IClassComponentAnnotationC, IClassImplAnnotationC>()
            .registerProvider<IClassImplAnnotationC()>([]() {
                return IClassImpl(TypeEnum::C);
            });
    }

    fruit::Component<
        fruit::Required<IClassComponentAnnotationA>,
        OuterClassComponentAnnotationA>
    getOuterClassA()
    {
        return fruit::createComponent()
            .registerConstructor<
                OuterClassComponentAnnotationA(IClassSharedPtrAnnotationA)>();
    }

    fruit::Component<
        fruit::Required<IClassComponentAnnotationB>,
        OuterClassComponentAnnotationB>
    getOuterClassB()
    {
        return fruit::createComponent()
            .registerConstructor<
                OuterClassComponentAnnotationB(IClassSharedPtrAnnotationB)>();
    }

    fruit::Component<
        fruit::Required<IClassComponentAnnotationC>,
        OuterClassComponentAnnotationC>
    getOuterClassC()
    {
        return fruit::createComponent()
            .registerConstructor<
                OuterClassComponentAnnotationC(IClassSharedPtrAnnotationC)>();
    }

    fruit::Component<
        OuterClassComponentAnnotationA,
        OuterClassComponentAnnotationB,
        OuterClassComponentAnnotationC>
    getRootComponent()
    {
        return fruit::createComponent()
            .install(getIClassA)
            .install(getIClassB)
            .install(getIClassC)
            .install(getOuterClassA)
            .install(getOuterClassB)
            .install(getOuterClassC);
    }

} // namespace fruit_issue_130
