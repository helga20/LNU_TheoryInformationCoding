# Division by XOR

testData = [11, 9, 8, 7, 6, 1]
separateBy = [5, 3, 1, 0]
while True:
    if (len(testData) == 0) or (max(separateBy) > max(testData)):
        print("End")
        break
    print(testData)
    multiplicator = max(testData) - max(separateBy)
    minus = [a + multiplicator for a in separateBy]
    for i in minus:
        if i in testData:
            testData.remove(i)
        else:
            testData.append(i)
print(testData)
