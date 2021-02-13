#include "OuterClass.hpp"
#include "FruitComponents.hpp"
#include "TypeEnum.hpp"

#include <memory>

namespace
{

    using namespace fruit_issue_130;

    using InjectorType = fruit::Injector<
        OuterClassComponentAnnotationA,
        OuterClassComponentAnnotationB,
        OuterClassComponentAnnotationC>;

    InjectorType createInjector()
    {
        return InjectorType(getRootComponent);
    }

    std::shared_ptr<OuterClass> getOuterClass(
        InjectorType &injector,
        TypeEnum typeEnum)
    {
        switch (typeEnum)
        {
        case TypeEnum::A:
            return injector.get<OuterClassSharedPtrAnnotationA>();

        case TypeEnum::B:
            return injector.get<OuterClassSharedPtrAnnotationB>();

        case TypeEnum::C:
            return injector.get<OuterClassSharedPtrAnnotationC>();

        default:
            throw std::exception("Unsupported TypeEnum.");
        }
    }

} // namespace

int main(int, char **)
{
    auto injector = createInjector();

    auto outerClassA = getOuterClass(injector, TypeEnum::A);
    auto outerClassB = getOuterClass(injector, TypeEnum::B);
    auto outerClassC = getOuterClass(injector, TypeEnum::C);

    outerClassA->callSay();
    outerClassB->callSay();
    outerClassC->callSay();

    return EXIT_SUCCESS;
}
