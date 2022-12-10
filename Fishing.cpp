#include <iostream>
#include <fstream>

bool fish_search(std::string);
void fish_write(std::string);

int main()
{
    int count = 0;
    std::string fish;
    std::cout << "Welcome to our pond!" << std::endl;
    std::cout << "How many times will you cast the bait?" << std::endl;
    std::cin >> count;
    for (int i = 0; i < count; i++)
    {
        std::cout << "What will you catch?" << std::endl;
        std::cin >> fish;
        if (fish_search(fish))
        {
            fish_write(fish);
        }
        else
        {
            std::cout << "This fish is not found here!" << std::endl;
        }
    }
}

bool fish_search(std::string fish)
{
    std::string temp;
    std::ifstream river("river.txt");
    while (!river.eof())
    {
        river >> temp;
        if (temp == fish)
        {
            return true;
            river.close();
        }
           
    }
    return false;
    river.close();
}

void fish_write(std::string fish)
{
    std::ofstream basket("basket.txt", std::ios::app);
    basket << fish;
    basket << std::endl;
    basket.close();
}