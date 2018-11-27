#include "stdafx.h"
#include "KForm.h"
#include "Utils.h"

using namespace std;

#ifdef _DEBUG
size_t KMorpheme::uid = 0;
#endif

KPOSTag makePOSTag(u16string tagStr)
{
	if (tagStr == KSTR("NNG")) return KPOSTag::NNG;
	if (tagStr == KSTR("NNP")) return KPOSTag::NNP;
	if (tagStr == KSTR("NNB")) return KPOSTag::NNB;
	if (tagStr == KSTR("NR")) return KPOSTag::NR;
	if (tagStr == KSTR("NP")) return KPOSTag::NP;
	if (tagStr == KSTR("VV")) return KPOSTag::VV;
	if (tagStr == KSTR("VA")) return KPOSTag::VA;
	if (tagStr == KSTR("VX")) return KPOSTag::VX;
	if (tagStr == KSTR("VCP")) return KPOSTag::VCP;
	if (tagStr == KSTR("VCN")) return KPOSTag::VCN;
	if (tagStr == KSTR("MM")) return KPOSTag::MM;
	if (tagStr == KSTR("MAG")) return KPOSTag::MAG;
	if (tagStr == KSTR("MAJ")) return KPOSTag::MAJ;
	if (tagStr == KSTR("IC")) return KPOSTag::IC;
	if (tagStr == KSTR("JKS")) return KPOSTag::JKS;
	if (tagStr == KSTR("JKC")) return KPOSTag::JKC;
	if (tagStr == KSTR("JKG")) return KPOSTag::JKG;
	if (tagStr == KSTR("JKO")) return KPOSTag::JKO;
	if (tagStr == KSTR("JKB")) return KPOSTag::JKB;
	if (tagStr == KSTR("JKV")) return KPOSTag::JKV;
	if (tagStr == KSTR("JKQ")) return KPOSTag::JKQ;
	if (tagStr == KSTR("JX")) return KPOSTag::JX;
	if (tagStr == KSTR("JC")) return KPOSTag::JC;
	if (tagStr == KSTR("EP")) return KPOSTag::EP;
	if (tagStr == KSTR("EF")) return KPOSTag::EF;
	if (tagStr == KSTR("EC")) return KPOSTag::EC;
	if (tagStr == KSTR("ETN")) return KPOSTag::ETN;
	if (tagStr == KSTR("ETM")) return KPOSTag::ETM;
	if (tagStr == KSTR("XPN")) return KPOSTag::XPN;
	if (tagStr == KSTR("XSN")) return KPOSTag::XSN;
	if (tagStr == KSTR("XSV")) return KPOSTag::XSV;
	if (tagStr == KSTR("XSA")) return KPOSTag::XSA;
	if (tagStr == KSTR("XR")) return KPOSTag::XR;
	if (tagStr == KSTR("SF")) return KPOSTag::SF;
	if (tagStr == KSTR("SP")) return KPOSTag::SP;
	if (tagStr == KSTR("SS")) return KPOSTag::SS;
	if (tagStr == KSTR("SE")) return KPOSTag::SE;
	if (tagStr == KSTR("SO")) return KPOSTag::SO;
	if (tagStr == KSTR("SW")) return KPOSTag::SW;
	if (tagStr == KSTR("NF")) return KPOSTag::UNKNOWN;
	if (tagStr == KSTR("NV")) return KPOSTag::UNKNOWN;
	if (tagStr == KSTR("NA")) return KPOSTag::UNKNOWN;
	if (tagStr == KSTR("SL")) return KPOSTag::SL;
	if (tagStr == KSTR("SH")) return KPOSTag::SH;
	if (tagStr == KSTR("SN")) return KPOSTag::SN;
	if (tagStr == KSTR("V")) return KPOSTag::V;
	if (tagStr == KSTR("A")) return KPOSTag::V;
	if (tagStr == KSTR("^")) return KPOSTag::UNKNOWN;
	//assert(0);
	return KPOSTag::MAX;
}

