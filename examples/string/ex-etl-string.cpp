#include <iostream>
#include <string>
#include "../../etl/include/etl/string.h"

constexpr size_t MAX_STRING_LENGTH = 150;

int main()
{
    std::string question = "But how, my lord, shall we resist it now?";
    etl::string<MAX_STRING_LENGTH> answer = "It must be thought on. If it pass against us";
    int stack_variable = 36;

    auto ptr_to_stack_int = &stack_variable;
    auto ptr_to_std_data = (int const *)question.data();
    auto ptr_to_etl_data = (int const *)answer.data();
    auto ptr_to_etl_end = (int const *)answer.data_end();
    

    std::cout << "std::string question:\n\t" << question << '\n';
    std::cout << "etl::string answer:\n\t" << answer.c_str() << '\n';

    std::cout << "\nRight after initialization...\n";
    std::cout << "std::string question:\n\t" << question << '\n';
    std::cout << "etl::string answer:\n\t" << answer.c_str() << '\n';

    std::cout << '\n';
    std::cout << "std::string lives at " << ptr_to_std_data << " <- That's on the heap!\n";
    std::cout << "stack int   lives at " << ptr_to_stack_int << '\n';
    std::cout << "etl::string lives at " << ptr_to_etl_data << " <- That's on the stack!\n";
    std::cout << "etl::string stops at " << ptr_to_etl_end << '\n';

    std::cout << "\nAdding words...\n";

    question += "How did this offer seem received, my lord?";
    answer += ", We lose the better half of our possession";
    ptr_to_std_data = (int const *)question.data();
    ptr_to_etl_data = (int const *)answer.data();
    ptr_to_etl_end = (int const *)answer.data_end();

    std::cout << "std::string question:\n\t" << question << '\n';
    std::cout << "etl::string answer:\n\t" << answer.c_str() << '\n';

    std::cout << '\n';
    std::cout << "std::string lives at " << ptr_to_std_data << " <- Extra text forced a new heap allocation.\n";
    std::cout << "stack int   lives at " << ptr_to_stack_int << '\n';
    std::cout << "etl::string lives at " << ptr_to_etl_data << " <- Extra text lives in the same stack buffer\n";
    std::cout << "etl::string stops at " << ptr_to_etl_end << " <- Hey, that changed!\n";

    std::cout << "\nOverwriting text...\n";

    question = "What was the impediment that broke this off?";
    answer = "The French ambassador upon that instant craved audience";
    ptr_to_std_data = (int const *)question.data();
    ptr_to_etl_data = (int const *)answer.data();
    ptr_to_etl_end = (int const *)answer.data_end();
    std::cout << "std::string question:\n\t" << question << '\n';
    std::cout << "etl::string answer:\n\t" << answer.c_str() << '\n';

    std::cout << '\n';
    std::cout << "std::string lives at " << ptr_to_std_data << " <- Overwriting used the same heap allocation.\n";
    std::cout << "stack int   lives at " << ptr_to_stack_int << '\n';
    std::cout << "etl::string lives at " << ptr_to_etl_data << " <- New text lives in the same stack buffer\n";
    std::cout << "etl::string stops at " << ptr_to_etl_end << "\n";

    return (0);
}