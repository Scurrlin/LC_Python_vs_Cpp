import pandas as pd
import matplotlib.pyplot as plt

excel_file = 'Python&C++_raw_data.xlsx'

df_speed = pd.read_excel(excel_file, sheet_name='Speed')
df_memory = pd.read_excel(excel_file, sheet_name='Memory')
