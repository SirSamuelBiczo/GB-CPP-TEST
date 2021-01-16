#include <array>
#include <string>
#include <tuple>
#include <iostream>

using namespace std::string_literals;

 
template<typename T, bool DISPLAY = true>
std::string print(T param)
{
    (void)param;
    
    std::string type = "Unknow Type";
    if (DISPLAY)
        std::cout << type << std::endl;   
    return type;
 
}

template<bool DISPLAY = true>
std::string print(bool param)
{
    (void)param;
    std::string type = "bool";
    if (DISPLAY)
        std::cout << type << std::endl;
    return type;
} 

template<bool DISPLAY = true>
std::string print(double param)
{
    (void)param;
    std::string type = "double";
    if(DISPLAY)
        std::cout << type << std::endl;
    return type;
} 

template<bool DISPLAY = true>
std::string print(std::string param)
{
    (void)param;
    std::string type = "std::string";
    if(DISPLAY)
        std::cout << type << std::endl;
    return type;
} 
template<bool DISPLAY = true>
std::string print(unsigned long  param)
{
    (void)param;
    std::string type = "unsigned long";
    if(DISPLAY)
        std::cout << type << std::endl;
    return type;
} 


std::string print()
{
    std::string type = "Unknow Type";
     
    std::cout << type << std::endl;   
    return type;
}

static bool DISPLAY_STD_TUPLE = true;
 
template<typename T, typename ...Args>
void print(std::tuple<T, Args...> param)
{
    (void)param;
    
    if(DISPLAY_STD_TUPLE)
    {
        std::cout << "std::tuple<";
        DISPLAY_STD_TUPLE = false;
    }
    
    if (sizeof...(Args) <= 0)
    {
        std::cout << print<false>(std::get<0>(param)) << ">" << std::endl;
        DISPLAY_STD_TUPLE = true;
    }
    else 
    {
        std::cout << print<false>(std::get<0>(param)) << ", ";
        print<Args...>(std::tuple<Args...>{});
    }
}

template<typename T, std::size_t SIZE>
void print(std::array<T, SIZE> param)
{
    (void)param;
    std::cout << "std::array<int, " << SIZE << ">" << std::endl;
}
 

int main() {
    print(true);
    print(123ul);
    print(123.456);
    print("hello!"s);
    
    print(std::make_tuple(123ul, 456.0, "hello"s));
    print(std::to_array({ 0, 2, 1, 3 }));
    
    print();
}
