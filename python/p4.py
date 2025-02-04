# Try this in Jupyter

def count_words(file_path):
    try:
        with open(file_path, "r") as file:
            text=file.read()
            word= text.split()
            return len(word)
    except:
        return "File NOt Found"

check =count_words("../python/p5.py")
print(check)


