/**
 * Start of a driver file to test orgtree.cpp
 * CS 210 Fall 2022
 * @author Mitchell Shapiro <mshapiro6805@sdsu.edu>
 * @date Nov 2022
 */

/*
 * I the undersigned promise that the submitted assignment is my own work. While I was free to discuss ideas with others,
 * the work contained is my own. I recognize that should this not be the case, I will be subject to penalties as outlined in the course syllabus.
 *
 * Name: Winnie Thong
 * Red ID: 827059799
 */

#include "connectedcities.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * THIS DRIVER FILE IS ONLY A START!
 * IT IS CRITICAL THAT YOU ADD YOUR
 * OWN TEST CASES. MOST CASES ARE
 * HIDDEN ON GRADESCOPE.
 */

/**
 * Print whether the given test case passed or failed
 * @param didPass - The test condition (true to pass, false to fail)
 * @param message - Description of what is being tested
 */
void asserts(bool didPass, string message) {
    if (didPass) {
        cout << "Passed: " << message << endl;
    } else {
        cout << "FAILED: " << message << endl;
        // Halts execution, comment out to
        // continue testing other parts
		// If you do comment this out, ignore the
		// "All test cases passed!" printout
        exit(EXIT_FAILURE);
    }
}

//TODO
int main(int argc, char **argv) {
    
    // Begin Testing
    // A few sample testing code are provided below  
    
    /* Construct a graph for testing
        *    SD ---> DL <--------         
        *    ^                   |
        *    |                   |
        *    OD <--- JL <--------|--
        *                        |  |
        *    BV <---             |  |
        *    --->  LA ---> BU    |  |
        *          ^             |  |
        *          |             |  |
        *  SJ ---> SK ---> IV ---|  |
        *                           |
        *  <---------------         |
        *  SF ---> HT ---> NH ------|
        * */

    vector<string> cities_1 {"SD", "LA", "SK", "IV", "JL", "SF", 
                             "DL", "HT", "OD", "NH", "BV", "SJ", "BU"};

    vector<pair<string, string>> trainRoutes;

    trainRoutes.emplace_back("JL", "OD");
    trainRoutes.emplace_back("OD", "SD");
    trainRoutes.emplace_back("SD", "DL");
    trainRoutes.emplace_back("BV", "LA");
    trainRoutes.emplace_back("LA", "BV");
    trainRoutes.emplace_back("LA", "BU");
    trainRoutes.emplace_back("SK", "IV");
    trainRoutes.emplace_back("SK", "LA");
    trainRoutes.emplace_back("SJ", "SK");

    trainRoutes.emplace_back("IV", "DL");
    
    trainRoutes.emplace_back("SF", "HT");
    trainRoutes.emplace_back("HT", "NH");
    trainRoutes.emplace_back("NH", "SF");
    trainRoutes.emplace_back("NH", "JL");

    vector<CityNode> cities = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_1, trainRoutes);

    //cities returned from the above call are sorted according to 
    //the ascending order of the city names and 
    //the descending order of the size of reachableCities starting from those cities
    
    asserts(cities.at(0).getCity() == "HT", "First city should be HT");
    //Reachable cities from HT are [HT, NH, SF, JL, OD, SD, DL]
    asserts(cities.at(0).getReachableCities().size() == 7, "Train starting from city HT can reach 7 cities"); 
    
    asserts(cities.at(1).getCity() == "NH", "Second city should be NH");
    //Reachable cities from NH are [NH, SF, HT, JL, OD, SD, DL]
    asserts(cities.at(1).getReachableCities().size() == 7, "Train starting from city NH can reach 7 cities");
    
    asserts(cities.at(2).getCity() == "SF", "Third city should be SF");
    //Reachable cities from SF are [SF, HT, NH, JL, OD, SD, DL]
    asserts(cities.at(2).getReachableCities().size() == 7, "Train starting from city SF can reach 7 cities");
    
    asserts(cities.at(3).getCity() == "SJ", "Fourth city should be SJ");
    //Reachable cities from SJ are [SJ, SK, IV, DL, LA, BV, BU]
    asserts(cities.at(3).getReachableCities().size() == 7, "Train starting from city SJ can reach 7 cities");

    asserts(cities.at(4).getCity() == "SK", "Fifth city should be SK");
    //Reachable cities from SK are [SK, IV, DL, LA, BV, BU]
    asserts(cities.at(4).getReachableCities().size() == 6, "Train starting from city SK can reach 6 cities");
    
    asserts(cities.at(5).getCity() == "JL", "Sixth city should be JL");
    //Reachable cities from JL are [JL, OD, SD, DL]
    asserts(cities.at(5).getReachableCities().size() == 4, "Train starting from city JL can reach 4 cities");
    
    asserts(cities.at(6).getCity() == "BV", "Seventh city should be BV");
    //Reachable cities from BV are [BV, LA, BU]
    asserts(cities.at(6).getReachableCities().size() == 3, "Train starting from city BV can reach 3 cities");
        
    asserts(cities.at(7).getCity() == "LA", "Eighth city should be LA");
    //Reachable cities from LA are [LA, BV, BU]
    asserts(cities.at(7).getReachableCities().size() == 3, "Train starting from city LA can reach 3 cities");

    asserts(cities.at(8).getCity() == "OD", "Ninth city should be OD");
    //Reachable cities from OD are [OD, SD, DL]
    asserts(cities.at(8).getReachableCities().size() == 3, "Train starting from city OD can reach 3 cities");

    asserts(cities.at(11).getCity() == "BU", "Twelfth city should be BU");
    //Reachable cities from BU are [BU]
    asserts(cities.at(11).getReachableCities().size() == 1, "Train starting from city BU can reach 1 city");

    // IMPORTANT:
    // TODO: write your own testing code similar to above as part of the coding required for assignment 4


    //TEST CASES FROM GIVEN GRAPHS IN ASSIGNMENT
        //TEST CASE 2 GRAPH
    vector<string> cities_2{"IV","LA", "SD", "SF"};
    vector<pair<string,string>> trainRoutes2;
    vector<CityNode> cities2= ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_2, trainRoutes2);

    asserts(cities2.at(0).getCity() == "IV", "First city should be IV");
    asserts(cities2.at(0).getReachableCities().size() == 1, "Train starting from city IV can reach 1 city");

    asserts(cities2.at(1).getCity() == "LA", "Second city should be LA");
    asserts(cities2.at(1).getReachableCities().size() == 1, "Train starting from city LA can reach 1 city");

    asserts(cities2.at(2).getCity() == "SD", "Third city should be SD");
    asserts(cities2.at(2).getReachableCities().size() == 1, "Train starting from city SD can reach 1 city");

    asserts(cities2.at(3).getCity() == "SF", "Fourth city should be SF");
    asserts(cities2.at(3).getReachableCities().size() == 1, "Train starting from city SF can reach 1 city");


    //TEST CASE 3 GRAPH
    vector<string> cities_3{"LA", "SD", "SF", "IV", "SL", "OD","NH","HT","DL","SJ","SK","BU","BV"};
    vector<pair<string,string>> trainRoutes3;
    trainRoutes.emplace_back("JL", "OD");
    trainRoutes.emplace_back("NH", "JL");
    trainRoutes.emplace_back("OD", "SD");
    trainRoutes.emplace_back("HT", "NH");
    trainRoutes.emplace_back("SD", "DL");
    trainRoutes.emplace_back("NH", "SF");
    trainRoutes.emplace_back("SF", "HT");
    trainRoutes.emplace_back("SJ", "SK");
    trainRoutes.emplace_back("SK", "IV");
    trainRoutes.emplace_back("SK", "LA");
    trainRoutes.emplace_back("IV", "DL");
    trainRoutes.emplace_back("LA", "BU");
    trainRoutes.emplace_back("LA", "BV");
    trainRoutes.emplace_back("BV", "LA");


    vector<CityNode> cities3= ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_3, trainRoutes3);

    asserts(cities3.at(0).getCity() == "HT", "First city should be HT");
    asserts(cities3.at(0).getReachableCities().size() == 7, "Train starting from city HT can reach 7 cities");

    asserts(cities3.at(1).getCity() == "NH", "Second city should be NH");
    asserts(cities3.at(1).getReachableCities().size() == 7, "Train starting from city NH can reach 7 cities");

    asserts(cities3.at(2).getCity() == "SF", "Third city should be SF");
    asserts(cities3.at(2).getReachableCities().size() == 7, "Train starting from city SF can reach 7 cities");

    asserts(cities3.at(3).getCity() == "SJ", "Fourth city should be SJ");
    asserts(cities3.at(3).getReachableCities().size() == 7, "Train starting from city SJ can reach 7 cities");

    asserts(cities3.at(4).getCity() == "SK", "Fifth city should be SK");
    asserts(cities3.at(4).getReachableCities().size() == 6, "Train starting from city HT can reach 6 cities");

    asserts(cities3.at(5).getCity() == "SL", "Sixth city should be SL");
    asserts(cities3.at(5).getReachableCities().size() == 4, "Train starting from city HT can reach 4 cities");

    asserts(cities3.at(6).getCity() == "BV", "Seventh city should be BV");
    asserts(cities3.at(6).getReachableCities().size() == 3, "Train starting from city HT can reach 3 cities");

    asserts(cities3.at(7).getCity() == "LA", "Eighth city should be LA");
    asserts(cities3.at(7).getReachableCities().size() == 3, "Train starting from city HT can reach 3 cities");

    asserts(cities3.at(8).getCity() == "OD", "Ninth city should be OD");
    asserts(cities3.at(8).getReachableCities().size() == 3, "Train starting from city HT can reach 3 cities");

    asserts(cities3.at(9).getCity() == "IV", "Tenth city should be IV");
    asserts(cities3.at(9).getReachableCities().size() == 2, "Train starting from city HT can reach 2 cities");

    asserts(cities3.at(10).getCity() == "SD", "Eleventh city should be SD");
    asserts(cities3.at(10).getReachableCities().size() == 2, "Train starting from city HT can reach 2 cities");

    asserts(cities3.at(11).getCity() == "BU", "Twelfth city should be BU");
    asserts(cities3.at(11).getReachableCities().size() == 1, "Train starting from city HT can reach 1 cities");

    asserts(cities3.at(12).getCity() == "DL", "Thirteenth city should be DL");
    asserts(cities3.at(12).getReachableCities().size() == 1, "Train starting from city HT can reach 1 cities");






    // IMPORTANT: You should construct at least one different city graph similar to the one above
    //
    // Also make sure to construct graphs for testing the edge cases, 
    // such as empty graph (NO node), one node graph, two nodes graph, etc.

    cout << endl << "All test cases passed!" << endl;

    // Return EXIT_SUCCESS exit code
    exit(EXIT_SUCCESS);
}