def stone_game(piles):
    alice_sum = 0
    bob_sum = 0
    left = 0
    right = len(piles)-1
    iteration = 0
    while left<right:
        if iteration%2 == 0:
            if piles[left] > piles[right]:
                alice_sum += piles[left]
                left += 1
            else:
                alice_sum += piles[right]
                right -= 1
        else:
            if piles[left] < piles[right]:
                bob_sum += piles[left]
                left += 1
            else:
                bob_sum += piles[right]
                right -= 1

    return True if alice_sum>bob_sum else False

print(stone_game([3,7,2,3]))