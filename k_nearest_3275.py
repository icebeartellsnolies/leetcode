
def resultsArray(queries, k):
    answer = [0]*len(queries)
    max_ans = 0
    for i in range(len(queries)):
        ans = abs(queries[i][0]) + abs(queries[i][1])
        max_ans = max(ans,max_ans)
        if i+1 < k:
            answer[i] = -1
        else:
            answer[i] = max_ans

    return answer

print(resultsArray([[1,2],[3,4],[2,3],[-3,0]], 2))
# print(resultsArray([[5,5],[4,4],[3,3]],1))
print(resultsArray([[7,7],[-9,4]],2))