first_number = int (input('Введи число 1: '))
second_number = int (input('Введи число 2: '))

math_operation = int (input('Операція? \n 1 Додавання \n 2 Відмання \n 3 Ділення \n 4 Множення \n'))

def calculate(number1, number2, operator):
    r = 0
    if operator < 1 or operator > 4:
        print('unknown operator')
    if operator == 1:
        r = number1 + number2
        p = 'Додавання'
        t = p
    if operator == 2:
        r = number1 - number2
        l = 'Віднімання'
        t = l
    if operator == 3:
        r = float(number1 / number2)
        m = 'Ділення'
        t = m
    if operator == 4:
        r = number1 * number2
        n = 'Множення'
        t = n
    return r
print ('Результат = ', calculate(first_number, second_number, math_operation))
