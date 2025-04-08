def findAllRecipes(recipes,ingredients,supplies):
    supplies=set(supplies)
    ans=[]
    for rec in range(len(recipes)):
        count=0
        for i in (ingredients[rec]):
            if i in supplies:
                count+=1
        if count==len(ingredients[rec]):
            ans.append(recipes[rec])
            supplies.add(recipes[rec])
    return ans

# print(findAllRecipes(recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]))
# print(findAllRecipes(["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]))
print(findAllRecipes(recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]))
                