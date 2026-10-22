import json
import tkinter as tk
import random
# with open('subject.json','r',encoding='utf-8') as f:
#     data = json.load(f)
# print(data)
# choice_1 = random.choice(list(data.values()))
def reuse_subject_button():
    with open('subject.json','r',encoding='utf-8') as f:
        data = json.load(f)
        choice_1 = random.choice(list(data.values()))
        return choice_1
root = tk.Tk()
root.title("Testing for random subject")
root.geometry("450x400")
subject_lable = tk.Label(root,text=reuse_subject_button())
subject_lable.pack()
def generate_button_work():
    subject_lable.config(text=reuse_subject_button())
subject_button = tk.Button(root,text="Generate",command=generate_button_work).pack()
# root.title("Student Registration Form")
# name_label = tk.Label(root,text= "Enter Name")
# name_label.pack(anchor="w",padx=10)
# name_textbox = tk.Entry(root)
# name_textbox.pack(anchor="w",padx=10)

# email_label = tk.Label(root,text= "Enter Email")
# email_label.pack(anchor="w")
# email_textbox = tk.Entry(root)
# email_textbox.pack(anchor="w")

# phno_label = tk.Label(root,text= "Enter Mobile N.O.")
# phno_label.pack(anchor="w")
# phno_textbox = tk.Entry(root)
# phno_textbox.pack(anchor="w")

# submit_button = tk.Button(root,text="Submit")
# submit_button.pack(anchor="w")



root.mainloop()