//
// Created by Tamar M on 2019-09-25.
//

#include "MapLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

MapLoader::MapLoader(string fileName)
{
    map = initialize(fileName);
}

Map* MapLoader::initialize(string fileName)
{
    ifstream infile;
    try {
        infile.open(fileName);
    } catch (const exception& e) {
        cout << "Invalid file." << endl;
    }

    Map *map = new Map();

    string line;
    bool countries = false;
    bool adjacencies = false;
    while (getline(infile, line))
    {
        if(line=="") {
            continue;
        }
        if(line=="[Countries]") {
            countries=true;
            continue;
        }
        if(line=="[Adjacencies]") {
            adjacencies=true;
            countries=false;
            continue;
        }
        if(countries||adjacencies) {
            string delimiter = ",";
            string first = line.substr(0, line.find(delimiter));
            string second = line.substr(line.find(delimiter) + 1, line.length());
            if(first==line) {
                cout << "Must delimit elements by a comma." << endl;
                return nullptr;
            }
            if (countries) {
                try {
                    Continent *continent = new Continent(second);
                    Country *country = new Country(first, continent);
                    map->addCountry(country);
                } catch (const exception& e) {
                    cout << endl << "Invalid country format" << endl;
                }
            }
            if (adjacencies) {
                try {
                    bool found = map->addAdjacency(map->findCountry(first), map->findCountry(second));
                    if(!found) {
                        cout << endl <<  "Country listed in Adjacency list not found." << endl;
                        return nullptr;
                    }
                } catch (const exception& e) {
                    cout << endl << "Invalid adjacency format" << endl;
                }
            }
            }
        }
    if(!adjacencies){
        cout << endl << "Invalid map. Map must be connected & each country should belong to only one continent!" << endl;
        return nullptr;
    }
    if (map->isValid()) {
        map->display();
        return map;
    } else {
        return nullptr;
    }

}

