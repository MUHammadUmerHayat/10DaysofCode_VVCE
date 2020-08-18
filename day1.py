if __name__ == '__main__':
    # Given
    n = 5
    d = 4
    a = [1,2,3,4,5]

    #Problem #1 Solution
    ans = ""

    # Rotating-Left-Array
    for i in range(0,d,1):
        temp = a[0]
        for j in range(0,n-1,1):
            a[j] = a[j+1]
        a[n-1] = temp

    # Converting List to String
    for i in a:
        ans = ans + str(i) + " "
    print(ans)

    #Output LEFT ROTATE ARRAY

    # given
    # d => Number of Rotation
    # n => List Length
    # a => Given List

    # ans = 5 1 2 3 4
