import tkinter as tk
import random

secret_number = random.randint(1, 100)

def check():
    user_number = int(entry.get())

    if user_number < secret_number:
        label.config(text="Більше")
    elif user_number > secret_number:
        label.config(text="Менше")
    else:
        label.config(text="Вгадав!")

window = tk.Tk()
window.title("Вгадай число")
window.geometry("250x150")

entry = tk.Entry(window)
entry.pack()

button = tk.Button(window, text="OK", command=check)
button.pack()

label = tk.Label(window, text="")
label.pack()

window.mainloop()
