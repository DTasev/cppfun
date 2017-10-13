from sklearn import tree

# The features of the data in order
# didnt make a difference if the doors are expressed as {3,5} or {0,1}
# Guarantee {Yes:1, No:0}
# No of Doors {3 doors:0, 5 doors: 1}
# New Tyres {Yes:1, No:0}
# features = [
# [0, 0, 1],
# [1, 0, 0],
# [0, 1, 0],
# [0, 0, 0],
# [1, 1, 0]
# ]

features = [
    [0, 3, 1],
    [1, 3, 0],
    [0, 5, 0],
    [0, 3, 0],
    [1, 5, 0]
]

# The labels of the data -> Buy {Yes:1, No:0}
labels = [1, 0, 1, 0, 1]

clf = tree.DecisionTreeClassifier()
clf.fit(features, labels)
