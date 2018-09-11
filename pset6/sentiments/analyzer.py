import nltk


class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        # get positive list
        self.positives = []
        with open(positives, 'r') as lines:
            for line in lines:
                if not line.startswith(";") and line != "\n":
                    self.positives.append(line.strip("\n"))

        # get negative list
        self.negatives = []
        with open(negatives, 'r') as lines:
            for line in lines:
                if not line.startswith(";") and line != "\n":
                    self.negatives.append(line.strip("\n"))

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        # lowercase text
        text = text.lower()

        # init tokenizer and get tokens
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)

        # calculate score
        score = 0.0
        for word in tokens:
            if word in self.positives:
                score += 1.0
            elif word in self.negatives:
                score -= 1.0

        return score
