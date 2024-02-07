% objects.pl

% This file contains the objects that need to be delivered.
% The format of the objects is as follows:
% object(ID, Weight, PickupLocation, DropoffLocation, UrgencyLevel, DeliveryPersonID)

% The ID is a unique number for each object.
% The Weight is the weight of the object in kilograms.
% The PickupLocation is the location where the object is currently located.
% The DropoffLocation is the location where the object needs to be delivered.
% The UrgencyLevel is the urgency of the object, which can be low, medium, or high.
% The DeliveryPersonID is the ID of the person who is currently delivering the object.
%   If the object is not being delivered, the DeliveryPersonID is set to none.

object(1, 5, 'Library', 'Engineering Bld.', high, none).
% ID = 1, Weight = 5, PickupLocation = Library, DropoffLocation = Engineering Bld., UrgencyLevel = high, DeliveryPersonID = none
object(2, 15, 'Cafeteria', 'Admin Office', medium, none).
% ID = 2, Weight = 15, PickupLocation = Cafeteria, DropoffLocation = Admin Office, UrgencyLevel = medium, DeliveryPersonID = none
object(3, 2, 'Admin Office', 'Library', low, none).
% ID = 3, Weight = 2, PickupLocation = Admin Office, DropoffLocation = Library, UrgencyLevel = low, DeliveryPersonID = none
object(4, 4, 'Lecture Hall A', 'Cafeteria', high, none).
% ID = 4, Weight = 4, PickupLocation = Lecture Hall A, DropoffLocation = Cafeteria, UrgencyLevel = high, DeliveryPersonID = none
object(5, 6, 'Engineering Bld.', 'Institute Y', medium, 3).
% ID = 5, Weight = 6, PickupLocation = Engineering Bld., DropoffLocation = Institute Y, UrgencyLevel = medium, DeliveryPersonID = 3
