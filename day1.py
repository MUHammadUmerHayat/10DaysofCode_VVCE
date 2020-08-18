if __name__ == '__main__':
    # Given
    nd = input().split()
    n = int(nd[0])
    d = int(nd[1])
    a = list(map(int, input().rstrip().split()))

    #Problem #1 Solution
    pos = []
    ans = []
    for j in range(0,n,1):
        pos.append((j+d)%n)
    for i in pos:
        ans.append(a[i])
    print(str(ans).replace('[','').replace(']','').replace(',',""))



    #Output LEFT ROTATE ARRAY

    # Given
    # d => Number of Rotation
    # n => List Length
    # a => Given List

    #Test Case 0
    #d = 4
    #n = 5
    #a = [1,2,3,4,5]

    #Result
    #a = 5 1 2 3 4
