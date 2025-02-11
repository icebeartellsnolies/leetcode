import copy
def min_mutation(startGene,endGene,bank):
    # copy_st_gene = copy.deepcopy(startGene)
    for gene in range(len(bank)):
        bank[gene] = list(bank[gene])
    startGene = list(startGene)
    endGene = list(endGene)
    if startGene == endGene or endGene not in bank:
        return -1
    # bank.append(list(copy_st_gene))
    replacements = ['A','C','G','T']
    mutation = 0
    for nucleotide in range(8):
        valid = False
        if startGene[nucleotide] != endGene[nucleotide]:
            mutation += 1
            for replacement in replacements:
                startGene[nucleotide] = replacement            
                if startGene in bank:
                    valid = True
                    break
                if startGene == endGene:
                    return mutation
            if not valid and nucleotide != 0:
                return -1
    return mutation

# print(min_mutation("AACCGGTT","AACCGGTA",["AACCGGTA"]))
# print(min_mutation("AACCGGTT","AAACGGTA",["AACCGGTA","AACCGCTA","AAACGGTA"]))
# print(min_mutation("AACCTTGG","AATTCCGG",["AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"]))
print(min_mutation("AACCGGTT","AAACGGTA",["AACCGGTA","AACCGCTA","AAACGGTA"]))
