num_test_cases=int(input())
test_cases=[]
for i in range(num_test_cases):
    test_cases.append(int(input()))
for case in range(num_test_cases):
    to_compute=test_cases[case]
    summation=to_compute
    while to_compute!=1:
        to_compute=to_compute//2
        summation+=to_compute
    print(summation)
