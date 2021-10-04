// Для закрепления материала по std::tuple выполните следующие задания.
#include <string>
#include <tuple>
#include <cassert>
#include <iostream>

#define UNUSED(value) (void)(value)

// Задание 1. Реализуйте свой вариант std::tie.
// Следующий код должен быть валидным:
template<typename ...Types>
std::tuple<Types&...> custom_tie(Types&... info)
{
    return std::tuple<Types&...>(info...);
}

auto getPerson()
{
    const std::string name = "Petia";
    const std::string secondName = "Ivanoff";
    const std::size_t age = 23;
    const std::string department = "Sale";
    return std::make_tuple(name, secondName, age, department);
}

int main(int argc, char * argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    std::string name, secondName, department;
    std::size_t age;
    getPerson();
    custom_tie(name, secondName, age, department) = getPerson();
    assert(name == "Petia");
    assert(secondName == "Ivanoff");
    assert(age == 23);
    assert(department == "Sale");
    std::cout << "done!" << std::endl;
    return 0;
}
