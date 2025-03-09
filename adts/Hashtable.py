class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [None] * size

    def _hash_function(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash_function(key)
        if self.table[index] is None:
            self.table[index] = [(key, value)]
        else:
            # Handle collisions using chaining
            self.table[index].append((key, value))

    def search(self, key):
        index = self._hash_function(key)
        if self.table[index] is not None:
            for k, v in self.table[index]:
                if k == key:
                    return v
        return None

    def delete(self, key):
        index = self._hash_function(key)
        if self.table[index] is not None:
            for i, (k, v) in enumerate(self.table[index]):
                if k == key:
                    del self.table[index][i]
                    return

    def __str__(self):
        return str(self.table)


# Example usage:
hash_table = HashTable()
hash_table.insert('apple', 10)
hash_table.insert('banana', 20)
hash_table.insert('orange', 30)

print(hash_table.search('apple'))  # Output: 10
print(hash_table.search('banana'))  # Output: 20
print(hash_table.search('grape'))  # Output: None
print(hash_table) 
hash_table.delete('banana')
print(hash_table)  # Output: [[('apple', 10)], None, [('orange', 30)]]
