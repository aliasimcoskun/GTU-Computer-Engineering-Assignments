% personnel.pl

% This file contains the personnel information for the simulation.
% The format for each personnel is:
% personnel(ID, Capacity, WorkHours, CurrentDelivery, CurrentLocation).

% ID is the unique identifier for the personnel.
% Capacity is the maximum weight of packages that the personnel can carry.
% WorkHours is the number of hours that the personnel works per day.
% CurrentDelivery is the ID of the delivery that the personnel is currently
%   working on. If the personnel is not currently working on a delivery, then
%   this value is 'none'.
% CurrentLocation is the ID of the location that the personnel is currently
%   at. If the personnel is not currently at a location, then this value is
%   'none'.

personnel(1, 10, 16, none, 'Library').
% ID = 1, Capacity = 10, WorkHours = 16, CurrentDelivery = none, CurrentLocation = 'Library'
personnel(2, 15, 8, none, 'Cafeteria').
% ID = 2, Capacity = 15, WorkHours = 8, CurrentDelivery = none, CurrentLocation = 'Cafeteria'
personnel(3, 30, 20, 'Delivery1', 'Admin Office').
% ID = 3, Capacity = 30, WorkHours = 20, CurrentDelivery = 'Delivery1', CurrentLocation = 'Admin Office'
