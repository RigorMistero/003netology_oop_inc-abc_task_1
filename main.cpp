#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Address
{
public:
    std::string City;
    std::string Street;
    int House;
    int Apartment;

    std::string get_output_address()
    {
        std::string addr{};
        addr.append(City + ", ");
        addr.append(Street + ", ");
        addr.append(std::to_string(House) + ", ");
        addr.append(std::to_string(Apartment)); //(City + ", " + Street + ", " + House + ", " + Apartment);
        return addr;
    }
};

int main(int argc, char** argv)
{
    //setlocale (LC_ALL, "rus");
    //SetConsoleOutputCP(1251);
    // std::ofstream ofile {"out.txt", std::ofstream::app};
    std::ifstream ifile("in.txt");
    std::ofstream ofile("out.txt");

      int number_of_addresses{};


    if (ifile.is_open())
        {
            ifile >> number_of_addresses;
            std::cout << number_of_addresses << std::endl;
            Address add[number_of_addresses];

        for (int i{}; i < number_of_addresses; i++)
           {
               ifile >> add[i].City;      //  std::cout << add.City;      std::cout << std::endl;
               ifile >> add[i].Street;    //  std::cout << add.Street;    std::cout << std::endl;
               ifile >> add[i].House;    //  std::cout << add.House;     std::cout << std::endl;
               ifile >> add[i].Apartment;// std::cout << add.Apartment; std::cout << std::endl;
               std::cout << add[i].get_output_address();
               std::cout << std::endl;

            }

         if (ofile.is_open())
    {
        ofile << number_of_addresses;

         for (int i{number_of_addresses - 1}; i >= 0; --i)
           {
                ofile << "\n";
                ofile << add[i].get_output_address();
        }

    }
    else
    {
        std::cout << "Couldn't open the file!";
    }
        }
    else
    {
        std::cout << "Couldn't open the file!";
    }




    ifile.close();
    ofile.close();
    return EXIT_SUCCESS;
}
