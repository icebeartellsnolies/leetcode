class HashTableLinearProbing:
    def __init__(self, size=100):
        self.size = size
        self.keys = [None] * size
        self.values = [None] * size

    def _hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash_function(key)
        while self.keys[index] is not None:
            # Linearly probe to find the next available slot
            index = (index + 1) % self.size
        self.keys[index] = key
        self.values[index] = value

    def search(self, key):
        index = self._hash_function(key)
        original_index = index
        while self.keys[index] is not None:
            if self.keys[index] == key:
                return self.values[index]
            index = (index + 1) % self.size
            if index == original_index:
                # We've looped through all slots and haven't found the key
                break
        return None

    def delete(self, key):
        index = self._hash_function(key)
        original_index = index
        while self.keys[index] is not None:
            if self.keys[index] == key:
                self.keys[index] = None
                self.values[index] = None
                return
            index = (index + 1) % self.size
            if index == original_index:
                # We've looped through all slots and haven't found the key
                break

    def __str__(self):
        items = []
        for key, value in zip(self.keys, self.values):
            if key is not None:
                items.append(f"({key}: {value})")
        return "{" + ", ".join(items) + "}"


# Example usage:
hash_table = HashTableLinearProbing()
hash_table.insert('apple', 10)
hash_table.insert('banana', 20)
hash_table.insert('orange', 30)
print(hash_table)
print(hash_table.search('apple'))  # Output: 10
print(hash_table.search('banana'))  # Output: 20
print(hash_table.search('grape'))  # Output: None

hash_table.delete('banana')
print(hash_table)  # Output: {(apple: 10), (orange: 30)}
