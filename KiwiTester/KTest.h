#pragma once

class KTest
{
public:
	typedef std::vector<KWordPair> AnswerType;
	struct TestResult
	{
		std::u16string q;
		AnswerType a;
		AnswerType r;
		std::vector<KWordPair> dr, da;
		std::vector<KResult> cands;
		float score;
		void writeResult(std::ostream& out) const;
	};
protected:
	std::vector<TestResult> wrongList;
	size_t totalCount;
	float totalScore;
public:
	KTest(const char* testSetFile, Kiwi* kw, size_t topN = 3);
	float getScore() const ;
	const std::vector<TestResult>& getWrongList() const { return wrongList; }
	size_t getTotalCount() const { return totalCount; }
};

