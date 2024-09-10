# Project Overview

The Dataline Bike Company Power BI Dashboard project aims to transition the company's reporting from manual PDF and Excel formats to an interactive and comprehensive Power BI dashboard. This dashboard is designed to meet the needs of two primary user groups: the CEO and managers, and the Marketing and Products team.

#### Key Objectives:
1. **Automate Reporting**: Replace manual reports with dynamic, real-time Power BI reports.
2. **Provide Insights**: Deliver valuable insights into sales performance, profit margins, and customer behavior.
3. **Enhance Decision-Making**: Support data-driven decision-making for different user groups within the company.

#### Data Sources:
- **Sales Orders (2017-2020)**: Four CSV files.
- **Additional Data**: One Excel file with multiple sheets.

#### Data Preparation:
- **Cleaning and Transformation**: Ensured data accuracy and consistency.
- **Date Formatting**: Converted order dates to a readable format and created a date dimension.
- **Data Model**: Developed a robust data model to support analyses.

#### Key Measures:
- **Revenue**: `Order quantity * Unit price`
- **Profit**: `Order quantity * (Unit price – Product Standard cost)`
- **Year-to-Date Measure**

#### Report Features:
1. **Executive Summary**:
   - Total Revenue, Profit, and Units Sold
   - Top Selling Categories and Countries
   - Revenue and Profit by Category, Subcategory, Country, and Quarter

2. **Revenue Analysis**:
   - Total Revenue and Profit Margin
   - Top Selling States and Cities
   - Revenue Trends by Year, Quarter, and Month
   - Order Quantity by Category

3. **Profit Analysis**:
   - Detailed Profit by Category and Subcategory
   - Profit Margin Trends
   - Top 5 Products by Profit

4. **Customer Analysis**:
   - Total Orders and Customers
   - Average Profit Per Customer
   - Most Ordered Product and Delivered Postal Code
   - Customer Distribution and Analysis Across Categories

#### Advanced Features:
- **Drilldowns**: Implemented drilldowns to allow users to explore data in greater detail.
- **Python Charts**: Utilized Python for advanced data visualizations, enhancing the analytical capabilities of the dashboard.

#### Design and Usability:
- **Professional Design**: Visually appealing and easy to read.
- **Interactivity**: Drillthroughs and drilldowns for detailed exploration.
- **User-Friendly**: Intuitive and accessible for end-users.

#### Conclusion:
This Power BI dashboard provides a comprehensive solution for the Dataline Bike Company, enabling efficient reporting and insightful analysis to support strategic decision-making.
