// Для закрепления материала по std::tuple выполните следующие задания.
#include <string>
#include <tuple>
#include <cassert>
#include <iostream>

#define UNUSED(value) (void)(value)

// Задание 2. Реализуйте свой вариант std::tuple. Предыдущий пример должен
// валидно работать с custom_tuple и custom_tie.

template<typename... Args>
struct custom_tuple;

namespace tmp {
    template<size_t Is, typename Head, typename... Args>
    struct getter {
        static decltype(auto) get(const custom_tuple<Head, Args...>& t)
        {
            return getter<Is - 1, Args...>::get(t);
        }
    };

    template<typename Head, typename... Args>
    struct getter<0, Head, Args...> {
        static decltype(auto) get(const custom_tuple<Head, Args...>& t)
        {
            return t.m_head;
        }
    };
}

template<size_t Is, typename Head, typename... Args>
decltype(auto) custom_get(const custom_tuple<Head, Args...>& t)
{
    return tmp::getter<Is, Head, Args...>::get(t);
}

// "Рекурсивное наследование"
template<typename H, typename... Tail>
struct custom_tuple<H, Tail...> : public custom_tuple<Tail...>
{
    custom_tuple(const H &head, const Tail & ... tail)
        : custom_tuple<Tail...>(tail...)
        , m_head(head)
    {
    }

    template<typename... Args>
    custom_tuple(const custom_tuple<Args...>& other)
        : custom_tuple(other, std::make_index_sequence<sizeof...(Args)>{}) {}

    template<typename... Args>
    void operator=(const custom_tuple<Args...>& other)
    {
        assign_tuple(*this, other, std::make_index_sequence<sizeof...(Args)>{});
    }

    template<typename T1, typename T2, size_t ... Indices>
    void assign_tuple(T1& th, const T2& other, std::index_sequence<Indices...>)
    {
        // FIXME
        ((custom_get<Indices>(th) = custom_get<Indices>(other)), ...);
    }

    template<typename Tuple, size_t ... Indices>
    custom_tuple(Tuple&& other, std::index_sequence<Indices...>)
        : custom_tuple(custom_get<Indices>(std::forward<Tuple>(other))...) {}

    H m_head;
};

template<>
struct custom_tuple<> {};

// Создание custom_tuple
template<typename ...Args>
custom_tuple<Args...> make_custom_tuple(Args && ... args)
{
    return custom_tuple<Args...>(args...);
}

// функция tie для custom_tuple
template<typename ...Args>
custom_tuple<Args&...> custom_tie(Args&... args)
{
    return custom_tuple<Args&...>(args...);
}

auto getPerson()
{
    const std::string name = "Petia";
    const std::string secondName = "Ivanoff";
    const std::size_t age = 23;
    const std::string department = "Sale";
    return make_custom_tuple(name, secondName, age, department);
}

int main(int argc, char * argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    std::string name, secondName, department;
    std::size_t age;

    // FIXME
    custom_tie(name, secondName, age, department) = getPerson();

    assert(name == "Petia");
    assert(secondName == "Ivanoff");
    assert(age == 23);
    assert(department == "Sale");
    std::cout << "done!" << std::endl;
    return 0;
}
