import random
for i in range(150):
    print(f"""insertProperty("Property {i+1}", {random.randint(1,5)}, {random.randint(1000,5000)}.0, {random.randint(180000,250000)}.0);""")