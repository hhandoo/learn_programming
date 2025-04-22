arr = ['I', 'love', 'oranges']

# count = ord('I') + ord('l') + ord('o') ---

count = 129836789



arr_str = I129836789love129836789oranges 
arr_str = Iloveoranges


arr_back = ['I', 'love', 'oranges']

# def say_hello():
#     print('Hello, World')

# for i in range(5):
#     say_hello()


# Your previous Plain Text content is preserved below:

# trips table ( trip details, driver_id,rider_id,start_time,end_time,city_id .. )
# driver_signup ( driver_id,signup_date ...)

# Find driver_ids who have not taken trip in first 7 days of their signup

# DriverSignup 
# D1 2025-01-01
# D2 2025-01-10
# D3 2025-04-20
# D4 2025-02-01

# Trips Starttime                 endTime
# T1 D1 2025-01-03 11:00:00
# T2 D1 2025-02-10 11:00:00
# T3 D2 2025-04-20 10:00:00
# T4 D2 2025-04-21 23:00:00


# Trips Starttime                 endTime
# T1 D1 2025-01-03
# T2 D1 2025-02-10
# T3 D2 2025-04-20
# T4 D2 2025-04-21


# Trips Starttime                 endTime
# T1 D1 2025-01-03
# T3 D2 2025-04-20
# T4 D2 2025-04-21



# with detect_minimum_start_time as (

#   select 
#   *,
#   date(min(Starttime)) over (partition by driver_id order by Starttime) as minstart
#   from 
#   Trips 

# )


# select

# d.driver_id


# detect_minimum_start_time as d
# left join
# from   trips as t
# on

# t.driver_id = d.driver_id

# where coalesce(DATE(t.Starttime), DATE('31-12-9999')) >= DATEADD(7, d.signup_date);


# py




