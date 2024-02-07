% main.pl

% Load the necessary databases for the simulation
:- [personnel].    % Personnel details
:- [places].       % List of different places
:- [objects].      % Objects that need to be delivered
:- [map].          % Map database containing routes

% Predicate to check if a delivery personnel is available for an object delivery
% and calculate the shortest total time for the delivery route
available_person_and_time(ObjectID, PersonID, ShortestTotalTime, ShortestRoute) :-
    % Retrieve object and personnel details
    object(ObjectID, Weight, Pickup, Dropoff, _, none),
    personnel(PersonID, Capacity, WorkHours, none, CurrentLocation),
    % Check if the personnel can carry the object and has enough work hours for the delivery
    Capacity >= Weight,
    % Calculate all possible routes from the current location via pickup to dropoff
    all_possible_routes(CurrentLocation, Pickup, Dropoff, Routes),
    % Find the shortest route among all possible routes
    find_shortest_route(Routes, ShortestTotalTime, ShortestRoute),
    WorkHours >= ShortestTotalTime.

% Calculate all possible delivery routes and their respective times for an object
all_possible_routes(CurrentLocation, Pickup, Dropoff, Routes) :-
    % Generate a list of all routes with their total time
    findall(route_time(Route, TotalTime), 
            ((CurrentLocation = Pickup -> RouteToPickup = [CurrentLocation], TimeToPickup = 0; find_route(CurrentLocation, Pickup, [], RouteToPickup, TimeToPickup)),
             find_route(Pickup, Dropoff, RouteToPickup, Route, DeliveryTime),
             TotalTime is TimeToPickup + DeliveryTime),
            Routes).

% Identify the shortest route from a list of routes
find_shortest_route(Routes, ShortestTime, ShortestRoute) :-
    % Sort the routes based on total time in ascending order
    sort(2, @=<, Routes, SortedRoutes),
    % Select the first route which is the shortest
    SortedRoutes = [route_time(ShortestRoute, ShortestTime)|_].

% List all available personnel and their shortest delivery routes for a specific object
available_personnel_for_object(ObjectID) :-
    nl, % Insert a new line for readability
    % Check if the object is already in transit
    object(ObjectID, _, _, _, _, InTransitPerson),
    (   InTransitPerson \= none
    ->  % If the object is in transit, print the personnel currently delivering it
        format('The Object ~w is already in delivery by PersonID: ~w\n', [ObjectID, InTransitPerson])
    ;   % Else, find all available personnel for the object
        findall(_, 
               (available_person_and_time(ObjectID, PersonID, ShortestTotalTime, ShortestRoute),
                reverse(ShortestRoute, ReversedRoute), % Reverse the route for correct order
                format('There is available personnel For Object ~w: \nPersonID: ~w, \nShortest Route: ~w, \nShortest Total Time: ~w\n', [ObjectID, PersonID, ReversedRoute, ShortestTotalTime])),
               PersonnelList),
        % If no personnel are available, indicate this
        (   PersonnelList = []
        ->  format('There is no available personnel.\n')
        ;   true
        )
    ).

% Find a route from one location to another
find_route(Start, End, Visited, Route, Time) :-
    % Start the journey, accumulating the travel time and recording the route
    travel(Start, End, [Start|Visited], 0, Time, Route).

% Recursive helper rule for traveling from one place to another
travel(Place, Place, Visited, Time, Time, Visited).  % Base case: destination reached
travel(Current, Destination, Visited, AccumulatedTime, TotalTime, Route) :-
    % Find a direct route to the next place and ensure it hasn't been visited
    route(Current, Next, TravelTime),
    \+ member(Next, Visited), 
    NewTime is AccumulatedTime + TravelTime,
    % Continue traveling to the destination
    travel(Next, Destination, [Next|Visited], NewTime, TotalTime, Route).


% ---------------- TEST CASES ---------------- %

% Test Case 1: Insufficient Work Hours
% Scenario: For ObjectID = 4, "PersonID = 2" has no working hours.
% Expected Output: 
% PersonID: 1, Total Time: 15
?- available_personnel_for_object(4).

% Test Case 2: Object Already in Delivery
% Scenario: For ObjectID = 5, the object is already in delivery and the identity of the person delivering it.
% Expected Output:
% PersonID: 3, is already in delivery
?- available_personnel_for_object(5).

% Test Case 3: Insufficient Capacity
% Scenario: For ObjectID = 2, the weight of the object (15 kg) is more than the capacity of some personnel.
% Expected Output: 
% PersonID: 2, Total Time: 4
?- available_personnel_for_object(2).

% Test Case 4: All Personnel Available
% Scenario: For ObjectID = 3, both personnel(PersonID: 1 and PersonID:2) are available and have sufficient capacity.
% Expected Output: 
% PersonID: 1, Total Time: 2 
% PersonID: 2, Total Time: 5
?- available_personnel_for_object(3).

% Test Case 5: All Personnel Available
% Scenario: For ObjectID = 1, both personnel(PersonID: 1 and PersonID:2) are available and have sufficient capacity.
% Expected Output: 
% PersonID: 1, Total Time: 4
% PersonID: 2, Total Time: 8
?- available_personnel_for_object(1).

% Test Case 6: All Personnel Busy
% To do this, you need to update the object.pl and personnel.pl files.