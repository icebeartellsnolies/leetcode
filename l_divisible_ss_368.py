def largest_divisible(parent):
    subset=[]
    true_listing=[]
    for i in range(len(parent)):
        if i+1<len(parent):
            j=i+1
            if parent[i]%parent[j]==0 or parent[j]%parent[i]==0:
                for k in range(len(subset)):
                    if (subset[k]%parent[j] or parent[j]%subset[k]) and (subset[k]%parent[i] or parent[i]%subset[k]):
                        true_listing.append(True)
                # all_true=False
                if False not in true_listing:
                    if parent[i] not in subset:
                        subset.append(parent[i])
                    if parent[j] not in subset:
                        subset.append(parent[j])
    return subset

print(largest_divisible([5,9,18,54,90,540,90,180,360,720]))