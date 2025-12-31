from nltk import PorterStemmer
from nltk import WordNetLemmatizer
import nltk

nltk.download("wordnet")
stemmer = PorterStemmer()
print(stemmer.stem("Programming"))
lemmatizer = WordNetLemmatizer()
print(lemmatizer.lemmatize("running", pos="v"))
print(lemmatizer.lemmatize("cars", pos="n"))
print(lemmatizer.lemmatize("better", pos="a"))

