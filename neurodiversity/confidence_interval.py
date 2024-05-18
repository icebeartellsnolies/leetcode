from scipy.stats import norm
import math
 # Given data
n = 500  # Total number of families owning 

x = 340  # Number of families that subscribe to HBO
confidence_level = 0.95  # 95% confidence level
# Step 1: Calculate the sample proportion
p_hat = x / n
# Step 2: Calculate the standard error
standard_error = math.sqrt((p_hat * (1 - p_hat)) / 
n)
# Step 3: Find the critical value (z-score) for the 

z = norm.ppf(1 - (1 - confidence_level) / 2)
margin_of_error = z * standard_error
# Step 5: Calculate the confidence interval
lower_bound = p_hat- margin_of_error
upper_bound = p_hat + margin_of_error
# Display the results
print(f"95% Confidence Interval: ({lower_bound:.4f}, 
{upper_bound:.4f})")
# 95% Confidence Interval: (0.6391, 0.7209)