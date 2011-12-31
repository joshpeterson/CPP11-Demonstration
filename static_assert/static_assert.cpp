#include <ostream>
#include <type_traits>

class Factory
{
public:
	template<typename TypeToCreate>
	TypeToCreate* Create()
	{
		return new TypeToCreate();
	}

	template<typename TypeToCreate>
	TypeToCreate* CreateWithStaticAssert()
	{
		static_assert(std::is_class<TypeToCreate>::value, "Type argument TypeToCreate must be of class type to be created by Factory.");
		return new TypeToCreate();
	}
};

class Foo
{
};

void main()
{
	Factory factory;

	factory.Create<int>();
	factory.CreateWithStaticAssert<Foo>();
	factory.CreateWithStaticAssert<int>();
}