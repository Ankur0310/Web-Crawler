#include <iostream>
#include <fstream>
#include <regex>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::regex_constants;

set<string> getLinks(string html, int maxLinks);

set<string> getLinks(string html, int maxLinks)
{
  // Extracting all the links from the html file
  const regex url_re(R"!!(<\s*A\s+[^>]*href\s*=\s*"([^"]*)")!!", icase);
  set<string> res_1 = {
		sregex_token_iterator(html.begin(), html.end(), url_re, 1),
		sregex_token_iterator{}};

  regex exp(".*\\..*");

  set<string> links;
  for (string i : res_1)
  {
    // A string starting from "https://" is considered as a link
    // A link should not contain \<>{}
    if(regex_match(i, exp)){
      links.insert(i);
      if (links.size() >= maxLinks)
      {
        break;
      }
    }
  }

  return links;
}