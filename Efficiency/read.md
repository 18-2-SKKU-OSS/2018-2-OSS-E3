현재 디렉토리는 고유명사에 대한 의견들을 모아서 만들어진 새로운 프로젝트를 위한 공간이다. 
고유명사란 :
어느 특정한 사물에 한정하여 그 이름을 나타내는 명사. 인명·지명·국호·상호·책명·사건명 따위가 이에 속함. 
대상의 유일성 여부가 고유 명사를 판별하는 절대 기준은 아님. 곧, `김철수'는 같은 이름을 가진 사람이 여러 명이어도 고유 명사이며,
`해', `달'은 세상에 하나밖에 없는 대상이어도 보통 명사임. 특별 명사. 홀로 이름씨. 홀이름씨. 특립 명사가 정의이다.
다음으로 현재 고유명사중에 분석이 가장 어려운 대상이면서 가장 높은 빈도로 등장하는 사람의 이름이 현실적으로 해결해야하는 문제라고 판단하였다.
현재 논의 되고 있는 방향은 2가지로 문장에서 알고리즘을 가지고 이름을 찾거나 데이터베이스에 저장하여 이를 비교하거나 두가지를 혼합하여 효율적인 알고리즘을
만들어내는 것을 목표로 하고 있다.


Named Entity Recognition (NER) is very important in many natural language processing tasks, especially information extraction. The problem of NE extraction in Thai is much more complicated than English because Thai language lacks orthography and boundary indicator between words. In this paper, we presented a research work in the field of NER with the emphasis on person name recognition (PNR) in Thai text. Our proposed method consists of 4 steps. First, text is tokenized into a set of words. Second, a part-of-name probability is computed for each word using Odds with Laplace smoothing and Logistic function. Third, name candidates are selected based on the likelihood probability. Finally, the end point of name is identified using a set of rules and a drop rate threshold. We then evaluated out method using 1,700 online news from the InterBEST 2009 corpus. The results show that the proposed method yields average precision, recall, f-measure and accuracy at 75.21%, 98.10%, 85.15%, and 81.05% respectively.
출처 : Thai person name recognition (PNR) using likelihood probability of tokenized words
