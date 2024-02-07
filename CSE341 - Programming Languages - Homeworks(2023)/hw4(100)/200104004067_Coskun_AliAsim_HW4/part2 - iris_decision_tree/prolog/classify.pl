% classify.pl
% Decision tree implementation in Prolog

% Modified entry point for classification without the Class variable
classify(SepalLength, SepalWidth, PetalLength, PetalWidth) :-
    classify(SepalLength, SepalWidth, PetalLength, PetalWidth, Class),
    write(Class).

% Original entry point for classification with the Class variable
classify(SepalLength, SepalWidth, PetalLength, PetalWidth, Class) :-
    node1(PetalLength, SepalLength, SepalWidth, PetalWidth, Class).

% Node 1: Petal Length <= 2.60
node1(PetalLength, _, _, _, 'Iris-setosa') :-
    PetalLength =< 2.60, !.      % If Petal Length <= 2.60, then it is Iris-setosa
node1(PetalLength, SepalLength, SepalWidth, PetalWidth, Class) :-
    PetalLength > 2.60,          % If Petal Length > 2.60, then it is go to node 2
    node2(PetalWidth, PetalLength, SepalLength, SepalWidth, Class).

% Node 2: Petal Width <= 1.65
node2(PetalWidth, PetalLength, SepalLength, _, Class) :-
    PetalWidth =< 1.65,         % If Petal Width <= 1.65, then it is go to node 3
    node3(PetalLength, SepalLength, Class).
node2(PetalWidth, PetalLength, _, SepalWidth, Class) :-
    PetalWidth > 1.65,          % If Petal Width > 1.65, then it is go to node 5
    node5(PetalLength, SepalWidth, Class).

% Node 3: Petal Length <= 5.00
node3(PetalLength, _, 'Iris-versicolor') :-
    PetalLength =< 5.00, !.     % If Petal Length <= 5.00, then it is Iris-versicolor
node3(PetalLength, SepalLength, Class) :-
    PetalLength > 5.00,         % If Petal Length > 5.00, then it is go to node 4
    node4(SepalLength, Class).

% Node 4: Sepal Length <= 6.05
node4(SepalLength, 'Iris-versicolor') :-
    SepalLength =< 6.05, !.    % If Sepal Length <= 6.05, then it is Iris-versicolor
node4(SepalLength, 'Iris-virginica') :-
    SepalLength > 6.05.       % If Sepal Length > 6.05, then it is Iris-virginica

% Node 5: Petal Length <= 4.85
node5(PetalLength, SepalWidth, Class) :-
    PetalLength =< 4.85,      % If Petal Length <= 4.85, then it is go to node 6
    node6(SepalWidth, Class).
node5(PetalLength, _, 'Iris-virginica') :-
    PetalLength > 4.85.      % If Petal Length > 4.85, then it is Iris-virginica

% Node 6: Sepal Width <= 3.10
node6(SepalWidth, 'Iris-virginica') :-
    SepalWidth =< 3.10, !.   % If Sepal Width <= 3.10, then it is Iris-virginica
node6(SepalWidth, 'Iris-versicolor') :-
    SepalWidth > 3.10.      % If Sepal Width > 3.10, then it is Iris-versicolor

%----------- Test Cases -----------%

% Test 1:
% ̀Query: classify(4.6, 3.1, 1.5, 0.2).
% Expected Result: 'Iris-setosa'

% Test 2:
% ̀Query: classify(4.3, 3.0, 1.1, 0.1).
% Expected Result: 'Iris-setosa'

% Test 3:
% ̀Query: classify(5.6, 2.8, 4.9, 1.3).
% Expected result: 'Iris-versicolor'

% Test 4:
% ̀Query: classify(6.0, 2.2, 4.0, 1.0).
% Expected result: 'Iris-versicolor'

% Test 5:
% ̀Query: classify(6.3, 3.3, 6.0, 2.5).
% Expected result: 'Iris-virginica'

% Test 6:
% ̀Query: classify(6.7, 3.0, 5.2, 2.3).
% Expected result: 'Iris-virginica'
