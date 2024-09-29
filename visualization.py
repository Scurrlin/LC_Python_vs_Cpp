import pandas as pd
import matplotlib.pyplot as plt
import os

excel_file = 'Python&C++_raw_data.xlsx'

runtime_df = pd.read_excel(excel_file, sheet_name='Runtime')
memory_df = pd.read_excel(excel_file, sheet_name='Memory')

def prep_dataframe(df, avg_col, value_col):
    df.columns = df.iloc[1]
    df = df[2:]
    df.reset_index(drop=True, inplace=True)
    return df[[avg_col, 'Problem #', 'Language', value_col]].dropna(subset=[value_col])

runtime_by_problem = prep_dataframe(
    runtime_df,
    'Algo Avg Runtime (ms)',
    'Avg Runtime (ms)'
)

memory_by_problem = prep_dataframe(
    memory_df,
    'Algo Avg Memory (MB)',
    'Avg Memory (MB)'
)

python_color = '#3572A5'
cpp_color = '#F34B7D'

def create_bar_graph(df, x_col, y_col, title, xlabel, ylabel, output_filename, is_runtime=True):
    plt.figure(figsize=(14, 8))

    python_data = df[df['Language'] == 'Python']
    cpp_data = df[df['Language'] == 'C++']

    indices = range(len(python_data))
    bar_width = 0.4

    plt.bar([i - bar_width / 2 for i in indices], python_data[y_col], width=bar_width, label='Python', color=python_color)
    plt.bar([i + bar_width / 2 for i in indices], cpp_data[y_col], width=bar_width, label='C++', color=cpp_color)

    plt.xlabel(xlabel)
    plt.ylabel(ylabel)
    plt.title(title)
    plt.xticks(indices, python_data[x_col], rotation=45, ha="right")
    plt.legend()

    explanation = (
        "*Runtime reduced by a factor of 10 to not skew data visualization"
        if is_runtime
        else "*Memory reduced by a factor of 10 to not skew data visualization"
    )

    plt.figtext(0.5, -0.05, explanation, ha="center", fontsize=10)

    plt.tight_layout()
    
    plt.savefig(output_filename, bbox_inches='tight')
    plt.close()

create_bar_graph(
    runtime_by_problem,
    'Problem #',
    'Avg Runtime (ms)',
    'Average Runtime (ms) by LeetCode Problem #',
    'LeetCode Problem #',
    'Average Runtime (ms)',
    'runtime_by_problem.png',
    is_runtime=True
)

create_bar_graph(
    runtime_by_problem,
    'Algorithm',
    'Algo Avg Runtime (ms)',
    'Average Runtime (ms) by Algorithm',
    'Algorithm',
    'Average Runtime (ms)',
    'runtime_by_algorithm.png',
    is_runtime=True
)

create_bar_graph(
    memory_by_problem,
    'Problem #',
    'Avg Memory (MB)',
    'Average Memory (MB) by LeetCode Problem #',
    'LeetCode Problem #',
    'Average Memory (MB)',
    'memory_by_problem.png',
    is_runtime=False
)

create_bar_graph(
    memory_by_problem,
    'Algorithm',
    'Algo Avg Memory (MB)',
    'Average Memory (MB) by Algorithm',
    'Algorithm',
    'Average Memory (MB)',
    'memory_by_algorithm.png',
    is_runtime=False
)