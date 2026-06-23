 import pandas as pd
import matplotlib.pyplot as plt

data = {
    "Month": ["Jan", "Feb", "Mar", "Apr"],
    "Sales": [100, 150, 200, 180]
}

df = pd.DataFrame(data)

df.plot(x="Month", y="Sales", kind="line")

plt.title("Monthly Sales")
plt.xlabel("Month")
plt.ylabel("Sales")
plt.show()
