# build_tree.py
# Python script to build and visualize the decision tree

import pandas as pd
from sklearn.tree import DecisionTreeClassifier, plot_tree
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn import metrics
from sklearn.tree import export_text

# Load the IRIS dataset
df = pd.read_csv('python/iris/iris.data', header=None)
df.columns = ["sepal length", "sepal width", "petal length", "petal width", "class"]
X = df[["sepal length", "sepal width", "petal length", "petal width"]]
y = df["class"]

# Split into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=1)

# Create and train the decision tree classifier
clf = DecisionTreeClassifier()
clf = clf.fit(X_train, y_train)

# Make predictions on the test set and print the accuracy value
y_pred = clf.predict(X_test)
print("Accuracy:", metrics.accuracy_score(y_test, y_pred))

# Visualize the decision tree
plt.figure(figsize=(10,10))
plot_tree(clf, filled=True, class_names=clf.classes_)
plt.show()

# Print the decision tree rules
tree_rules = export_text(clf, feature_names=list(X.columns))
print(tree_rules)