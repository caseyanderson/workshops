def helloWorld():
    """Greets the world upon creation"""
    print("HELLO WORLD!")


'''Function with parameter.'''

def happyBirthday(person):
    """formats a happy birthday message with the birthday person's name"""
    print("Happy Birthday to you!")
    print("Happy Birthday to you!")
    print("Happy Birthday, dear " + person + ".")
    print("Happy Birthday to you!")

def happyBirthday(person):
        """sings a happy birthday message with the birthday person's name"""
        for i in range(4):
            if i != 2:
                message = "Happy Birthday to you!"
                print message
            else:
                message = "Happy Birthday, dear " + person + "!"
                print message