const char * tagToString(KPOSTag t)
{
	static const char* tags[] = 
	{
		"UN",
		"NNG", "NNP", "NNB", 
		"VV", "VA", 
		"MAG", 
		"NR", "NP",
		"VX",
		"MM", "MAJ",
		"IC",
		"XPN", "XSN", "XSV", "XSA", "XR",
		"VCP", "VCN",
		"SF", "SP", "SS", "SE", "SO", "SW",
		"SL", "SH", "SN",
		"JKS", "JKC", "JKG", "JKO", "JKB", "JKV", "JKQ", "JX", "JC",
		"EP", "EF", "EC", "ETN", "ETM",
		"V",
		"@"
	};
	assert(t < KPOSTag::MAX);
	return tags[(size_t)t];
}

const k_char * tagToStringW(KPOSTag t)
{
	static const k_char* tags[] =
	{
		KSTR("UN"),
		KSTR("NNG"), KSTR("NNP"), KSTR("NNB"),
		KSTR("VV"), KSTR("VA"),
		KSTR("MAG"),
		KSTR("NR"), KSTR("NP"),
		KSTR("VX"),
		KSTR("MM"), KSTR("MAJ"),
		KSTR("IC"),
		KSTR("XPN"), KSTR("XSN"), KSTR("XSV"), KSTR("XSA"), KSTR("XR"),
		KSTR("VCP"), KSTR("VCN"),
		KSTR("SF"), KSTR("SP"), KSTR("SS"), KSTR("SE"), KSTR("SO"), KSTR("SW"),
		KSTR("SL"), KSTR("SH"), KSTR("SN"),
		KSTR("JKS"), KSTR("JKC"), KSTR("JKG"), KSTR("JKO"), KSTR("JKB"), KSTR("JKV"), KSTR("JKQ"), KSTR("JX"), KSTR("JC"),
		KSTR("EP"), KSTR("EF"), KSTR("EC"), KSTR("ETN"), KSTR("ETM"),
		KSTR("V"),
		KSTR("@")
	};
	assert(t < KPOSTag::MAX);
	return tags[(size_t)t];
}

KForm::KForm(const k_char * _form)
{
	if (_form) form = _form;
}

void KForm::readFromBin(istream& is, const function<const KMorpheme*(size_t)>& mapper)
{
	form = readFromBinStream<k_string>(is);
	candidate.resize(readFromBinStream<uint32_t>(is));
	for (auto& c : candidate)
	{
		c = mapper(readFromBinStream<uint32_t>(is));
	}
}

void KForm::writeToBin(ostream& os, const function<size_t(const KMorpheme*)>& mapper) const
{
	writeToBinStream(os, form);
	writeToBinStream<uint32_t>(os, candidate.size());
	for (auto c : candidate)
	{
		writeToBinStream<uint32_t>(os, mapper(c));
	}
}

void KMorpheme::readFromBin(istream& is, const function<const KMorpheme*(size_t)>& mapper)
{
	kform = (const k_string*)readFromBinStream<uint32_t>(is);
	readFromBinStream(is, tag);
	readFromBinStream(is, vowel);
	readFromBinStream(is, polar);
	readFromBinStream(is, combineSocket);
	readFromBinStream(is, combined);
	readFromBinStream(is, userScore);

	size_t s = readFromBinStream<uint32_t>(is);
	if (s)
	{
		chunks = new vector<const KMorpheme*>(s);
		for (auto& c : *chunks)
		{
			c = mapper(readFromBinStream<uint32_t>(is));
		}
	}
}

void KMorpheme::writeToBin(ostream& os, const function<size_t(const KMorpheme*)>& mapper) const
{
	writeToBinStream<uint32_t>(os, (uint32_t)kform);
	writeToBinStream(os, tag);
	writeToBinStream(os, vowel);
	writeToBinStream(os, polar);
	writeToBinStream(os, combineSocket);
	writeToBinStream(os, combined);
	writeToBinStream(os, userScore);

	writeToBinStream<uint32_t>(os, chunks ? chunks->size() : 0);
	if(chunks) for (auto c : *chunks)
	{
		writeToBinStream<uint32_t>(os, mapper(c));
	}
}

std::ostream & operator<<(std::ostream & os, const KMorpheme & morph)
{
	os << utf16_to_utf8(morph.kform ? u16string{ morph.kform->begin(), morph.kform->end() } : u"_");
	os << '/';
	os << tagToString(morph.tag);
	if (morph.combineSocket) os << '+' << morph.combineSocket;
	return os;
}
