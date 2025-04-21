import streamlit as st
import pandas as pd
import os
import matplotlib.pyplot as plt

# Set page title
st.title("Plant Monitoring Dashboard")

# List of sensor CSV files (update with your actual file names)
sensor_files = {
    "Temperature": "temperature.csv",
    "Humidity": "humidity.csv",
    "Moisture": "moisture.csv",
    "Water": "water.csv"
}

# Sidebar for sensor selection
sensor = st.sidebar.selectbox("Select Sensor", list(sensor_files.keys()))

# Load the selected sensor data
csv_file = sensor_files[sensor]
if os.path.exists(csv_file):
    df = pd.read_csv(csv_file)
    st.subheader(f"{sensor} Data")
    st.write(df.tail(10))  # Show last 10 rows

    # Plot last 10 values
    st.subheader(f"Last 10 {sensor} Values")
    if len(df) >= 10:
        data_to_plot = df.tail(10)
    else:
        data_to_plot = df
    # Assume the value column is the second column
    value_col = df.columns[1]
    st.line_chart(data_to_plot[value_col])
else:
    st.warning(f"No data found for {sensor} sensor.")


