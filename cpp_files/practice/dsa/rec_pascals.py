def generate_pascals_triangle(num_rows):
    triangle = []
    
    for i in range(num_rows):
        row = [1]  # The first element in each row is always 1
        
        # Generate the rest of the row
        for j in range(1, i):
            row.append(triangle[i-1][j-1] + triangle[i-1][j])
        
        if i > 0:
            row.append(1)  # The last element in each row is always 1
        
        triangle.append(row)
    
    return triangle

# Example: Generate Pascal's Triangle with 5 rows
num_rows = 5
result = generate_pascals_triangle(num_rows)

# Print the result
for row in result:
    print(row)