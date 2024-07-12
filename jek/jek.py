import matplotlib.pyplot as plt
import pandas as pd

# Example DataFrame
data = {
    'meal_type': ['breakfast', 'lunch', 'dinner'],
    'total_spent': [50.00, 100.00, 120.00]  # Example total amounts
}
df = pd.DataFrame(data)

# Plotting
plt.figure(figsize=(8, 6))
plt.bar(df['meal_type'], df['total_spent'], color='skyblue')
plt.xlabel('Meal Type')
plt.ylabel('Total Spending')
plt.title('Total Spending by Meal Type')
plt.grid(True)
plt.tight_layout()
# Display the plot

plt.show()

