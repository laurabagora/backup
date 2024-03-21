# Custom messages that show up at the end of user input 
custom_message_A = "<< Awesome Job! >>"
custom_message_B = "<< Great Work! >>"
custom_message_C = "<< Good but there is room for improvement! >>"
custom_message_D = "<< Is this the best you can do? >>"
custom_message_F = "<< Need more practice. >>"

# Being able to print the assignment name like Midterm 1 or Final
def assessment(assessment_name):
    print(assessment_name + ":")

# Setting the basic weight, score, and shift so we can calculate off of it
    weight = int(input("Weight (0-100)? "))
    score_earned = int(input("Score earned? "))
    shift_bool = int(input("Were scores shifted (1=yes, 2=no)? "))  
    total_points = score_earned

# Giving the points earned so we can calculate for the shift amount
    if (shift_bool == 1):
        shift_amount = int(input("Shift amount? " ))
        total_points += shift_amount

# This is to make sure that the score stops at 100
    if (total_points > 100):
        total_points = 100

    print("Total points = " + str(total_points) + " / 100")

    weighted_score = round(total_points / 100 * weight, 1)
    print("Weighted score = " + str(weighted_score) + " / " + str(weight) + "\n")

    return weighted_score

# This will calculate the homework and the amount of assignments with it
def homework():
    print("Homework:")
    
    weight = int(input("Weight (0-100)? "))
    num_assignments = int(input("Number of assignments? "))
    score = 0
    max = 0
    for assignment in range(0, num_assignments):
        score += int(input("Assignment " + str(assignment + 1) + " score? "))
        max += int(input("Assignment " + str(assignment + 1) + " max? "))
    if score > max:
        score = max

    sections_attended = int(input("How many sections did you attend? "))
    section_points = sections_attended * 3
    if section_points > 34:
        section_points = 34

# This will calculating attendance
    print("Section points = " + str(section_points) + " / 34")

    total_points = score + section_points
    total_max = max + 34
    print("Total points = " + str(total_points) + " / " + str(total_max))

    weighted_score = round(total_points / total_max * weight, 1)
    print("Weighted score = " + str(weighted_score) + " / " + str(weight) + "\n")

    return weighted_score

# This will calculate the quiz and daily homework scores
def extra(extra_name):
    
    print(extra_name + ':')
    weight = int(input("Weight (0-100)? "))
    score_earned = int(input("Total points earned? "))
    points_possible = int(input("Total points possible? "))
    total_points = score_earned
    
    if (total_points > 100):
        total_points = 100

    print("Total points = " + str(total_points) + ' / ' + str(points_possible))

    weighted_score = round(score_earned / points_possible * weight, 1)
    print("Weighted score = " + str(weighted_score) + " / " + str(weight) + "\n")

    return weighted_score


# This is the parameter for the percentage you get with a letter grade and custom message
def letter_grade(percent):
    if percent > 90:
        grade = "A"     
        custom_message = custom_message_A
    elif percent > 80:
        grade = "B"
        custom_message = custom_message_B
    elif percent > 70:
        grade = "C"
        custom_message = custom_message_C
    elif percent > 60:
        grade = "D"
        custom_message = custom_message_D
    else:
        grade = "F"
        custom_message = custom_message_F

    print("Your grade will be at least: " + grade)
    print(custom_message)

# This will calculate the total percentage earned so the letter grade can show
def Calculate_Percentage():
    print("This program reads exam/homework scores")
    print("and reports your overall course grade.")
    print()
    overall_percentage = round(assessment("Midterm 1") + assessment("Midterm 2") + assessment("Final") + homework(),1) + round(extra("Quizzes") + extra("Daily Homework"), 1)
    print("Overall percentage = " + str(overall_percentage))
    letter_grade(overall_percentage)

Calculate_Percentage()
