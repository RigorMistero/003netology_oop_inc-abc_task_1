#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Address
{
private:
    std::string City;
    std::string Street;
    int House;
    int Apartment;

    public:

    void set_City(std::string name_City) {City = name_City; } // setter
    void set_Street(std::string name_Street) {Street = name_Street;}
    void set_House(int num_House) { House = num_House;}
    void set_Apartment(int num_Apartment) {Apartment = num_Apartment;}

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

    std::ifstream ifile("in.txt");
    std::ofstream ofile("out.txt");

      int number_of_addresses{};

      std::string City_from_File{};
      std::string Street_from_File{};
      int House_from_File{};
      int Aps_from_File{};

    if (ifile.is_open())
        {
            ifile >> number_of_addresses;
            std::cout << number_of_addresses << std::endl;
            Address add[number_of_addresses];

        for (int i{}; i < number_of_addresses; i++)
           {
               ifile >> City_from_File;    add[i].set_City(City_from_File);      //  std::cout << add.City;      std::cout << std::endl;
               ifile >> Street_from_File;  add[i].set_Street(Street_from_File);    //  std::cout << add.Street;    std::cout << std::endl;
               ifile >> House_from_File;   add[i].set_House(House_from_File);    //  std::cout << add.House;     std::cout << std::endl;
               ifile >> Aps_from_File;     add[i].set_Apartment(Aps_from_File);// std::cout << add.Apartment; std::cout << std::endl;
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
