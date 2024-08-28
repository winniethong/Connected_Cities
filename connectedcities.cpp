/*
 * I the undersigned promise that the submitted assignment is my own work. While I was free to discuss ideas with others,
 * the work contained is my own. I recognize that should this not be the case, I will be subject to penalties as outlined in the course syllabus.
 *
 * Name: Winnie Thong
 * Red ID: 827059799
 */

#include "connectedcities.h"


/**
 * <p>
 * Part A 
 * ---------------------------------------------------------------------------------------
 * For each city in a city list, find the list of reachable cities starting from the city 
 * following the train routes, and sort the cities in the descending order based on the 
 * number of their reachable cities.  
 * 
 * Required specifications - 
 *
 * Given a list of cities, and a list of one-way train routes from one city to another:
 *
 * 1) Create a graph with each node in the graph as an instance of the CityNode class,
 *    the graph can use any STL collection by your choice.
 *
 * 2) Populate the direct routes information to each CityNode's directRoutedCities collection.
 *    This is like an adjacency list graph representation.
 *
 * 3) For each city node in the graph, use Depth First Search algorithm to find all reachable 
 *    cities starting from the city following the train routes and store those reachable cities to 
 *    the CityNode's reachableCities collection. 
 *
 *    IMPORTANT: The reachable cities must include the starting city itself.  
 *
 *    Note: The train route can go from the starting city and stop at several cities 
 *          before reaching the destination city, all cities including the starting city and 
 *          the destination city along the path would be counted as reachable cities from 
 *          the city where the train starts.
 *
 * 4) Sort the cities in the descending order based on the number of their reachable cities,
 *    so that after sorting, starting from the first city in the sorted order, the train can 
 *    reach the greatest number of destination cities following the given one-way routes. 
 *
 * 5) You must use a RECURSIVE algorithm to implement the Depth First Search part to find
 *    all reachable cities from a starting city given the train routes, using an iterative 
 *    approach would result in a 30% penalty to your assignment 4 grade.  
 *
 * 6) You may add necessary helper functions as needed. Follow the comments for hints.
 * 
 * Assumptions - 
 * 1) Each city is represented by a unique two-letter code like "SD", "LA", 
 *    "SF", "SJ", "NY", etc.
 * 2) Each one-way train route is represented by a pair of city codes; for example, 
 *    route {"SD", "LA"} means train can drive one-way from San Diego (SD) to 
 *    Los Angeles (LA). 
 *
 * <p>
 * Part B
 * ---------------------------------------------------------------------------------------
 * Show the upper bound of the time complexity of this function would be O(c^2 + c * r) 
 * where:
 * c is the number of cities
 * r is the number of direct routes between cities
 * 
 * ---------------------------------------------------------------------------------------
 * @param  cities  a list of cities with each city identified by a two letter code
 * @param  routes  pairs of one-way train routes with each one-way train route represented 
 *                 by a pair of city codes; for example, route {"SD", "LA"} means train 
 *                 can go one-way from San Diego (SD) to Los Angeles (LA).
 *
 *                 NOTE: examples of routes are { {"SD", "LA"},
 *                                                {"LA", "SJ"},
 *                                                {"SJ", "SF"}
 *                                              }   
 *                       refer to driver.cpp for more examples.  
 *
 * @return       A list of CityNode in the descending order based on the number of their 
 *               reachable cities following the train routes
 
* @see         
*/

void depthFirstSearchReachableCities( map<string, CityNode> cityGraph, // a collection of a STL collection type,
                                      string startingCity, vector<string> &reachableCities, // list of cities to add reachable cities along the recursive call
                                      set<string> &visitedCities) { // list of cities to track if a city is already visited along DFS search

    int directSize = cityGraph.at(startingCity).getDirectRoutedCities().size();
    // what would be the base condition? --> the startingCity is not already visited
    if (visitedCities.find(startingCity) == visitedCities.end()) {
        //insert the startingCity to both visitedCities and reachableCities
        visitedCities.insert(startingCity);
        reachableCities.push_back(startingCity);

        //recursive call for the startingCity's direct cities
        for (int i = 0; i < directSize; i++) {
            depthFirstSearchReachableCities(cityGraph, cityGraph.at(startingCity).getDirectRoutedCities().at(i),
                                            reachableCities, visitedCities);

        }
    }
}
//helper function for stable sort
bool alphSort(CityNode one, CityNode two ){

    //get ascending order for alphabetical sort
 return one.getCity()<two.getCity();
}

//helper function for stable sort
bool numSort(CityNode first, CityNode second){

    //get descending order of number of reachableCities
   return first.getReachableCities().size()>second.getReachableCities().size();

}

vector<CityNode> ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(vector<string> cities,
                                    vector<pair<string, string>> trainRoutes) {

  // Write your implementation here.

    //create map
    map<string, CityNode> cityGraph;
    int citiesSize= cities.size();

    //implement graph
    for(int i=0; i<citiesSize;i++){

        //temp CityNode city to hold the city names so that we can insert it into the map
        CityNode city(cities.at(i));
        cityGraph.insert(std::pair<string, CityNode> (cities[i],city));

    }

    //use trainRoutes to populate directRoutedCities with adjacency list
    int routeSize = trainRoutes.size();

    for(int i=0; i<routeSize;i++){
        string route =trainRoutes.at(i).first;
        string addRoute= trainRoutes.at(i).second;
        //add direct city of current cityNode
        cityGraph.at(route).addADirectRoutedCity(addRoute);

    }


  //implementing DFS function for each CityNode city
  //create new vector and set for parameters for the DFS function to sort the reachableCities using visitedCities
  vector <string> reachableCities;
  set <string> visitedCities;

  //cityG holds reference to cityGraph objects
  for(auto& cityG:cityGraph){

      string city_1 =cityG.second.getCity();
      //call DFS for each cityNode city
      depthFirstSearchReachableCities(cityGraph, city_1, reachableCities, visitedCities);

      //save reachable cities into current cityG node .setReachable
      cityGraph.at(city_1).setReachableCities(reachableCities);
      //clear to deallocate memory
      visitedCities.clear();
      reachableCities.clear();

  }

    //sort with stable_sort, created two helper functions : alphSort and numSort
    //sortedCities vector is the return value, so we put our sorted values in there
  vector<CityNode> sortedCities;

  //cityG is for reference to cityGraph objects
    for(auto& cityG : cityGraph){
        //only pulling out CityNode value from cityGraph into the sortedCities vector
        sortedCities.push_back(cityG.second);
    }

    //sort alphabetically first
    stable_sort(sortedCities.begin(), sortedCities.end(), alphSort);
    //sort numerically by num of reachableCities
    stable_sort(sortedCities.begin(), sortedCities.end(), numSort);

  return sortedCities; // final sorted vector
}



