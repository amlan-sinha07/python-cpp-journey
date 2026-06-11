def reverse_string(s):
    return s[::-1]

def is_palindrome(s):
    return s==s[::-1]

def word_count(s):
    return len(s.split())

def capitalize_words(s):
    return " ".join(w.capitalize() for w in s.split())