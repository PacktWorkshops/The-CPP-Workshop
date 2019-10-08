#include <iostream>
#include <string>
using namespace std;
class ValuePrinter
{
  public:
    void Print(string msg, float f)
      {
         cout << msg << " : " << f << endl;
      }
    void Print(string msg, int i)
      {
         cout << msg << " : " << i << endl;
      }
    void Print(string msg, string s)
      {
         cout << msg << " : " << s << endl;
      }
};
class Article
 {
   public:
     Article(string title, int pageCount, int wordCount, string author)
       {
         m_title = title;
         m_pageCount = pageCount;
         m_wordCount = wordCount;
         m_author = author;
        }
     string m_title;
     int m_pageCount;
     int m_wordCount;
     string m_author;
     ValuePrinter valuePrinter;
     void ShowDetails()
       {
          valuePrinter.Print("Article Title", m_title);
          valuePrinter.Print("Article Page Count", m_pageCount);
          valuePrinter.Print("Article Word Count", m_wordCount);
          valuePrinter.Print("Article Author", m_author);
       }
};
int main()
{
  Article article("Celebrity Crushes!", 2, 200, "Papa Ratsea");
  article.ShowDetails();
  return 0;
}
