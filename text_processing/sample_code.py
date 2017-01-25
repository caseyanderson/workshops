"""
ghostses generator

1. reads arbitrary text input
2. tokenizes text into words (followed by quick spacing fix)
3. assigns parts of speech
4. finds parts of speech we care about and colors said in original
5. everything else is invisible
6. outputs contents to a file

list of parts of speech tags used in nltk: nltk.help.upenn_tagset()

TODO:
make into class
"""

# reads a textfile
def readCorpus(filename):
    f = open(str(filename), 'r')
    x = f.read()
    return x


# tokenize to words and then run the parts of speech analysis, outputs a tuple
def wordTkzCrps(corpus):
    tokenized = nltk.word_tokenize(str(corpus))
    words = nltk.pos_tag(tokenized)
    return words


# splits a tuple list castes the output
def tupleSplitter(corpus):
    a,b = zip(*corpus)
    a = list(a)
    b = list(b)
    return a, b


# colorize every item that is a part of speech we care about
def colorizer(corpus, tagged, pos, dct ):
    step = 0
    size = len(tagged)
    colorCorpus = corpus
    x = dct[str(pos)]

    for i in x:
        step = 0
        for j in tagged:
            if i == j:
                colorCorpus[step] = """<span class='""" + str(pos) + """'>""" + corpus[step] + """</span>"""
                step = step + 1
            else:
                step = step + 1
    return colorCorpus

# everything not colorized by colorizer is whitespace
def whitespacer(corpus):
    output = []

    for i in corpus:
        if re.search("<[^<>]+>", i) is not None:
            output.append(i)
        else:
            output.append("""<span class='whitespace'>""" + i + """</span>""")
    return output

# opens the output file, checks to see if text in html tag needs a space before it, writes processed list to output
def outputer(filename, corpus):
    output = []

    o = open(filename, "w") # make a thing that adds which part of speech this is to the extension

    top ="""
    <html>
    <head>
    <link rel="stylesheet" href="styles.css" type="text/css"/>
    <link rel="stylesheet" href="print.css" media ="print" type="text/css"/>
    </head>
    <body>
    """

    for i in corpus:
        soup = BeautifulSoup(i, "html.parser")
        the_text = soup.get_text()
        if re.search('[^A-Za-z0-9]+', the_text) is not None:
            output.append(str(i))
        else:
            output.append(" " + str(i))

    middle = "".join(output) + "<br/>"

    bottom ="""
    </body>
    </html>
    """

    o.write(top + middle + bottom)
    o.close()
    return output
