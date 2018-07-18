# Generate 3 easy question and 1 hard question per day
import os
import random

from question_num import easy_list, medium_list

def get_question(arr):
    """ Get question number
        arr: Input array with question numbers
    """
    size   = len(arr)
    r_num  = random.randint(0, size) 
    number = arr[r_num]
    return number


# Main
if __name__ == "__main__":

    today = []

    print("================================")
    print(" Easy   questions: "),
    for i in range(3):
        today.append(get_question(easy_list))
        print(today[-1]),
        
    print("")


    print(" Medium questions: "),
    for i in range(1):
        today.append(get_question(medium_list))
        print(today[-1]),

    print("")
    print("================================")

    #print(str(today))
