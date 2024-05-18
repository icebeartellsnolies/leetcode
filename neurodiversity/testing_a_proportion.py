from scipy.stats import norm
# Number of homes with heat pumps installed in the survey
x = 8
# Total number of homes surveyed
n = 15
# Assumed proportion under the null hypothesis
p_null = 0.70
# Sample proportion
p_sample = x / n
# Standard error of the proportion
se = ((p_null * (1 - p_null)) / n) ** 0.5
# Calculate the z-score
z_score = (p_sample- p_null) / se
# Significance level
alpha = 0.10
# Find the critical value
critical_value = norm.ppf(1 - alpha / 2)
# Compare the z-score to the critical value
if abs(z_score) > critical_value:
    print(f"Reject the null hypothesis. There is enough evidence to suggest that the 
          true proportion is different from {p_null}.")
else:
    print(f"Fail to reject the null hypothesis. There is not enough evidence to suggest 
          that the true proportion is different from {p_null}.")