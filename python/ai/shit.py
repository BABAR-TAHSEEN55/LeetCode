import nltk
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from nltk.tag import pos_tag
from nltk.tokenize import word_tokenize

nltk.download("averaged_perceptron_tagger_eng")

nltk.download("punkt_tab")
nltk.download("stopwords")


def remove_stop_words(text: str):
    words = word_tokenize(text)
    stop_words = set(stopwords.words("english"))
    filtered_words = [word for word in words if word.lower() not in stop_words]
    return " ".join(filtered_words)


print(remove_stop_words("This is an example of Stop Words"))


def stemming_implementation(text: str):
    words = word_tokenize(text)
    stemmer = PorterStemmer()
    stemmed_words = [stemmer.stem(word) for word in words]
    print("Original Word : ", text)
    stemmed_filtered_words = " ".join(stemmed_words)
    print("now", stemmed_filtered_words)


print(stemming_implementation("Programming programmed"))


def Pos_tag_implementation(text: str):
    word = word_tokenize(text)
    pos = pos_tag(word)
    print(pos)


print(Pos_tag_implementation("super man is the best"))
