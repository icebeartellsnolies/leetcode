import math
from scipy import stats
# Town voters
n1 = 200
x1 = 120
# County voters
n2 = 500
x2 = 240
# Calculate sample proportions
p_hat1 = x1 / n1
p_hat2 = x2 / n2
# Calculate pooled sample proportion and qc
p_c = (x1 + x2) / (n1 + n2)
qc = 1 - p_c
# Calculate the standard error of the difference between proportions
se = math.sqrt(p_c * qc * (1/n1 + 1/n2))
z_cal = (p_hat1 - p_hat2) / se
# Significance level
alpha = 0.05
# Two-sided test, so we need to compare against a critical z-value
critical_value = stats.norm.ppf(1 - alpha / 2)
# Compare the z-calculated value to the critical value
if z_cal > critical_value:
    print(f'Reject the null hypothesis. The proportion of town voters favoring the proposal is 
          higher than the proportion of county voters.')
else:
    print(f"Fail to reject the null hypothesis. There is not enough 
    evidence to suggest that the proportion of town voters favoring the 
    proposal is higher than the proportion of county voters.")