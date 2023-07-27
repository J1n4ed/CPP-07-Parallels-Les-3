// Задание 1
// Сортировка выбором

// includes

#include <iostream>
#include <random>
#include <list>
#include <future>

// functions

void print_list(std::list<int>& list);

void select_sort(std::list<int>& list);

void find_smallest_pos(std::list<int>& list, std::list<int>::iterator start, std::promise<std::list<int>::iterator> prom);

int main(int argc, char** argv)
{
    // VARS

    std::list<int> list;

    // BODY

    // - generate list

    std::mt19937 rng;
    std::uniform_int_distribution<int> dist(10, 99); // rng numbers from 10 to 99

    // 100 elements list generation
    for (int i = 0; i < 100; ++i)
    {
        list.push_back(dist(rng));
    } // !for

    std::cout << "Initial list (unsorted) generated: \n\n";

    print_list(list);

    // - Sorting

    select_sort(list);

    std::cout << '\n' << '\n' << "Sorted list:\n\n";

    print_list(list);

    // EXIT

    std::cout << std::endl;
    system("pause");
    return EXIT_SUCCESS;

} // !main()

// functions

void print_list(std::list<int>& list)
{
    int i = 1;

    for (const auto& element : list)
    {
        std::cout << element;

        if (i % 10 == 0)
        {
            std::cout << '\n';
        } // !if
        else
        {
            std::cout << ' ';
        } // !else

        ++i;
    } // !for
    std::cout << '\n' << "List size: " << list.size();
} // print_list()

void find_smallest_pos(std::list<int>& list, std::list<int>::iterator start, std::promise<std::list<int>::iterator> prom)
{
    std::list<int>::iterator smallestPos = start;

    for (start; start != list.end(); ++start)
    {
        if (*start < *smallestPos)
            smallestPos = start;
    }
    prom.set_value(smallestPos);
} // ! find_smallest_pos()

void select_sort(std::list<int>& list)
{
    std::list<int>::iterator currentElement = list.begin();
    bool flag = true;   

    for (auto& element : list)
    {
        std::promise<std::list<int>::iterator> prom;
        std::future <std::list<int>::iterator> sP = prom.get_future();

        if (currentElement != list.end())
        {

            std::list<int>::iterator smallestPos;

            auto ft = std::async(find_smallest_pos, std::ref(list), currentElement, std::move(prom));

            smallestPos = sP.get();

            if (smallestPos != currentElement)
            {
                std::swap(*currentElement, *smallestPos);
            } // !if                

            ++currentElement;
        } // !if
    } // !for   
    return;
} // !select_sort()