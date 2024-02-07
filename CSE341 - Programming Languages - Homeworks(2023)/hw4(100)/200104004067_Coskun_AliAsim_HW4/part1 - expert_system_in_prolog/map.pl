% map.pl

% This file contains the map of the campus.
% The format is route(Place1, Place2, Distance).

route('Admin Office', 'Engineering Bld.', 3).
route('Engineering Bld.', 'Admin Office', 3).

route('Admin Office', 'Library', 1).
route('Library', 'Admin Office', 1).

route('Admin Office', 'Cafeteria', 4).
route('Cafeteria', 'Admin Office', 4).

route('Cafeteria', 'Library', 5).
route('Library', 'Cafeteria', 5).

route('Cafeteria', 'Social Sciences Bld.', 2).
route('Social Sciences Bld.', 'Cafeteria', 2).

route('Social Sciences Bld.', 'Institute X', 8).
route('Institute X', 'Social Sciences Bld.', 8).

route('Engineering Bld.', 'Lecture Hall A', 2).
route('Lecture Hall A', 'Engineering Bld.', 2).

route('Engineering Bld.', 'Library', 5).
route('Library', 'Engineering Bld.', 5).

route('Library', 'Institute Y', 3).
route('Institute Y', 'Library', 3).

route('Library', 'Social Sciences Bld.', 2).
route('Social Sciences Bld.', 'Library', 2).

route('Institute Y', 'Lecture Hall A', 3).
route('Lecture Hall A', 'Institute Y', 3).
