// Для закрепления материала по std::tuple выполните следующие задания.
#include <string>
#include <tuple>
#include <cassert>
#include <iostream>

#define UNUSED(value) (void)(value)

// Задание 2. Реализуйте свой вариант std::tuple. Предыдущий пример должен
// валидно работать с custom_tuple и custom_tie.
template<class ...Types>
struct custom_tuple
{
//    custom_tuple<Types...> &operator=(const custom_tuple<Types...> &other)
//    {
//        *this = other;
//        return *this;
//    }
};

// "Рекурсивное наследование"
template<class Ttail, class ...Thead>
struct custom_tuple<Ttail, Thead...> : public custom_tuple<Thead...>
{
    custom_tuple(const Ttail &tail, const Thead & ... head)
        : custom_tuple<Thead...>(head...)
        , m_tail(tail)
    {
    }

    Ttail m_tail;
};

// Создание custom_tuple
template<typename ...Types>
custom_tuple<Types...> create_tuple(Types && ... values)
{
    return custom_tuple<Types...>(values...);
}

// функция tie для custom_tuple
template<typename ...Types>
custom_tuple<Types&...> custom_tie(Types&... info)
{
    return custom_tuple<Types&...>(info...);
}

auto getPerson()
{
    const std::string name = "Petia";
    const std::string secondName = "Ivanoff";
    const std::size_t age = 23;
    const std::string department = "Sale";
    return create_tuple(name, secondName, age, department);
}

int main(int argc, char * argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    std::string name, secondName, department;
    std::size_t age;
    getPerson();

    // FIXME
//    custom_tie(name, secondName, age, department) = getPerson();

    assert(name == "Petia");
    assert(secondName == "Ivanoff");
    assert(age == 23);
    assert(department == "Sale");
    std::cout << "done!" << std::endl;
    return 0;
}
