import random

dinner = ["spaghetti", "alfredo", "bbq sandwhiches", "goolash", "nachos", "burritos",
          "chili fries", "chili dogs", "hot dogs","pulled pork sammys", "orange chicken",
          "chicken fried rice","teriakya chicken","enchiladas", "tacos","chipotle bowls",
         "pork chops","mac n cheese","brautwarsts","ramen","soup","pizza",
          "grilled cheese and tomato soup","meatball subs","mashed pototates and gravy",
          "chicken parmesean","burgers","lasagna", "raviolli", "baked potatoes", "go out :)"]
lunch = ["chicken salad sammy", "peanut butter and jelly", "wraps", "turkey sammy",
         "pasta salad", "salad", "tuna and ritz", "soup", "grilled cheese", "go out :)"]
breakfast = ["protein bar", "parfaits", "smoothie", "cereal", "bagels and cream cheese",
             "oatmeal", "fruit", "go out :)"]
def main():
    print("MEAL PICKER 3000\n")
    mealChoice()

def mealChoice():
    meal_name = input("which meal is this for: ")
    if meal_name == "dinner" or meal_name == "d":
        meal_name = "dinner"
        meal = dinner
        choose(meal,meal_name)
    elif meal_name == "lunch" or meal_name == "l":
        meal_name = "lunch"
        meal = lunch
        choose(meal,meal_name)
    elif meal_name == "breakfast" or meal_name == "b":
        meal_name = "breakfast"
        meal = breakfast
        choose(meal,meal_name)
    else:
        print("not a choice, choose breakfast, lunch or dinner")
        mealChoice()
        again()

def choose(meal,meal_name):
    mealNum = int(input("how many {}s this week: ".format(meal_name)))
    mealCount = 0             
    count = 0
    for count, index in enumerate(meal):
        count += 1
    while mealCount < mealNum:
        num = random.randint(1, count-1)
        FOOD = meal[num]
        mealCount += 1
        print("\n" + str(mealCount) + ": " + str(FOOD))
        
    print()
    agains = input("Would you like to choose another: ")
    if agains == 'yes' or agains == 'y' or agains == 'Y' or agains == 'Yes':
        print()
        mealChoice()
    else:
        print()
        print()
        print("thank you andcome back soon :)")
main()
    
